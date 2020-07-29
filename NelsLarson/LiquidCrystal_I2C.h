//
//  LiquidCrystal_I2C.h
//  NelsLarsonA
//
//  Created by Robert Russell Millward on 7/28/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef LiquidCrystal_I2C_h
#define LiquidCrystal_I2C_h
#define LIQUIDCRYSTAL_I2C_VERSION "LiquidCrystal_I2C s.i.m"

#include "Serial.h"
//#include <inittypes.h> need to get byte, try this
typedef unsigned char byte;
typedef unsigned char uint8_t;

#define LCD_5x8DOTS 0x00

class LiquidCrystal_I2C
{
public:
    LiquidCrystal_I2C(uint8_t addr, uint8_t cols, uint8_t rows);
    void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);
    
    void (*init)(void);
    void (*backlight)(void);
    void (*home)(void);
    void (*clear)(void);
    void (*setCursor)(int col, int row);
    void (*print)(char const *);
private:
};

#define OUTPUT 1
extern void pinMode(int, int tofrom);



#endif /* LiquidCrystal_I2C_h */
/**
 * This is a stripped down simulation
 */
