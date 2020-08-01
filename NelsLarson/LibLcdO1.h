//
//  LibLcdO1.h
//  MIT License
//
//  Created by Robert Russell Millward on 7/30/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef LibLcdO1_h
#define LibLcdO1_h
static int LIBLCD01;
#define LCDCOL_BEG 0

void lcd_setup(LiquidCrystal_I2C some_lcd)
{
    some_lcd.init();
    some_lcd.backlight();
    some_lcd.home();
}

void lcd_header(LiquidCrystal_I2C some_lcd, int row, char* header)
{
    some_lcd.clear();
    some_lcd.setCursor(LCDCOL_BEG, row);
    some_lcd.print(header);
}

void lcd_data(LiquidCrystal_I2C some_lcd, int data, int row, int col)
{
    some_lcd.setCursor(col, row);
    char asciiOut[20] = "not";
//    sprintf(asciiOut, "%d", data); TODO:
    some_lcd.print(asciiOut);
}


#endif /* LibLcdO1_h */
/**
 * Basic connections to any LCD
 * Start with level 0.
 */
