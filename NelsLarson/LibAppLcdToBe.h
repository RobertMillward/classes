//
//  LcdToBe.h
//  Nels Larson
//
//  Created by Robert Russell Millward on 7/30/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef LcdToBe_h
#define LcdToBe_h
#include "LcdBase.h"

LiquidCrystal_I2C lcd_tobe(0x27, 20, 4); // set the address for a 2x16 chars display

typedef enum lcdColEnum
{
    LCDCOL_TMP = LCDCOL_BEG,
    LCDCOL_HUM,
    LCDCOL_CO2
}lcdColEnumT;


#endif /* LcdToBe_h */
/**
 * Application
 */
