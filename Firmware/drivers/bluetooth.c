/**
 * @file bluetooth.c
 * @author Jesus Minjares @see https://github.com/jminjares4 
 * @author Erick A. Baca  @see https://github.com/eabaca2419 
 * @brief Bluetooth driver source code
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "inc/bluetooth.h"

void bluetooth_init(void){
    /*UART Driver*/
    UART_init();
    UART_Params bluetoothUartParams;
    /*Initialize UART Param*/
    UART_Params_init(&bluetoothUartParams);
    /*Set Bluetooth Parameter to send and read @ 9600*/
    bluetoothUartParams.readMode = UART_MODE_BLOCKING;
    bluetoothUartParams.writeMode = UART_MODE_BLOCKING;
    bluetoothUartParams.readTimeout = UART_WAIT_FOREVER;
    bluetoothUartParams.writeTimeout = UART_WAIT_FOREVER;
    bluetoothUartParams.readCallback = NULL;
    bluetoothUartParams.writeCallback = NULL;
    bluetoothUartParams.readReturnMode = UART_RETURN_NEWLINE;
    bluetoothUartParams.readDataMode = UART_DATA_TEXT;
    bluetoothUartParams.writeDataMode = UART_DATA_BINARY;
    bluetoothUartParams.readEcho = UART_ECHO_OFF;
    bluetoothUartParams.baudRate = 9600;
    bluetoothUartParams.dataLength = UART_LEN_8;
    bluetoothUartParams.stopBits = UART_STOP_ONE;
    bluetoothUartParams.parityType = UART_PAR_NONE;
    /*open UART instance */
    bluetoothUartHandle = UART_open(BLUETOOTH,&bluetoothUartParams);
    if(bluetoothUartHandle == NULL){
        while(1);
    }
    return;
}


void bluetooth_char(char *buffer, char c, uint32_t *index){
    buffer[*index] = c;
    *index = *index + 1;
}

void bluetooth_string(char *buffer, char *string, uint32_t *index){
    /*while the string is not the null character*/
    while(*string){
        bluetooth_char(buffer, *string, index);
        string++;
    }
}

void bluetooth_integer(char *buffer, int integer, uint32_t *index){
    if(integer == 0){
        bluetooth_char(buffer, '0', index);
    }
    if(integer < 0){
        bluetooth_char(buffer, '-', index);
        integer = -integer;
    }

    char b[10];
    int digit = integer;

    uint8_t i = 0;
    while(digit){
        b[i++] = digit % 10;
        digit /= 10;
    }

    while(i){
        bluetooth_char(buffer, '0' + b[i-1], index);
        i--;
    }
}

void bluetooth_float(char *buffer, float n, uint8_t decimal_places, uint32_t *index){
    if (n < 0){
        bluetooth_char(buffer, '-', index);
        n = -n;
    }

    uint8_t decimals = decimal_places;
    while (decimals >= 2){
      // Quickly convert values expected to be E0 to E-4.
      n *= 100;
      decimals -= 2;
    }

    if (decimals){
      n *= 10;
    }

    // Add rounding factor. Ensures carryover through entire value.
    n += 0.5;

    // Generate digits backwards and store in string.
    uint8_t buf[32];
    uint8_t i = 0;
    uint32_t a = (long)n;
    // Place decimal point, even if decimal places are zero.
    buf[decimal_places] = '.';

    while(a > 0){
        // Skip decimal point location
        if (i == decimal_places){
            i++;
        }

        // Get digit
        buf[i++] = (a % 10) + '0';
        a /= 10;
    }

    while (i < decimal_places){
        // Fill in zeros to decimal point for (n < 1)
        buf[i++] = '0';
    }

    // Fill in leading zero, if needed.
    if (i == decimal_places){
        i++;
        buf[i++] = '0';
    }

    // Print the generated string.
    for (; i > 0; i--){
        bluetooth_char(buffer, buf[i-1], index);
    }
}

void bluetooth_sprintf(char *buffer, const char *fs, ...){
    va_list valist;
    va_start(valist, fs);
    int i;
    char *s;
    float f;
    uint32_t index = 0;

    while(*fs){
        if(*fs != '%'){
            bluetooth_char(buffer, *fs, &index);
            fs++;
        }
        else{
            switch(*++fs){
            case 'c':
                i = va_arg(valist, int);
                bluetooth_char(buffer, (char)i, &index);
                break;
            case 's':
                s = va_arg(valist, char*);
                bluetooth_string(buffer, s, &index);
                break;
            case 'i':
                i = va_arg(valist, int);
                bluetooth_integer(buffer, i, &index);
                break;
            case 'f':
                f = va_arg(valist, double);
                bluetooth_float(buffer, f, 3, &index);
                break;
            }
            ++fs;
        }
    }

    buffer[index] = '\0';
}

void bluetooth_send(const COORDINATE *coordinate, const SysTime *sysTime, uint32_t adc){
    bluetooth_sprintf(bluetooth_buffer, "DATA:%f,%f,%u:%u:%u:%u,%i\r\n", coordinate->latitude,
                                                                         coordinate->longitude,
                                                                         sysTime->hour,
                                                                         sysTime->minute,
                                                                         sysTime->second,
                                                                         sysTime->milli,
                                                                         adc);
    /*send buffer via uart handle*/
    UART_write(bluetoothUartHandle, bluetooth_buffer, strlen(bluetooth_buffer));
}
