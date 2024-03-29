/*
 *  ======== main_freertos.c ========
 *   Authors:   Jesus Minjares, Bachelor of Science in Electrical Engineering
 *              Erick A. Baca, Bachelor of Science in Electrical Engineering
 */
#include <stdint.h>

#ifdef __ICCARM__
#include <DLib_Threads.h>
#endif

/* POSIX Header files */
#include <pthread.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>

/* Driver configuration */
#include <ti/drivers/Board.h>

extern void *solarTrackerThread(void *arg0);
extern void *gpsThread(void*arg0);
extern void *pressureSensorThread(void *arg0);


/* Stack size in bytes */
#define THREADSTACKSIZE   1024

/*
 *  ======== main ========
 */
int main(void)
{
    pthread_t           thread, thread2, thread3;
    pthread_attr_t      attrs;
    struct sched_param  priParam;
    int                 retc;

    /* initialize the system locks */
#ifdef __ICCARM__
    __iar_Initlocks();
#endif

    /* Call driver init functions */
    Board_init();

    /* Initialize the attributes structure with default values */
    pthread_attr_init(&attrs);

    /* Set priority, detach state, and stack size attributes */
    priParam.sched_priority = 1;
    retc = pthread_attr_setschedparam(&attrs, &priParam);
    retc |= pthread_attr_setdetachstate(&attrs, PTHREAD_CREATE_DETACHED);
    retc |= pthread_attr_setstacksize(&attrs, THREADSTACKSIZE);
    if (retc != 0) {
        /* failed to set attributes */
        while (1) {}
    }

    retc = pthread_create(&thread, &attrs, pressureSensorThread, NULL);
    if (retc != 0) {
        /* pthread_create() failed */
        while (1) {}
    }
    retc = pthread_create(&thread2, &attrs, gpsThread, NULL);
    if (retc != 0) {
        /* pthread_create() failed */
        while (1) {}
    }

    retc = pthread_create(&thread3, &attrs, solarTrackerThread, NULL);
    if (retc != 0) {
        /* pthread_create() failed */
        while (1) {}
    }


    /* Start the FreeRTOS scheduler */
    vTaskStartScheduler();

    return (0);
}

//*****************************************************************************
//
//! \brief Application defined malloc failed hook
//!
//! \param  none
//!
//! \return none
//!
//*****************************************************************************
void vApplicationMallocFailedHook()
{
    /* Handle Memory Allocation Errors */
    while(1)
    {
    }
}

//*****************************************************************************
//
//! \brief Application defined stack overflow hook
//!
//! \param  none
//!
//! \return none
//!
//*****************************************************************************
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    //Handle FreeRTOS Stack Overflow
    while(1)
    {
    }
}
