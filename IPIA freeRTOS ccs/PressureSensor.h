/*
 *  ======== PressureSensor.h ========
 *   Authors:   Jesus Minjares, MS in Computer Engineering
 *              Erick A. Baca, MS in Computer Engineering
 */
#ifndef PRESSURESENSOR_H_
#define PRESSURESENSOR_H_
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <ti/drivers/Timer.h>
#include <ti/drivers/ADC.h>
#include <semaphore.h>
#include "ti_drivers_config.h"
/* ADC semaphore */
sem_t pressureSensorSem;
/*Global Variables*/
#define PRESSURE_SENSOR_SAMPLE 10
uint16_t adcBuf[PRESSURE_SENSOR_SAMPLE];
uint32_t adcAvg;
ADC_Handle adcHandle;\
/*Initialize Pressure Sensor Driver*/
void Pressure_Sensor_init(void);
/*Initialize Pressure Sensor Timer*/
void Pressure_Sensor_Timer_init(Timer_Handle *pressureSensorHandle, Timer_Params *pressureSensorParam,uint16_t hertz);
/*Start Pressure Sensor Timer*/
void Pressure_Sensor_start(Timer_Handle *pressureSensorHandle, Timer_Params *pressureSensorParam);
/*Pressure Sensor Callback*/
void pressureSensorCallback(Timer_Handle handle);
#endif /* PRESSURESENSOR_H_ */
