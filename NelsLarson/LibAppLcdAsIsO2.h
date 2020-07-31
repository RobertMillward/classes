//
//  LibAppLcdAsIsO2.h
//  Nels Larson
//
//  Created by Robert Russell Millward on 7/30/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef LibAppLcdAsIsO2_h
#define LibAppLcdAsIsO2_h
#include "LibLcdO0.h"

LiquidCrystal_I2C lcd_asis(0x27, 20, 4); // set the address for a 2x16 chars display

bool lcdAsIsRevised = true;

typedef enum lcdAsIsRowEnum
{
    LCDASISROW_TOP = 0,
    LCDASISROW_TMP = 2,
    LCDASISROW_HUM,
    LCDASISROW_CO2
}lcdAsIsRowEnumT;



void lcd_asis_display(int mapped_t, int mapped_h, int mapped_c)
{
    lcd_asis.clear();
    
    lcd_asis.print("Target Temp ");
    lcd_data(lcd_asis, mapped_t, LCDASISROW_TMP, LCDCOL_BEG)(mapped_t);
    
    lcd_asis.print("Target RH ");
    lcd_data(lcd_asis, mapped_h, LCDASISROW_TMP, LCDCOL_BEG)(mapped_h);
    
    lcd_asis.print("Target CO2 ");
    lcd_data(lcd_asis, mapped_t, LCDASISROW_TMP, LCDCOL_BEG)(mapped_c);
}

#endif /* LibAppLcdAsIsO2_h */
/**
 * Application
 */
