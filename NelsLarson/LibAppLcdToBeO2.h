//
//  LibAppLcdToBeO2.h
//  Nels Larson
//
//  Created by Robert Russell Millward on 7/30/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef LibLcdToBeO2_h
#define LibLcdToBeO2_h
#include "LibLcdO0.h"

LiquidCrystal_I2C lcd_tobe(0x27, 20, 4); // set the address for a 2x16 chars display

#define LCDTOBEROW_TOP 0

typedef enum lcdToBeColEnum
{
    LCDTOBECOL_TMP = LCDCOL_BEG,
    LCDTOBECOL_HUM,
    LCDTOBECOL_CO2
}lcdToBeColEnumT;


void printMenuHeader(int menu_count)
{
    lcd_tobe.clear();
    lcd_tobe.setCursor(LCDCOL_BEG, LCDTOBEROW_TOP);
    
    switch(menu_count)
    {
        case MENU_TMP: lcd_tobe.print("Set TEMP :");      break;
        case MENU_HUM: lcd_tobe.print("Set humidity :");  break;
        case MENU_CO2: lcd_tobe.print("Set CO2 :");       break;
    }
}

void printMenuFooter(int menu_count)
{
    lcd_tobe.clear();
    lcd_tobe.setCursor(LCDCOL_BEG, LCDTOBEROW_TOP); // This matches the sent code:
    switch(menu_count)
    {
        case MENU_TMP: lcd_tobe.print("Done setting TEMP");      break;
        case MENU_HUM: lcd_tobe.print("Done setting humidity");  break;
        case MENU_CO2: lcd_tobe.print("Done setting CO2");       break;
    }
    
    delay(1000);
}


#endif /* LibAppLcdToBeO2_h */
/**
 * Application
 */
