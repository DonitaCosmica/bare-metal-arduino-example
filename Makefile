
# Makefile para compilar y programar el código en un Arduino Uno

# Nombre del archivo fuente
SOURCE = motor.c
LIBRARY = lib.c

# Configuración del programador
PROGRAMMER = arduino
PORT = /dev/ttyACM0

# Opciones de compilación
CC = avr-gcc
OBJCOPY = avr-objcopy
MMCU = atmega328p
F_CPU = 16000000UL
CFLAGS = -Os -DF_CPU=$(F_CPU) -mmcu=$(MMCU)
LDFLAGS = -mmcu=$(MMCU)
FLAGS = -Wall -c -o

# Nombre del archivo de salida
OUTPUT = motor
OUTLIB = lib

# Directorio de salida para los archivos generados
BUILD_DIR = build

all: create_build_folder $(BUILD_DIR)/$(OUTPUT).hex

$(BUILD_DIR)/$(OUTPUT).hex: $(BUILD_DIR)/$(OUTPUT).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

$(BUILD_DIR)/$(OUTPUT).elf: $(BUILD_DIR)/motor.o $(BUILD_DIR)/lib.o
	$(CC) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/$(OUTPUT).o: $(SOURCE)
	$(CC) $(CFLAGS) $(FLAGS) $@ $<

$(BUILD_DIR)/$(OUTLIB).o: $(LIBRARY)
	$(CC) $(CFLAGS) $(FLAGS) $@ $<

flash: $(BUILD_DIR)/$(OUTPUT).hex
	avrdude -c $(PROGRAMMER) -p $(MMCU) -P $(PORT) -U flash:w:$<

create_build_folder:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all flash create_build_folder clean
