/**
 * @file sim33eau.h
 * @author Jesus Minjares @see https://github.com/jminjares4 
 * @author Erick A. Baca  @see https://github.com/eabaca2419 
 * @brief sim33eau driver
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SIM33EAU_H_
#define SIM33EAU_H_
#include <ti/drivers/UART.h>
#include <ti/drivers/GPIO.h>
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include "GPS.h"
#include "ti_drivers_config.h"

/*GPS THREAD*/
#define BUFFER 82                       /*!< Buffer Max Bytes */
UART_Handle gpsUartHandle;              /*!< GPS Uart Handle */
char gpsData[BUFFER];                   /*!< GPS Data */

/*Data Structures*/
NMEA_GNRMC nmeaGnrmc;                   /*!< NMEA GNRMC object */
UTC_TIME utcTime;                       /*!< UTC TIME object */
COORDINATE coordinate;                  /*!< COORDINATE object */
SysTime sysTime;                        /*!< SysTime object */

/******************************************************************
 * \brief GPS Initialize
 * 
 * Detailed description starts here 
 * @param void		No argument
 * @return None
 *******************************************************************/
void GPS_init(void);

/******************************************************************
 * \brief GPS read
 * 
 * Detailed description starts here 
 * @param totalRead		 nth number of lines
 * @return None
 *******************************************************************/
void GPS_read(uint8_t totalRead);

/******************************************************************
 * \brief GPS stop
 * 
 * Detailed description starts here 
 * @param void		No argument
 * @return None
 *******************************************************************/
void GPS_stop(void);

/*Check if a str has substring of substr*/

/******************************************************************
 * \brief Check if string is a substring
 * 
 * Detailed description starts here 
 * @param str       primary string
 * @param substr    substring
 * @return bool substr is a substring of str
 *******************************************************************/
bool isSubstring(char *str, char *substr);


/******************************************************************
 * \brief String to uint8_t
 * 
 * Detailed description starts here 
 * @param str       string
 * @return uint8_t  value
 *******************************************************************/
uint8_t str_to_uint8(char *str);

/******************************************************************
 * \brief String to uint16_t
 * 
 * Detailed description starts here 
 * @param str       string
 * @return uint16_t  value
 *******************************************************************/
uint16_t str_to_uint16(char *str);
/*Set SysTime structure with UTC_TIME data*/

/******************************************************************
 * \brief Set System Time
 * 
 * Detailed description starts here 
 * @param gpsUtcTime        UTC_TIME reference @see UTC_TIME
 * @return SysTime          instance of SysTime
 *******************************************************************/
SysTime setSysTime(const UTC_TIME  *gpsUtcTime);

//void displayGpsData(Display_Handle displayHandle, NMEA_GNRMC nmeaGnrmc, UTC_TIME utcTime, COORDINATE coordinate, SysTime sysTime);
#endif /* SIM33EAU_H_ */
