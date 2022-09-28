#@copyright : Ahmed Mostafa
#The INCS is for any header file
# The LIBS for any non standard liberarys and used with linker
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -mthumb -gdwarf-2 -g
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name=lab3_cortex-m4

all: $(Project_name).bin
	@echo "=============Build is Done============="
	
%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c  $< -o $@
	
$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) -o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean-all:
	rm *.bin *.elf *.o

clean:
	rm *.bin *.elf