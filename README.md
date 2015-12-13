# EEPROMExtra

A simple utility library that contains routines for augmenting the basic Arduino EEPROM library.


## Description
The standard Arduino EEPROM library only provides single byte read and write. This library adds useful utility functions to access other data types. It is written to be as lightweight as possible, and so does not provide any more exotic features such as wear levelling or individual bit manipulation.

For a more complete solution to this problem, check out the EEPROMEx library which can be accessed through the Library Manager in the Arduino IDE.

Uses the existing Arduino EEPROM library for underlying read and write.

## Installation
To use this in your Arduino sketches you need to add it to your Arduino libraries. First, navigate to your Arduinio libraries:

On Linux or OS X: `~/Documents/Arduino/libraries/`

On Windows: `My Documents\Arduino\libraries\`

And check out the repo there:

    git clone git@github.com:iangray001/eepromextra.git

If you are using the Arduino IDE you will need to restart it.
