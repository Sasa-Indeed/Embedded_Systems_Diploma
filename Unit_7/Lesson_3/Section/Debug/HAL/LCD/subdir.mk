################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD/lcd.c 

OBJS += \
./HAL/LCD/lcd.o 

C_DEPS += \
./HAL/LCD/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD/lcd.o: ../HAL/LCD/lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/LearnInDepthEmbedded/Unit_7(MCU_Essential_Peripherals)/Assignments/Assignment_4/Code/Lesson_4/HAL/inc" -I"D:/LearnInDepthEmbedded/Unit_7(MCU_Essential_Peripherals)/Assignments/Assignment_4/Code/Lesson_4/STM32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

