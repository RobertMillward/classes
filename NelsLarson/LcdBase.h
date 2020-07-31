//
//  LcdBase.h
//  MIT License
//
//  Created by Robert Russell Millward on 7/30/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef LcdBase_h
#define LcdBase_h
#include "LiquidCrystal_I2C.h"

void lcd_setup(LiquidCrystal_I2C some_lcd)
{
    some_lcd.init();
    some_lcd.backlight();
    some_lcd.home();
}

void lcd_header(LiquidCrystal_I2C some_lcd, char* header)
{
    some_lcd.clear();
    //some_lcd.setCursor(LCDCOL_BEG, LCDNROW_TOP); TODO
    some_lcd.print(header);
}

void lcd_data(LiquidCrystal_I2C some_lcd, int data, int row, int col)
{
    some_lcd.setCursor(col, row);
}


#endif /* LcdBase_h */
/**
 * Basic connections to any LCD 
 */
