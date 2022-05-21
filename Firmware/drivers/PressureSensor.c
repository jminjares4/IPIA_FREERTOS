/**
 * @file PressureSensor.c
 * @author Jesus Minjares @see https://github.com/jminjares4 
 * @author Erick A. Baca  @see https://github.com/eabaca2419 
 * @brief Pressure Sensor driver source code 
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "inc/PressureSensor.h"

void Pressure_Sensor_init(void){
    adcAvg = 0; //set global value to 0
    /*Initialize ADC Driver*/
    ADC_init();
    ADC_Params adcParams;
    /*Set parameter at default*/
    ADC_Params_init(&adcParams);
    /*Open ADC Instance*/
    adcHandle = ADC_open(PRESSURE_SENSOR, &adcParams);
    /*Check for error*/
    if(adcHandle == NULL){
      while(1);
    }
    return;
}

void Pressure_Sensor_Timer_init(Timer_Handle *pressureSensorHandle, Timer_Params *pressureSensorParam,uint16_t hertz){
    /*Initialize Timer Driver*/
    Timer_init();
    /*Set parameter to default*/
    Timer_Params_init(pressureSensorParam);
    /*Set timer @ hertz with a 6 lvl priority */
    pressureSensorParam->period = hertz;
    pressureSensorParam->periodUnits = Timer_PERIOD_HZ;
    pressureSensorParam->timerCallback = pressureSensorCallback;
    pressureSensorParam->timerMode = Timer_CONTINUOUS_CALLBACK;
    return;
}

void Pressure_Sensor_start(Timer_Handle *pressureSensorHandle, Timer_Params *pressureSensorParam){
    /*Open Pressure Sensor Timer Instance*/
    *pressureSensorHandle = Timer_open(PRESSURE_SENSOR_TIMER, pressureSensorParam);
    /*Check for error*/
    if(*pressureSensorHandle == NULL){
       while(1);
    }
    /*Start timer*/
    if(Timer_start(*pressureSensorHandle) ==Timer_STATUS_ERROR){
       while(1);
    }
    return;
}

void pressureSensorCallback(Timer_Handle handle){
    adcAvg = 0; //reset value @ 0
    static int i = 0; //static variable
    /*Iterate over PRESSURE_SENSOR_SAMPLE */
    for(i = 0; i < PRESSURE_SENSOR_SAMPLE; i++){
      ADC_convert(adcHandle, &adcBuf[i]); //convert
      adcAvg += adcBuf[i]; //store into average
    }
    sem_post(&pressureSensorSem); //post semaphore
}
