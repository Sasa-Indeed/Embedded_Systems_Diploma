################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DoorLock_AUTOSAR_Implementation/DoorLock_Indication_SWC.c \
../DoorLock_AUTOSAR_Implementation/DoorSensorAbstractionSWC.c 

OBJS += \
./DoorLock_AUTOSAR_Implementation/DoorLock_Indication_SWC.o \
./DoorLock_AUTOSAR_Implementation/DoorSensorAbstractionSWC.o 

C_DEPS += \
./DoorLock_AUTOSAR_Implementation/DoorLock_Indication_SWC.d \
./DoorLock_AUTOSAR_Implementation/DoorSensorAbstractionSWC.d 


# Each subdirectory must supply rules for building sources it contributes
DoorLock_AUTOSAR_Implementation/%.o DoorLock_AUTOSAR_Implementation/%.su DoorLock_AUTOSAR_Implementation/%.cyclo: ../DoorLock_AUTOSAR_Implementation/%.c DoorLock_AUTOSAR_Implementation/subdir.mk
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Learn_In_Depth/AUTOSAR/Unit 3 AUTOSAR SW LAYER/Project/DoorLock_Code/DoorLock_AUTOSAR_Project/DoorLock_AUTOSAR_Implementation/AUTOSAR_include_files" -I"D:/Learn_In_Depth/AUTOSAR/Unit 3 AUTOSAR SW LAYER/Project/DoorLock_Code/DoorLock_AUTOSAR_Project/HAL/includes" -I"D:/Learn_In_Depth/AUTOSAR/Unit 3 AUTOSAR SW LAYER/Project/DoorLock_Code/DoorLock_AUTOSAR_Project/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-DoorLock_AUTOSAR_Implementation

clean-DoorLock_AUTOSAR_Implementation:
	-$(RM) ./DoorLock_AUTOSAR_Implementation/DoorLock_Indication_SWC.cyclo ./DoorLock_AUTOSAR_Implementation/DoorLock_Indication_SWC.d ./DoorLock_AUTOSAR_Implementation/DoorLock_Indication_SWC.o ./DoorLock_AUTOSAR_Implementation/DoorLock_Indication_SWC.su ./DoorLock_AUTOSAR_Implementation/DoorSensorAbstractionSWC.cyclo ./DoorLock_AUTOSAR_Implementation/DoorSensorAbstractionSWC.d ./DoorLock_AUTOSAR_Implementation/DoorSensorAbstractionSWC.o ./DoorLock_AUTOSAR_Implementation/DoorSensorAbstractionSWC.su

.PHONY: clean-DoorLock_AUTOSAR_Implementation

