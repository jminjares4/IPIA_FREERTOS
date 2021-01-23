################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../MSP_EXP432P401R_FREERTOS.cmd 

SYSCFG_SRCS += \
../ipia.syscfg 

C_SRCS += \
../GPS.c \
../PressureSensor.c \
../SG90.c \
../bluetooth.c \
../gpsTimer.c \
../ipia.c \
./syscfg/ti_drivers_config.c \
../main_freertos.c \
../sim33eau.c 

GEN_FILES += \
./syscfg/ti_drivers_config.c 

GEN_MISC_DIRS += \
./syscfg/ 

C_DEPS += \
./GPS.d \
./PressureSensor.d \
./SG90.d \
./bluetooth.d \
./gpsTimer.d \
./ipia.d \
./syscfg/ti_drivers_config.d \
./main_freertos.d \
./sim33eau.d 

OBJS += \
./GPS.obj \
./PressureSensor.obj \
./SG90.obj \
./bluetooth.obj \
./gpsTimer.obj \
./ipia.obj \
./syscfg/ti_drivers_config.obj \
./main_freertos.obj \
./sim33eau.obj 

GEN_MISC_FILES += \
./syscfg/ti_drivers_config.h \
./syscfg/syscfg_c.rov.xs 

GEN_MISC_DIRS__QUOTED += \
"syscfg\" 

OBJS__QUOTED += \
"GPS.obj" \
"PressureSensor.obj" \
"SG90.obj" \
"bluetooth.obj" \
"gpsTimer.obj" \
"ipia.obj" \
"syscfg\ti_drivers_config.obj" \
"main_freertos.obj" \
"sim33eau.obj" 

GEN_MISC_FILES__QUOTED += \
"syscfg\ti_drivers_config.h" \
"syscfg\syscfg_c.rov.xs" 

C_DEPS__QUOTED += \
"GPS.d" \
"PressureSensor.d" \
"SG90.d" \
"bluetooth.d" \
"gpsTimer.d" \
"ipia.d" \
"syscfg\ti_drivers_config.d" \
"main_freertos.d" \
"sim33eau.d" 

GEN_FILES__QUOTED += \
"syscfg\ti_drivers_config.c" 

C_SRCS__QUOTED += \
"../GPS.c" \
"../PressureSensor.c" \
"../SG90.c" \
"../bluetooth.c" \
"../gpsTimer.c" \
"../ipia.c" \
"./syscfg/ti_drivers_config.c" \
"../main_freertos.c" \
"../sim33eau.c" 

SYSCFG_SRCS__QUOTED += \
"../ipia.syscfg" 


