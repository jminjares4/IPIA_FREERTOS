/**
 * @file GPS.h
 * @author Jesus Minjares @see https://github.com/jminjares4
 * @brief GPS NMEA custom API
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GPS_H
#define GPS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

/******************************************************************
 * \struct SysTime GPS.h
 * \brief SysTime Time object
 *
 * ### Example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.c
 * typedef struct{
 *      uint8_t hour;
 *      uint8_t minute;
 *      uint8_t second;
 *      uint16_t milli;
 * }SysTime;
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *******************************************************************/
typedef struct{
    uint8_t hour;       /*!< Hour */
    uint8_t minute;     /*!< Minuute */
    uint8_t second;     /*!< Second */
    uint16_t milli;     /*!< Millisecond */
}SysTime;


/******************************************************************
 * \struct NMEA_GNRMC GPS.h
 * \brief NMEA_GNRMC Time object
 *
 * ### Example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.c
 * typedef struct NMEA_GNRMC{
 *      char *name;
 *      char *utc_time;
 *      char *status;
 *      char *latitude;
 *      char *latitudeDirection;
 *      char *longitude;
 *      char *longitudeDirection;
 *      char *speedOverGround;
 *      char *courseOverGround;
 *      char *utc_date;
 *      char *modeIndicatorAndcheckSum;
 * }NMEA_GNRMC;
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *******************************************************************/
typedef struct NMEA_GNRMC{
    char *name;                         /*!< Name */
    char *utc_time;                     /*!< UTC time */
    char *status;                       /*!< Status */
    char *latitude;                     /*!< Latitude */
    char *latitudeDirection;            /*!< Latitude direction */
    char *longitude;                    /*!< Longitude */
    char *longitudeDirection;           /*!< Longitude direction */
    char *speedOverGround;              /*!< Speed over ground */
    char *courseOverGround;             /*!< Course over ground  */
    char *utc_date;                     /*!< UTC date */
    char *modeIndicatorAndcheckSum;     /*!< Mode and check sum */
}NMEA_GNRMC;


/******************************************************************
 * \struct UTC_TIME GPS.h
 * \brief UTC_TIME object
 *
 * ### Example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.c
 * typedef struct UTC_TIME{
 *      char hour[3];
 *      char minute[3];
 *      char second[3];
 *      char milli[4];
 * }UTC_TIME;
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *******************************************************************/
typedef struct UTC_TIME{
    char hour[3];           /*!< Hour */
    char minute[3];         /*!< Minute */
    char second[3];         /*!< Second */
    char milli[4];          /*!< Millisecond */
}UTC_TIME;


/******************************************************************
 * \struct COORDINATE GPS.h
 * \brief COORDINATE object
 *
 * ### Example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.c
 * typedef struct COORDINATE{
 *      double latitude;
 *      double longitude;
 * }COORDINATE;
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *******************************************************************/
typedef struct COORDINATE{
    double latitude;        /*!< Latitude */
    double longitude;       /*!< Longitude */
}COORDINATE;


/******************************************************************
 * \brief Tokenize a string by a delimiter
 * 
 * Detailed description starts here 
 * @param str           string 
 * @param delimiter     custom delimiter
 * @return char *       tokenized string
 *******************************************************************/
char* token(char *str, char *delimiter);

/******************************************************************
 * \brief Print GNRMC structure @see NMEA_GNRMC
 * 
 * Detailed description starts here 
 * @param data      constant NMEA_GNRMC pointer
 * @return None
 *******************************************************************/
void print_NMEA_GNRMC(const NMEA_GNRMC *data);


/******************************************************************
 * \brief  Print the UTC_TIME Object @see UTC_TIME
 * 
 * Detailed description starts here 
 * @param time      UTC_TIME reference
 * @return None
 *******************************************************************/
void print_UTC_TIME(const UTC_TIME *time);

/******************************************************************
 * \brief  Parse string into NMEA_GNRMC object @see NMEA_GNRMC
 * 
 * Detailed description starts here 
 * @param str   GPS string
 * @return NMEA_GNRMC instance of the NMEA_GNRMC
 *******************************************************************/
NMEA_GNRMC setGnrmc(char *str);

/******************************************************************
 * \brief  Set UTC time in UTC_TIME object @see UTC_TIME
 * 
 * Detailed description starts here 
 * @param str  NMEA_GNRMC utc time string @see NMEA_GNRMC
 * @return UTC_TIME instance of the UTC_TIME
 *******************************************************************/
UTC_TIME setTime(char *utcTime);

/******************************************************************
 * \brief  Set Coordinate in COORDINATE object @see COORDINATE
 * 
 * Detailed description starts here 
 * @param data  NMEA_GNRMC refrence @see NMEA_GNRMC
 * @return COORDINATE instance of the COORDINATE
 *******************************************************************/
COORDINATE setCoordinates(const NMEA_GNRMC *data);

/******************************************************************
 * \brief  Print coordinates members @see COORDINATE
 * 
 * Detailed description starts here 
 * @param data  COORDINATE refrence @see COORDINATE
 * @return None
 *******************************************************************/
void print_COORDINATE(const COORDINATE *tempCoordinate);


/******************************************************************
 * \brief  Convert latitude decimal value to degrees
 * 
 * Detailed description starts here 
 * @param latitude  NMEA_GNRMC latitude @see NMEA_GNRMC
 * @param direction NMEA_GNRMC latitude direction @see NMEA_GNRMC
 * @return double latitude in degrees
 *******************************************************************/
double latitudeDegrees(char* latitude, char *direction);

/******************************************************************
 * \brief  Convert longitude decimal value to degrees
 * 
 * Detailed description starts here 
 * @param latitude  NMEA_GNRMC longitude @see NMEA_GNRMC
 * @param direction NMEA_GNRMC longitude direction @see NMEA_GNRMC
 * @return double longitude in degrees
 *******************************************************************/
double longitudeDegrees(char *longitude,char *direction);

/******************************************************************
 * \brief  Convert string to floating point
 * 
 * Detailed description starts here 
 * @param num   string
 * @return double floating point value
 *******************************************************************/
double str_to_double(char* num);
#endif
