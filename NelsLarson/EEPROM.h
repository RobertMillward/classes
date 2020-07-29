//
//  EEPROM.h
//  NelsLarsonA
//
//  Created by Robert Russell Millward on 7/28/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef EEPROM_h
#define EEPROM_h

typedef struct EEPROMStruct
{
    void (*write)(int, char);
    int (*read)(int);
}EEPROMT;

extern EEPROMT EEPROM;
extern void delay(int);

#endif /* EEPROM_h */
/**
 * This is a strpped down simulation
 */
