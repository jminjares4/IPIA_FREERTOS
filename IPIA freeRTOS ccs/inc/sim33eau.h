/*
 *  ======== sim33eau.h ========
 *   Authors:   Jesus Minjares, Bachelor of Science in Electrical Engineering
 *              Erick A. Baca, Bachelor of Science in Electrical Engineering
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
#define BUFFER 82
UART_Handle gpsUartHandle;
char gpsData[BUFFER];
/*Data Structures*/
NMEA_GNRMC nmeaGnrmc;
UTC_TIME utcTime;
COORDINATE coordinate;
SysTime sysTime;
/*Initialize GPS*/
void GPS_init();
/*Read GPS Line a total of n lines*/
void GPS_read(uint8_t totalRead);
/*GPS stop will toggle enable pin to turn off sim33eau*/
void GPS_stop();
/*Check if a str has substring of substr*/
bool isSubstring(char *str, char *substr);
/*Convert String to uint8_t*/
uint8_t str_to_uint8(char *str);
/*Convert String to uint16_t*/
uint16_t str_to_uint16(char *str);
/*Set SysTime structure with UTC_TIME data*/
SysTime setSysTime(const UTC_TIME  *gpsUtcTime);
//void displayGpsData(Display_Handle displayHandle, NMEA_GNRMC nmeaGnrmc, UTC_TIME utcTime, COORDINATE coordinate, SysTime sysTime);
#endif /* SIM33EAU_H_ */
