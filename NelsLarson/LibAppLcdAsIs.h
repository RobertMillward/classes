//
//  LibAppLcdAsIs.h
//  Nels Larson
//
//  Created by Robert Russell Millward on 7/30/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef LibAppLcdAsIs_h
#define LibAppLcdAsIs_h
#include "LcdBase.h"

LiquidCrystal_I2C lcd_asis(0x27, 20, 4); // set the address for a 2x16 chars display

bool lcdAsIsUpdated = true;

typedef enum lcdMultiRowEnum
{
    LCDNROW_TOP = 0,
    LCDNROW_TMP = 2,
    LCDNROW_HUM,
    LCDNROW_CO2
}lcdManyRowEnumT;



void lcd_asis_display(int mapped_t, int mapped_h, int mapped_c)
{
    lcd_asis.clear();
    
    lcd_asis.print("Target Temp ");
    lcd_data(lcd_asis, mapped_t, LCDNROW_TMP, LCDCOL_BEG)(mapped_t);
    
    lcd_asis.print("Target RH ");
    lcd_data(lcd_asis, mapped_h, LCDNROW_TMP, LCDCOL_BEG)(mapped_h);
    
    lcd_asis.print("Target CO2 ");
    lcd_data(lcd_asis, mapped_t, LCDNROW_TMP, LCDCOL_BEG)(mapped_c);
}

#endif /* LibAppLcdAsIs_h */
/**
 * Application
 */
