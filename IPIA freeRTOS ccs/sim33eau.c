/*
 *  ======== sim33eau.c ========
 *   Authors:   Jesus Minjares, MS in Computer Engineering
 *              Erick A. Baca, MS in Computer Engineering
 */
#include "sim33eau.h"
/*Initialize GPS*/
void GPS_init(){
    /*Initialize Drivers*/
    GPIO_init();
    UART_init();
    /*Set PIN as OUTPUT*/
    GPIO_setConfig(SIM33EAU_EN, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_write(SIMM33EAU_EN, 1);
    
    UART_Params uartParams;
    /*Set UART Parameter to default*/
    UART_Params_init(&uartParams);
    /*Set GPS parameter for read only @ 9600 with binary input*/
    uartParams.readMode = UART_MODE_BLOCKING;
    uartParams.writeMode = UART_MODE_BLOCKING;
    uartParams.readTimeout = UART_WAIT_FOREVER;
    uartParams.writeTimeout = UART_WAIT_FOREVER;
    uartParams.readCallback = NULL;
    uartParams.writeCallback = NULL;
    uartParams.readReturnMode = UART_RETURN_NEWLINE;
    uartParams.readDataMode = UART_DATA_BINARY;
    uartParams.writeDataMode = UART_DATA_TEXT;
    uartParams.readEcho = UART_ECHO_OFF;
    uartParams.baudRate = 9600;
    uartParams.dataLength = UART_LEN_8;
    uartParams.stopBits = UART_STOP_ONE;
    uartParams.parityType = UART_PAR_NONE;
    /*Open UART Instance*/
    gpsUartHandle = UART_open(SIM33EAU_GPS, &uartParams);
    /*Check for error*/
    if(gpsUartHandle == NULL){
       while(1);
    }
    return;
}
/*Read GPS Line a total of n lines*/
void GPS_read(uint8_t totalRead){
    int index = 0;
    int count = 0;
    /*Iterate until totalRead*/
    while(count < totalRead){
        char c;
        /*Read character and store in c*/
        UART_read(gpsUartHandle, &c, 1);
        gpsData[index++] = c; //store in buffer
        if( gpsData[index-1] == '\r'){ //check if a carriage return has been read
            if(isSubstring((char*)gpsData,"GNRMC")){ //check if GNRMC is a substring
                count++; //increment count
                /*Parse Data*/
                nmeaGnrmc = setGnrmc(gpsData);
                utcTime = setTime(nmeaGnrmc.utc_time);
                coordinate = setCoordinates(&nmeaGnrmc);
                sysTime = setSysTime(&utcTime);
//                displayGpsData(displayHandle, nmeaGnrmc, utcTime, coordinate, sysTime);
            }
            index = 0;//reset index to 0
            memset(gpsData, 0, sizeof(gpsData)); //clear buffer
        }
    }
    return;
}
/*GPS stop will toggle enable pin to turn off sim33eau*/
void GPS_stop(){
    GPIO_write(SIM33EAU_EN, 0); // turn off GPS
    usleep(10000);
}
/*Set SysTime structure with UTC_TIME data*/
SysTime setSysTime(const UTC_TIME  *gpsUtcTime){
    SysTime tempSysTime;
    tempSysTime.hour = str_to_uint8((char*)gpsUtcTime->hour);
    tempSysTime.minute = str_to_uint8((char*)gpsUtcTime->minute);
    tempSysTime.second = str_to_uint8((char *)gpsUtcTime->second);
    tempSysTime.milli = str_to_uint16((char*)gpsUtcTime->milli);
    return tempSysTime; //return sysTime instance
}
/*Check if a str has substring of substr*/
bool isSubstring(char *str, char *substr){
    int i;
    int len = strlen(str);
    int len2 = strlen(substr);
    for(i = 0; i < len; i++){
        if(str[i] == substr[0]){
            int j;
            int temp = i;
            for(j = 0; j < len2; j++){
                if(substr[j] == str[temp++])
                    continue;
                else{
                    break;
                }
            }
            if(temp - i == strlen(substr)){
                return true;
            }
        }
    }
    return false;
}
/*Convert String to uint8_t*/
uint8_t str_to_uint8(char *str){
    uint8_t result;
    uint8_t puiss;
    result = 0;
    puiss = 1;
    while (('-' == (*str)) || ((*str) == '+')){
        if (*str == '-')
            puiss = puiss * -1;
        str++;
    }
    while ((*str >= '0') && (*str <= '9')){
        result = (result * 10) + ((*str) - '0');
        str++;
    }
    return (result * puiss);
}
/*Convert String to uint16_t*/
uint16_t str_to_uint16(char *str){
    uint16_t result;
    uint16_t puiss;
    result = 0;
    puiss = 1;
    while (('-' == (*str)) || ((*str) == '+')){
        if (*str == '-')
            puiss = puiss * -1;
        str++;
    }
    while ((*str >= '0') && (*str <= '9')){
        result = (result * 10) + ((*str) - '0');
        str++;
    }
    return (result * puiss);
}
//void displayGpsData(Display_Handle displayHandle, NMEA_GNRMC nmeaGnrmc, UTC_TIME utcTime, COORDINATE coordinate, SysTime sysTime){
//    Display_printf(displayHandle, 0,0, "/* NMEA_GNRMC */\n");
//    Display_printf(displayHandle, 0,0, "NMEA: %s\n", nmeaGnrmc.name);
//    Display_printf(displayHandle, 0,0, "UTC_TIME: %s\n", nmeaGnrmc.utc_time);
//    Display_printf(displayHandle, 0,0, "Status: %s\n", nmeaGnrmc.status);
//    Display_printf(displayHandle, 0,0,"Latitude: %s\tDirection: %s\n",nmeaGnrmc.latitude, nmeaGnrmc.latitudeDirection);
//    Display_printf(displayHandle, 0,0,"Longitude: %s\tDirection: %s\n",nmeaGnrmc.longitude, nmeaGnrmc.longitudeDirection);
//    Display_printf(displayHandle, 0,0, "Speed over ground: %s\n", nmeaGnrmc.speedOverGround);
//    Display_printf(displayHandle, 0,0,"Course over ground: %s\n", nmeaGnrmc.courseOverGround);
//    Display_printf(displayHandle, 0,0, "UTC_DATE: %s\n", nmeaGnrmc.utc_date);
//    Display_printf(displayHandle,0,0,"Mode Indicator and Check Sum: %s\n", nmeaGnrmc.modeIndicatorAndcheckSum);
//    Display_printf(displayHandle, 0,0, "/* UTC_TIME */\n");
//    Display_printf(displayHandle,0,0,"UTC_TIME: %s:%s:%s:%s\n", utcTime.hour, utcTime.minute, utcTime.second, utcTime.milli);
//    Display_printf(displayHandle, 0,0, "/* COORDINATE */\n");
//    Display_printf(displayHandle, 0,0, "LAT,LON: %lf,%lf\n", coordinate.latitude, coordinate.longitude);
//    Display_printf(displayHandle, 0,0, "/* SysTime */\n");
//    Display_printf(displayHandle,0,0,"UTC_TIME: %u:%u:%u:%u\n", sysTime.hour, sysTime.minute, sysTime.second, sysTime.milli);
//    sleep(5);
//    Display_printf(displayHandle,0,0,"%c[2J%c[H",27,27);
//}

