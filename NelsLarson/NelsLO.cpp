//
//  NelsLO.cpp (???)
//  NelsLarson - version [O]riginal
//
//  Created by Robert Russell Millward on 7/30/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#include "Serial.h"
#include "KeypadPhoneABCD.h"
#include "LcdAsIs.h"
#include "LcdToBe.h"

void setup()
{
    Serial.begin(9600);
    lcd_setup(lcd_asis);
    Serial.println("SCD30 USAGE T, RH, CO2");
//    Wire.begin();
//    if (airSensor.begin() == false)
//    {
        Serial.println("Air sensor not detected. Please check wiring. Freezing...");
//        while (1)
//        ;
//    }
//
//    pinMode(relay_co2, OUTPUT);// set relay pin as output
//    pinMode(relay_hum, OUTPUT);// set relay pin as output
//    pinMode(relay_temp, OUTPUT);// set relay pin as output
//    //The SCD30 has data ready every two seconds
//    mapped_t = EEPROM.read(LCDCOL_TMP);
//    mapped_h = EEPROM.read(LCDCOL_HUM);
//    mapped_c = EEPROM.read(LCDCOL_CO2);
}

void loop()
{
    getUserKey();
    // A change will occur only if a key was pressed
    if(isUserKeyPresent())
    {
        if(isUserKeyMenuDown())
        {
            // A change to menu will occur when ewquested
            getNextMenuDown();
        }else{
            // A change to data will occur only if a non-control key was pressed
            // processUserKeyInput(menu_count);
        }
    }else{
        delay(200); // key presses could be weeks apart.
    }
}

/**
 * This version blah blah blah
 */
