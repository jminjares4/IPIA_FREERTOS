/**
 * @file ipia.c
 * @author Jesus Minjares @see https://github.com/jminjares4 
 * @author Erick A. Baca  @see https://github.com/eabaca2419 
 * @brief IPIA main
 * @version 0.1
 * @date 2022-05-20 
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* For usleep() */
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/Timer.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/PWM.h>
#include "GPS.h"
#include <ti/drivers/ADC.h>
#include <semaphore.h>

#include "inc/bluetooth.h"
#include "inc/sim33eau.h"
#include "inc/gpsTimer.h"
#include "inc/SG90.h"
#include "inc/PressureSensor.h"
/* Driver configuration */
#include "ti_drivers_config.h"

#define SOLAR_SAMPLE 5          /*!< Number of samples for solar tracker */

/******************************************************************
 * \brief Pressure Sensor Thread
 * 
 * Detailed description starts here 
 * @param arg0		pressure sensor argument
 * @return None
 *******************************************************************/
void *pressureSensorThread(void *arg0){
    /*Timer Variables*/
    Timer_Handle timerHandle;
    Timer_Params timerParam;
    /*Initialize Pressure Sensor Driver*/
    Pressure_Sensor_init();
    /*Initialize Pressure Timer @ 80 hertz*/
    Pressure_Sensor_Timer_init(&timerHandle, &timerParam, 80); //set callback at 80 hz
    /*initialize bluetooth driver*/
    bluetooth_init();
    /*set semaphore*/
    int status = sem_init(&pressureSensorSem, 0, 0);
    if (status != 0) {
        while(1);
    }
    /*Start Timer*/
    Pressure_Sensor_start(&timerHandle, &timerParam);
    while(1){
        sem_wait(&pressureSensorSem); //wait for flag
        /*send via bluetooth*/
        bluetooth_send(&coordinate, &sysTime, adcAvg/PRESSURE_SENSOR_SAMPLE);
        usleep(10000); //sleep 10us
    }
}

/******************************************************************
 * \brief Solar Tracker Thread
 * 
 * Detailed description starts here 
 * @param arg0		solar tracker argument
 * @return None
 *******************************************************************/
void *solarTrackerThread(void *arg0){
    /*Variables*/
    uint16_t x = 0, y = 0, adcData, data = 0;

    /*ADC Variable & PWM*/
    ADC_Handle adcHandle;
    ADC_Params adcParams;
    PWM_Handle X_Handle, Y_Handle;
    /*Initialize Drivers*/
    ADC_init();

    /*Initialize ADC Parameter*/
    ADC_Params_init(&adcParams);
    /*Open SOLAR PANEL Instance*/
    adcHandle = ADC_open(SOLAR_PANEL, &adcParams);
    /*Check for ERROR*/
    if(adcHandle == NULL){
       while(1);
    }

    /*Initialize SG90 MOTOR @ SERVO MIN*/
    SG90_init(X_AXIS, &X_Handle);
    SG90_init(Y_AXIS, &Y_Handle);

    /*Set y_duty and x_duty @ SERVO_MIN*/
    uint32_t y_duty = SERVO_MIN, x_duty = SERVO_MIN;

    /*Start SG90 MOTOR for X and Y Axis*/
    SG90_start(X_Handle);
    SG90_start(Y_Handle);
    while(1){
       /*Set axis duty*/
       SG90_setDuty(Y_Handle, y_duty);
       SG90_setDuty(X_Handle, x_duty);
       y_duty += 180;   //Increase Y_axis duty by 1%
       if(y_duty > SERVO_MAX){   //Check if the maximum value for Y_axis duty have being reached
           y_duty = SERVO_MIN;   //Reset duty to its initial value
           x_duty += 1000;  //Increase X_axis duty by 5.5%
           if (x_duty > SERVO_MAX){     //Check if the maximum value for Y_axis duty have being reached
               /* Set the motors in the optimal position*/
               y_duty  = y;
               x_duty = x;
               /*Set the duty for both axis*/
               SG90_setDuty(Y_Handle, y_duty);
               SG90_setDuty(X_Handle, x_duty);
               y_duty += 180;   //Increase Y_axis du
               sleep(120);      //Set two minute delay
               /*Re-initialize the Solar Tracker*/
               data = 0;
               y_duty = x_duty = SERVO_MIN;
           }
       }
       int i = 0;
       uint32_t avg = 0;
       for( ; i < SOLAR_SAMPLE; i++){
           ADC_convert(adcHandle, &adcData);   //Function to perform an ADC conversion
           avg += adcData; //store into avg
       }
       adcData = (uint16_t)(avg/SOLAR_SAMPLE); //get the average

       usleep(100000); //100us
       if(data < adcData){     //Compare new ADC data to previous data.
           data = adcData;     //Save the new ADC data
           /*Save the coordinates for the new ADC Data */
           x = x_duty;
           y = y_duty;
       }
   }
}

/******************************************************************
 * \brief GPS Thread
 * 
 * Detailed description starts here 
 * @param arg0		GPS argument
 * @return None
 *******************************************************************/
void *gpsThread(void *arg0){
   /*Initalize GPS drivers*/
    GPS_init();
    GPS_read(60); //read 60 lines
    GPS_stop(); //toggle GPS EN pin

    /*Initialize system timer with gps inputs*/
    GPS_TIMER_init();
    GPS_TIMER_start(); //start timer
    while(1){
//        Display_printf(displayHandle,0,0,"%c[2J%c[H",27,27);
//        Display_printf(displayHandle,0,0,"UTC_TIME: %02u:%02u:%02u:%02u\n", sysTime.hour, sysTime.minute, sysTime.second, sysTime.milli);
        usleep(50000);
    };
}
