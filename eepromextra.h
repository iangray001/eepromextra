#ifndef __EEPROMEXTRA_H_
#define __EEPROMEXTRA_H_

/* 
Simple utility routines for augmenting the basic Arduino EEPROM library.
Uses the existing Arduino EEPROM library for underlying read and write.
*/

/*
Reads 'size' bytes from EEPROM address 'address' into buf.
*/
void eeprom_read_bytes(int address, int size, char *buf);

/*
Writes 'size' bytes from buf to the EEPROM at address 'address'.
*/
void eeprom_write_bytes(int address, int size, char *buf);

/*
Reads bytes into buf, up the maximum size given, stopping when a \0 is found in the eeprom
Returns the number of bytes read.
*/
int eeprom_read_until_null(int address, int maxsize, char *buf);

/*
Writes bytes from EEPROM address 'address', up to 'maxsize' bytes, stopping when a \0 
is found in buf.
*/
void eeprom_write_until_null(int address, int maxsize, char *buf);

/*
Reads bytes from EEPROM address 'address' into buf, up to 'maxsize' bytes, stopping 
when a non-printable ascii char is read. Returns the number of bytes read.
The resulting string in buf in null-terminated.
*/
int eeprom_read_printable(int address, int maxsize, char *buf);

/*
Writes a 32-bit integer to the given address. Values are stored big-endian.
*/
void eeprom_write_int(int address, int val);

/*
Reads a 32-bit integer from the given address. Values are stored big-endian.
*/
int eeprom_read_int(int address);

#endif
