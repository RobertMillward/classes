//
//  NelsLO.cpp (???)
//  NelsLarson - version [O]riginal
//
//  Created by Robert Russell Millward on 7/30/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#include "Serial.h"
#include "LibEEPROMO0.h"
#include "LibKeypadO0.h"
#include "LibAppLcdAsIsO2.h"
#include "LibAppLcdToBeO2.h"

/**
 * The values from the keypad or initially the EEPROM
 */
int mapped_t = 100;
int mapped_c = 1000;
int mapped_h = 100;

void setup()
{
    Serial.begin(9600);
    lcd_setup(lcd_asis);
    Serial.println("SCD30 USAGE T, RH, CO2");
    Wire.begin();
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
}

void displayAsIs()
{
    mapped_t = EEPROM.read(LCDTOBECOL_TMP);
    mapped_h = EEPROM.read(LCDTOBECOL_HUM);
    mapped_c = EEPROM.read(LCDTOBECOL_CO2);
    
    lcd_asis_display(mapped_t, mapped_h, mapped_c);

    delay(100);
}

void processUserKeyInput(int menu_count)
{
    printMenuHeader(menu_count);
    
    Data[data_count] = kypd_pressed; // store char into data array
                                  // TODO: might the LCD1ROW_DTA below be epromCol?
    lcd_tobe.setCursor(data_count, LCDTOBEROW_DTA); // move cursor to show each new char
    lcd_tobe.print(Data[data_count]); // print char at said cursor
    data_count++; // increment data array by 1 to store new char, also keep track of the number of chars entered
    
    if (isUserKeyEnter())
    {
        int epromCol = -1;
        switch(menu_count)
        {
            case MENU_TMP:
                mapped_t = Data[data_count];
                epromCol = LCDTOBECOL_TMP;
                break;
            case MENU_HUM:
                mapped_h = Data[data_count];
                epromCol = LCDTOBECOL_HUM;
                break;
            case MENU_CO2:
                mapped_c = Data[data_count];
                epromCol = LCDTOBECOL_CO2;
                break;
        }
        EEPROM.write(epromCol, Data[data_count]); // TODO: update
        
        printMenuFooter(menu_count);

        lcdAsIsRevised = true;
    }
}

void loop()
{    // Any time that the mapped_? data has been refreshed then repaint the lcd
    if (lcdAsIsRevised) {
        displayAsIs();
        lcdAsIsRevised = false;
    }
    
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
            processUserKeyInput(menu_count);
        }
    }else{
        delay(200); // key presses could be weeks apart.
    }
}

/**
 * This version blah blah blah
 */
