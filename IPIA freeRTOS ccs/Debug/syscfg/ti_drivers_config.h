/*
 *  ======== ti_drivers_config.h ========
 *  Configured TI-Drivers module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSP_EXP432P401R
 *  by the SysConfig tool.
 */
#ifndef ti_drivers_config_h
#define ti_drivers_config_h

#define CONFIG_SYSCONFIG_PREVIEW

#define CONFIG_MSP_EXP432P401R

#ifndef DeviceFamily_MSP432P401x
#define DeviceFamily_MSP432P401x
#endif

#include <ti/devices/DeviceFamily.h>

#include <stdint.h>

/* support C++ sources */
#ifdef __cplusplus
extern "C" {
#endif


/*
 *  ======== ADC ========
 */

/* P5.5 */
#define SOLAR_PANEL                 0
/* P5.4 */
#define PRESSURE_SENSOR             1


/*
 *  ======== GPIO ========
 */

/* P3.6 */
#define SIM33EAU_EN                 0
/* P1.0, LaunchPad LED 1 Red */
#define RED                         1

/* LEDs are active high */
#define CONFIG_GPIO_LED_ON  (1)
#define CONFIG_GPIO_LED_OFF (0)

#define CONFIG_LED_ON  (CONFIG_GPIO_LED_ON)
#define CONFIG_LED_OFF (CONFIG_GPIO_LED_OFF)


/*
 *  ======== PWM ========
 */

/* P2.7 */
#define Y_AXIS                      0
/* P2.6 */
#define X_AXIS                      1


/*
 *  ======== Timer ========
 */

#define TIMERA0                     0
#define PRESSURE_SENSOR_TIMER       1

/*
 *  ======== UART ========
 */

/*
 *  TX: P3.3
 *  RX: P3.2
 */
#define BLUETOOTH                   0
/*
 *  TX: Unassigned
 *  RX: P3.0
 */
#define SIM33EAU_GPS                1
/*
 *  TX: P1.3
 *  RX: P1.2
 *  XDS110 UART
 */
#define CONFIG_UART_0               2


/*
 *  ======== Board_init ========
 *  Perform all required TI-Drivers initialization
 *
 *  This function should be called once at a point before any use of
 *  TI-Drivers.
 */
extern void Board_init(void);

/*
 *  ======== Board_initGeneral ========
 *  (deprecated)
 *
 *  Board_initGeneral() is defined purely for backward compatibility.
 *
 *  All new code should use Board_init() to do any required TI-Drivers
 *  initialization _and_ use <Driver>_init() for only where specific drivers
 *  are explicitly referenced by the application.  <Driver>_init() functions
 *  are idempotent.
 */
#define Board_initGeneral Board_init

#ifdef __cplusplus
}
#endif

#endif /* include guard */
