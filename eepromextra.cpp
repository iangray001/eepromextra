#include <EEPROM.h>
#include "eepromextra.h"

#define ISSTRINGCHAR(c) ((c) >= ' ' && (c) <= '~' && (c) != ',')

void eeprom_read_bytes(int address, int size, char *buf) {
	for(int i = 0; i < size; i++) {
		buf[i] = EEPROM.read(address + i);
	}
}

void eeprom_write_bytes(int address, int size, char *buf) {
	for(int i = 0; i < size; i++) {
		EEPROM.write(address + i, buf[i]);
	}
}

int eeprom_read_until_null(int address, int maxsize, char *buf) {
	int count = 0;
	for(int i = 0; i < maxsize; i++) {
		buf[i] = EEPROM.read(address + i);
		count++;
		if(buf[i] == '\0') break;
	}
	return count;
}

void eeprom_write_until_null(int address, int size, char *buf) {
	for(int i = 0; i < size; i++) {
		EEPROM.write(address + i, buf[i]);
		if(buf[i] == '\0') break;
	}
}

int eeprom_read_printable(int address, int maxsize, char *buf) {
	int count = 0;
	for(int i = 0; i < maxsize; i++) {
		buf[i] = EEPROM.read(address + i);
		count++;
		if(!ISSTRINGCHAR(buf[i])) break;
	}
	return count;
}

void eeprom_write_int(int address, int val) {
	EEPROM.write(address + 0, (unsigned char)((val & 0xFF000000) >> 24));
	EEPROM.write(address + 1, (unsigned char)((val & 0x00FF0000) >> 16));
	EEPROM.write(address + 2, (unsigned char)((val & 0x0000FF00) >> 8));
	EEPROM.write(address + 3, (unsigned char)((val & 0x000000FF) >> 0));
}

int eeprom_read_int(int address) {
	int val = 0;
	unsigned char c;
	for(int i = 0; i < 4; i++) {
		c = EEPROM.read(address + i);
		val = val << 8;
		val = val + (int) c;
	}	
	return val;
}



