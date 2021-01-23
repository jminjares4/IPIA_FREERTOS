/*
 *  ======== gpsTimer.h ========
 *   Authors:   Jesus Minjares, MS in Computer Engineering
 *              Erick A. Baca, MS in Computer Engineering
 */
#ifndef GPSTIMER_H_
#define GPSTIMER_H_
#include <ti/drivers/Timer.h>
#include "sim33eau.h"
#include "ti_drivers_config.h"
/*Global Timer Handle*/
Timer_Handle gpsTimerHandle;
/*Initialize GPS TIMER Driver*/
void GPS_TIMER_init();
/*Start GPS TIMER*/
void GPS_TIMER_start();
/*Timer Callback*/
void timerCallback(Timer_Handle handle);
#endif /* GPSTIMER_H_ */
