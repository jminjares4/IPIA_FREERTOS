/**
 * @file SG90.c
 * @author Jesus Minjares @see https://github.com/jminjares4 
 * @author Erick A. Baca  @see https://github.com/eabaca2419 
 * @brief SG90 driver source code 
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "inc/SG90.h"

void SG90_init(uint_least8_t index, PWM_Handle *motorHandle){
    /*Initialize PWM Driver*/
    PWM_init();
    PWM_Params pwmParams;
    /*Set PWM Parameter to default*/
    PWM_Params_init(&pwmParams);
    /*Set Parameter for Sg90 @ 5%->10% @ 50hz*/
    pwmParams.dutyUnits   = PWM_DUTY_COUNTS;        //Period in timer counts
    pwmParams.dutyValue   = SERVO_MIN;                   //PWM initial duty
    pwmParams.idleLevel   = PWM_IDLE_LOW;           //PWM start in low
    pwmParams.periodUnits = PWM_PERIOD_COUNTS;      //Duty in timer counts
    pwmParams.periodValue = 240000;
    /*Open PWM Instance*/
    *motorHandle = PWM_open(index, &pwmParams);    //This function opens a given PWM instance
    if(*motorHandle == NULL){   //Check for error
        while(1);
    }
    return;
}

void SG90_setDuty(PWM_Handle motor, uint32_t duty){
    /*Set motor duty cycle*/
    if(PWM_setDuty(motor, duty) == PWM_STATUS_ERROR){    //Set duty and check for status error
       PWM_setDuty(motor, duty);                        //If error reset duty
    }
}

void SG90_start(PWM_Handle motorHandle){
    /*Start SG90 Motor*/
    PWM_start(motorHandle);
}
