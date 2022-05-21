/**
 * @file PressureSensor.h
 * @author Jesus Minjares @see https://github.com/jminjares4 
 * @author Erick A. Baca  @see https://github.com/eabaca2419 
 * @brief Pressure sensor driver
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PRESSURESENSOR_H_
#define PRESSURESENSOR_H_
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <ti/drivers/ADC.h>
#include <semaphore.h>
#include "ti_drivers_config.h"
/* ADC semaphore */
sem_t pressureSensorSem;
/*Global Variables*/
#define PRESSURE_SENSOR_SAMPLE 10           /*!< Pressure Sensor Max Samples */
uint16_t adcBuf[PRESSURE_SENSOR_SAMPLE];    /*!< ADC data buffer */
uint32_t adcAvg;                            /*!< ADC average */
ADC_Handle adcHandle;                       /*!< ADC handle */

/******************************************************************
 * \brief Pressure Sensor Initialize
 * 
 * Detailed description starts here 
 * @param void		No argument
 * @return None
 *******************************************************************/
void Pressure_Sensor_init(void);
/*Initialize Pressure Sensor Timer*/

/******************************************************************
 * \brief Pressure Sensor Timer Initialize
 * 
 * Detailed description starts here 
 * @param pressureSensorHandle  pressure sensor timer handle
 * @param pressureSensorParam   pressure sensor timer parameters
 * @param hertz                 pressure sensor timer frequency
 * @return None
 *******************************************************************/
void Pressure_Sensor_Timer_init(Timer_Handle *pressureSensorHandle, Timer_Params *pressureSensorParam,uint16_t hertz);

/******************************************************************
 * \brief Pressure Sensor Timer Start
 * 
 * Detailed description starts here 
 * @param pressureSensorHandle  pressure sensor timer handle
 * @param pressureSensorParam   pressure sensor timer parameters
 * @return None
 *******************************************************************/
void Pressure_Sensor_start(Timer_Handle *pressureSensorHandle, Timer_Params *pressureSensorParam);


/******************************************************************
 * \brief Pressure Sensor Timer Callback
 * 
 * Detailed description starts here 
 * @param handle  pressure sensor timer handle
 * @return None
 *******************************************************************/
void pressureSensorCallback(Timer_Handle handle);

#endif /* PRESSURESENSOR_H_ */
