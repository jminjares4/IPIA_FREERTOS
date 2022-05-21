/**
 * @file gpsTimer.h
 * @author Jesus Minjares @see https://github.com/jminjares4 
 * @author Erick A. Baca  @see https://github.com/eabaca2419 
 * @brief GPS Timer driver source code 
 * @version 0.1
 * @date 2022-05-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef GPSTIMER_H_
#define GPSTIMER_H_
#include <ti/drivers/Timer.h>
#include "sim33eau.h"
#include "ti_drivers_config.h"

Timer_Handle gpsTimerHandle; /*!< GPS Timer Handle */

/******************************************************************
 * \brief GPS Timer Initialization
 * 
 * Detailed description starts here 
 * @param void		No argument
 * @return None
 *******************************************************************/
void GPS_TIMER_init(void);

/******************************************************************
 * \brief GPS Timer start
 * 
 * Detailed description starts here 
 * @param void  
 * @return None
 *******************************************************************/
void GPS_TIMER_start(void);

/******************************************************************
 * \brief Timer callback
 * 
 * Detailed description starts here 
 * @param handle    Timer handle  
 * @return None
 *******************************************************************/
void timerCallback(Timer_Handle handle);

#endif /* GPSTIMER_H_ */
