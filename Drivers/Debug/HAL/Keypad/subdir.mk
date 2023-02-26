################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Keypad/keypad.c 

OBJS += \
./HAL/Keypad/keypad.o 

C_DEPS += \
./HAL/Keypad/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Keypad/keypad.o: ../HAL/Keypad/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/LearnInDepthEmbedded/Drivers/Drivers/HAL/inc" -I"D:/LearnInDepthEmbedded/Drivers/Drivers/STM32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Keypad/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

