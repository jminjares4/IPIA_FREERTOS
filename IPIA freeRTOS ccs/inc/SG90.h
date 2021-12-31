/*
 *  ======== SG90.h ========
 *   Authors:   Jesus Minjares, Bachelor of Science in Electrical Engineering
 *              Erick A. Baca, Bachelor of Science in Electrical Engineering
 */
#ifndef SG90_H_
#define SG90_H_
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <ti/drivers/PWM.h>
#include "ti_drivers_config.h"
/*SERVO LIMITS*/
#define SERVO_MIN 12000
#define SERVO_MAX 24000
/*Initialize S90 Driver*/
void SG90_init(uint_least8_t index, PWM_Handle *motorHandle);
/*Set Sg90 duty cycle*/
void SG90_setDuty(PWM_Handle motor, uint32_t duty);
/*Start SG90 Motor*/
void SG90_start(PWM_Handle motorHandle);
#endif /* SG90_H_ */
