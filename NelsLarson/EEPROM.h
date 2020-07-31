//
//  EEPROM.h
//  NelsLarsonA
//
//  Created by Robert Russell Millward on 7/31/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef EEPROM_h
#define EEPROM_h


typedef struct EEPROMStruct
{
    void (*write)(int offset, char data);
    void (*update)(int offset, char data);
    int (*read)(int offset);
}EEPROMT;

extern EEPROMT EEPROM;

extern void delay(int);

#endif /* EEPROM_h */
/**
 * A simultion
 */
