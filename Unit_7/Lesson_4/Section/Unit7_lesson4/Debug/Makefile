################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../Debug/ \
../Debug/HAL/ \
../Debug/HAL/inc/ \
../Debug/HAL/LCD/ \
../Debug/MCAL/ \
../Debug/MCAL/GPIO/ \
../Debug/MCAL/inc/ \
../HAL/ \
../HAL/inc/ \
../HAL/LCD/ \
../MCAL/ \
../MCAL/GPIO/ \
../MCAL/inc/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../HAL/LCD/lcd.c \
../main.c \
../MCAL/GPIO/AVR_ATMEGA32_GPIO.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
HAL/LCD/lcd.o \
main.o \
MCAL/GPIO/AVR_ATMEGA32_GPIO.o

OBJS_AS_ARGS +=  \
HAL/LCD/lcd.o \
main.o \
MCAL/GPIO/AVR_ATMEGA32_GPIO.o

C_DEPS +=  \
HAL/LCD/lcd.d \
main.d \
MCAL/GPIO/AVR_ATMEGA32_GPIO.d

C_DEPS_AS_ARGS +=  \
HAL/LCD/lcd.d \
main.d \
MCAL/GPIO/AVR_ATMEGA32_GPIO.d

OUTPUT_FILE_PATH +=AVR_Drivers.elf

OUTPUT_FILE_PATH_AS_ARGS +=AVR_Drivers.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
HAL/LCD/lcd.o: ../HAL/LCD/lcd.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\LearnInDepthEmbedded\Tools\AVR_studio\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\LearnInDepthEmbedded\Tools\AVR_studio\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\include" -I"../HAL/inc" -I"../HAL/LCD" -I"../MCAL/GPIO" -I"../MCAL/inc"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "D:\LearnInDepthEmbedded\Tools\AVR_studio\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\LearnInDepthEmbedded\Tools\AVR_studio\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\LearnInDepthEmbedded\Tools\AVR_studio\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\include" -I"../HAL/inc" -I"../HAL/LCD" -I"../MCAL/GPIO" -I"../MCAL/inc"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "D:\LearnInDepthEmbedded\Tools\AVR_studio\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

MCAL/GPIO/AVR_ATMEGA32_GPIO.o: ../MCAL/GPIO/AVR_ATMEGA32_GPIO.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\LearnInDepthEmbedded\Tools\AVR_studio\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\LearnInDepthEmbedded\Tools\AVR_studio\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\include" -I"../HAL/inc" -I"../HAL/LCD" -I"../MCAL/GPIO" -I"../MCAL/inc"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "D:\LearnInDepthEmbedded\Tools\AVR_studio\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)D:\LearnInDepthEmbedded\Tools\AVR_studio\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="AVR_Drivers.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 -B "D:\LearnInDepthEmbedded\Tools\AVR_studio\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32"  
	@echo Finished building target: $@
	"D:\LearnInDepthEmbedded\Tools\AVR_studio\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "AVR_Drivers.elf" "AVR_Drivers.hex"
	"D:\LearnInDepthEmbedded\Tools\AVR_studio\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "AVR_Drivers.elf" "AVR_Drivers.eep" || exit 0
	"D:\LearnInDepthEmbedded\Tools\AVR_studio\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "AVR_Drivers.elf" > "AVR_Drivers.lss"
	"D:\LearnInDepthEmbedded\Tools\AVR_studio\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "AVR_Drivers.elf" "AVR_Drivers.srec"
	"D:\LearnInDepthEmbedded\Tools\AVR_studio\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "AVR_Drivers.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "AVR_Drivers.elf" "AVR_Drivers.a" "AVR_Drivers.hex" "AVR_Drivers.lss" "AVR_Drivers.eep" "AVR_Drivers.map" "AVR_Drivers.srec" "AVR_Drivers.usersignatures"
	