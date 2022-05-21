/**
 * @file SG90.h
 * @author Jesus Minjares @see https://github.com/jminjares4 
 * @author Erick A. Baca  @see https://github.com/eabaca2419 
 * @brief SG90 Driver
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SG90_H_
#define SG90_H_
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <ti/drivers/PWM.h>
#include "ti_drivers_config.h"
/*SERVO LIMITS*/
#define SERVO_MIN 12000         /*!< Servo Min Value */
#define SERVO_MAX 24000         /*!< Servo Max Value */
/*Initialize S90 Driver*/

/******************************************************************
 * \brief SG90 Initialize
 * 
 * Detailed description starts here 
 * @param index         SG90 index value    
 * @param motorHandle   PWM_handle reference
 * @return None
 *******************************************************************/
void SG90_init(uint_least8_t index, PWM_Handle *motorHandle);

/******************************************************************
 * \brief SG90 set duty
 * 
 * Detailed description starts here 
 * @param motor         PWM_Handle value
 * @param duty          motor duty value
 * @return None
 *******************************************************************/
void SG90_setDuty(PWM_Handle motor, uint32_t duty);

/******************************************************************
 * \brief SG90 start
 * 
 * Detailed description starts here 
 * @param motor         PWM_Handle value
 * @return None
 *******************************************************************/
void SG90_start(PWM_Handle motorHandle);
#endif /* SG90_H_ */
