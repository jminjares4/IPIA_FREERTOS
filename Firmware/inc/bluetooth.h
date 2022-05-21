/**
 * @file bluetooth.h
 * @author Jesus Minjares @see https://github.com/jminjares4 
 * @author Erick A. Baca  @see https://github.com/eabaca2419 
 * @brief Bluetooth driver
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <ti/drivers/UART.h>
#include "GPS.h"
#include "ti_drivers_config.h"
/*Set Size of Buffer*/

#define BLUETOOTH_BUFFER 512 /*!< Bluetooth Max Buffer */

UART_Handle bluetoothUartHandle; /*!< Global instance of UART Handle */

char bluetooth_buffer[BLUETOOTH_BUFFER]; /*!< Global buffer */

/******************************************************************
 * \brief Bluetooth Initialize
 * 
 * Detailed description starts here 
 * @param void		No argument
 * @return None
 *******************************************************************/
void bluetooth_init(void);

/******************************************************************
 * \brief Bluetooth character
 * 
 * Detailed description starts here 
 * @param buffer		character buffer
 * @param c             character
 * @param index         index
 * @see https://github.com/grbl/grbl/blob/master/grbl/print.c
 * @return None
 *******************************************************************/
void bluetooth_char(char *buffer, char c, uint32_t *index);

/******************************************************************
 * \brief Bluetooth string
 * 
 * Detailed description starts here 
 * @param buffer		character buffer
 * @param string        character
 * @param index         index
 * @see https://github.com/grbl/grbl/blob/master/grbl/print.c
 * @return None
 *******************************************************************/
void bluetooth_string(char *buffer, char *string, uint32_t *index);

/******************************************************************
 * \brief Bluetooth integer
 * 
 * Detailed description starts here 
 * @param buffer		character buffer
 * @param integer       integer to be stored
 * @param index         index
 * @see https://github.com/grbl/grbl/blob/master/grbl/print.c
 * @return None
 *******************************************************************/
void bluetooth_integer(char *buffer, int integer, uint32_t *index);


/******************************************************************
 * \brief Bluetooth float
 * 
 * Detailed description starts here 
 * @param buffer		character buffer
 * @param n             value
 * @param decimal_place how many decimal places
 * @param index         index
 * @see https://github.com/grbl/grbl/blob/master/grbl/print.c
 * @return None
 *******************************************************************/
void bluetooth_float(char *buffer, float n, uint8_t decimal_places, uint32_t *index);

/******************************************************************
 * \brief Bluetooth sprintf
 * 
 * Detailed description starts here 
 * @param buffer		character buffer
 * @param fs            string to be parsed
 * @param ...           arguments
 * @see https://github.com/grbl/grbl/blob/master/grbl/print.c
 * @return None
 *******************************************************************/
void bluetooth_sprintf(char *buffer, const char *fs, ...);
/*Send message via UART*/

/******************************************************************
 * \brief Bluetooth send
 * 
 * Detailed description starts here 
 * @param coordinate    system coordinate
 * @param sysTime       system current time
 * @param adc           solar panel reading
 * @see https://github.com/grbl/grbl/blob/master/grbl/print.c
 * @return None
 *******************************************************************/
void bluetooth_send(const COORDINATE *coordinate, const SysTime *sysTime, uint32_t adc);
#endif /* BLUETOOTH_H_ */
