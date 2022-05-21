/**
 * @file GPS.c
 * @author Jesus Minjares @see https://github.com/jminjares4
 * @brief GPSlibrary was design to organize the NMEA format gather from
    GPS Module(SIM33EAU) by Serial Communication.
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "inc/GPS.h"

void print_NMEA_GNRMC(const NMEA_GNRMC *data){
    printf("NAME: %s\n", data->name);
    printf("UTC TIME: %s\n", data->utc_time);
    printf("STATUS: %s\n",data->status);
    printf("LATITUDE: %s\n",data->latitude);
    printf("LATITUDE DIRECTION: %s\n", data->latitudeDirection);
    printf("LONGITUDE: %s\n",data->longitude);
    printf("LONGITUDE DIRECTION: %s\n", data->longitudeDirection);
    printf("SPEED: %s\n", data->speedOverGround);
    printf("COURSE: %s\n", data->courseOverGround);
    printf("UTC DATE: %s\n", data->utc_date);
    printf("MODE & CHECKSUM: %s\n", data->modeIndicatorAndcheckSum);
}
char* token(char *str, char *delimiter){
    static char *state;   // state is a char pointer point to a specific char
    // location in "str". It records non-scanned part
    char *d, *beg;
    if (str != NULL)
        state = str;
    for (; *state != '\0'; state++) {   // find beg, delete previous delimiter
        for (d = delimiter; *d != '\0'; d++)
            if (*d == *state)
                break;
        if (*d == '\0')
            break;
    }
    if (*state == '\0')    // if reach '\0', no token, return NULL
        return NULL;
    else
        beg = state;       // else, find beg

    for (; *state != '\0'; state++) {   // find end
        for (d= delimiter; *d != '\0'; d++)
            if (*d == *state)
                break;
        if (*d != '\0')
            break;
    }
    if (*state != '\0')     // if not reach '\0', put '\0', and state++
        *state++ = '\0';

    return beg;    // return beg of token
}

void print_UTC_TIME(const UTC_TIME *time){
    printf("HOUR: %s\n", time->hour);
    printf("MINUTE: %s\n", time->minute);
    printf("SECOND: %s\n", time->second);
    printf("MILLI: %s\n", time->milli);
    printf("---TIME---\n");
    printf("%s:%s:%s.%s\n",time->hour,time->minute,time->second, time->milli);
}
 
NMEA_GNRMC setGnrmc(char *str){
    NMEA_GNRMC temp; //create a instance of NMEA_GNRMC
    char *del = ","; //set the delimiter
    //tokenize the string
    temp.name = token(str,del);
    temp.utc_time = token(NULL,del);
    temp.status = token(NULL,del);
    temp.latitude = token(NULL,del);
    temp.latitudeDirection =token(NULL,del);
    temp.longitude = token(NULL,del);
    temp.longitudeDirection  = token(NULL,del);
    temp.speedOverGround = token(NULL,del);
    temp.courseOverGround  = token(NULL,del);
    temp.utc_date  = token(NULL,del);
    temp.modeIndicatorAndcheckSum  = token(NULL,del);
    return temp; //return the instance of the NMEA_GNMRC
}

UTC_TIME setTime(char *utcTime){
    UTC_TIME time;//create an instance of the UTC
    //set the memory of each member to empty
    memset((void*)&time.hour, 0, sizeof(time.hour));
    memset((void*)&time.minute, 0, sizeof(time.minute));
    memset((void*)&time.second, 0, sizeof(time.second));
    memset((void*)&time.milli, 0, sizeof(time.milli));

    //copy part of the string to the corresponding UTC_TIME member
    memcpy((void*)&time.hour, (void*)&utcTime[0],2 );
    memcpy((void*)&time.minute,(void*)&utcTime[2],2);
    memcpy((void*)&time.second,(void*)&utcTime[4], 2);
    memcpy((void*)&time.milli,(void*)&utcTime[7], 4);
    return time; //return the time
}

COORDINATE setCoordinates(const NMEA_GNRMC *data){
    COORDINATE tempCoordinates; //create an instance COORDINATE
    //use sprintf to convert double to string
    //and store in COORDINATE members
    tempCoordinates.latitude  = latitudeDegrees(data->latitude, data->latitudeDirection);
    tempCoordinates.longitude = longitudeDegrees(data->longitude, data->longitudeDirection);
    return tempCoordinates;
}


void print_COORDINATE(const COORDINATE *tempCoor){
    printf("LAT: %lf\n",tempCoor->latitude);
    printf("LON: %lf\n",tempCoor->longitude);
    printf("%lf,%lf\n",tempCoor->latitude, tempCoor->longitude);
}

double latitudeDegrees(char *latitude, char *direction){
  double latitudeAsDouble = str_to_double(latitude);
  //NMEA format: ddmm.mmmm
  int dd = latitudeAsDouble / 100;  //get the dd
  double mmmm = latitudeAsDouble - dd*100; //get mmm in double
  if(direction[0] == 'N') //if the direction is N then i will be positive
    return dd + mmmm/60;
  else if(direction[0] == 'S') //if the direction is S, then it will negative
      return -1*(dd + mmmm/60);
  else
      return 0;
  //return (direction[0] == 'N') ? ddd+mmmm/60 : -1*(ddd + mmmm/60);
}

double longitudeDegrees(char *longitude, char *direction){
  double longitudeAsDouble = str_to_double(longitude);
  //NMEA format: dddmm.mmmm
  int ddd = longitudeAsDouble/100; //get the DD for the longtiude
  double mmmm = longitudeAsDouble - ddd*100; //get the mm.mmmm from the longitude
  if(direction[0] == 'E') //if direction is East, then postive
    return ddd + mmmm/60;
  else if(direction[0] == 'W') //if direction is West, then Negative
      return -1*(ddd + mmmm/60);
  else
    return 0; //if it recieve a errnous character return a 0
  //return (direction[0] == 'E') ? ddd+mmmm/60 : -1*(ddd + mmmm/60);
}
double str_to_double(char* num)
 {
     if (!num || !*num)
         return 0;
     double integerPart = 0;
     double fractionPart = 0;
     int divisorForFraction = 1;
     int sign = 1;
     bool inFraction = false;
     /*Take care of +/- sign*/
     if (*num == '-')
     {
         ++num;
         sign = -1;
     }
     else if (*num == '+')
     {
         ++num;
     }
     while (*num != '\0')
     {
         if (*num >= '0' && *num <= '9')
         {
             if (inFraction)
             {
                 /*See how are we converting a character to integer*/
                 fractionPart = fractionPart*10 + (*num - '0');
                 divisorForFraction *= 10;
             }
             else
             {
                 integerPart = integerPart*10 + (*num - '0');
             }
         }
         else if (*num == '.')
         {
             if (inFraction)
                 return sign * (integerPart + fractionPart/divisorForFraction);
             else
                 inFraction = true;
         }
         else
         {
             return sign * (integerPart + fractionPart/divisorForFraction);
         }
         ++num;
     }
     return sign * (integerPart + fractionPart/divisorForFraction);
 }
