//
//  EdAppKeypadO1.cpp
//  MIT License
//
//  Created by Robert Russell Millward on 7/30/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#include "LibKeypadO0.h"

void processUserKeyInput(int menu_count)
{
    
}

void setup()
{
    
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
            processUserKeyInput(menu_count);
        }
    }else{
        delay(200); // key presses could be weeks apart.
    }
}


/**
 * Educational application for Keypad version O (2020) <sku series 1>
 * Sample sketch for the Keyboard as a menu driver and data entry.
 */
