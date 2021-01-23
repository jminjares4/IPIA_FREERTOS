/*
 *  ======== bluetooth.h ========
 *   Authors:   Jesus Minjares, MS in Computer Engineering
 *              Erick A. Baca, MS in Computer Engineering
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
#define BLUETOOTH_BUFFER 512
/*Global instance of UART handle*/
UART_Handle bluetoothUartHandle;
/*Global Buffer*/
char bluetooth_buffer[BLUETOOTH_BUFFER];
/*Initialize Bluetooth Driver*/
void bluetooth_init();
/*Thanks! https://github.com/grbl/grbl/blob/master/grbl/print.c */
void bluetooth_char(char *buffer, char c, uint32_t *index);
void bluetooth_string(char *buffer, char *string, uint32_t *index);
void bluetooth_integer(char *buffer, int integer, uint32_t *index);
void bluetooth_float(char *buffer, float n, uint8_t decimal_places, uint32_t *index);
void bluetooth_sprintf(char *buffer, const char *fs, ...);
/*Send message via UART*/
void bluetooth_send(const COORDINATE *coordinate, const SysTime *sysTime, uint32_t adc);
#endif /* BLUETOOTH_H_ */
