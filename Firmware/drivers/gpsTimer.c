/*
 *  ======== gpsTimer.c ========
 *   Authors:   Jesus Minjares, Bachelor of Science in Electrical Engineering
 *              Erick A. Baca, Bachelor of Science in Electrical Engineering
 */
#include "inc/gpsTimer.h"
/*Initialize GPS Timer Driver*/
void GPS_TIMER_init(){
    /*Initialize Timer Dirver*/
    Timer_init();
    Timer_Params timerParams;
    /*Set to default*/
    Timer_Params_init(&timerParams);
    /*Set timer at 10hz-> 100ms intervals*/
    timerParams.period = 10;
    timerParams.periodUnits = Timer_PERIOD_HZ;
    timerParams.timerCallback = timerCallback;
    timerParams.timerMode = Timer_CONTINUOUS_CALLBACK;
    /*Open timer instance*/
    gpsTimerHandle = Timer_open(TIMERA0, &timerParams);
    if(gpsTimerHandle == NULL){
       while(1){}
    }
    return;
}
/*Start GPS TIMER Driver*/
void GPS_TIMER_start(){
    /*Start timer*/
    int32_t status = Timer_start(gpsTimerHandle);
    /*Check for STATUS ERROR*/
    if(status == Timer_STATUS_ERROR){
        while(1){}
    }
    return;
}
/*GPS Timer Callback*/
void timerCallback(Timer_Handle handle){
    /*every 100ms*/
    sysTime.milli+= 100; //incrmement every TA2 interval
    if(sysTime.milli > 999){ sysTime.second++; sysTime.milli = 0;  }
    if(sysTime.second > 59){ sysTime.minute++; sysTime.second = 0; }
    if(sysTime.minute > 59){ sysTime.hour++;   sysTime.minute = 0; }
    if(sysTime.hour > 23){   sysTime.hour = 0;}
}
