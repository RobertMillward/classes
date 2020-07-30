//
//  kybd_sketch.cpp
//  MIT License
//
//  Created by Robert Russell Millward on 7/30/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
//#include <stdio.h>
#include "KeypadPhoneABCD.h"

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
            // A change to menu will occur only if requested
            menu_count = menu_count + 1;
            if (menu_count == MENU_RESET) {
                menu_count = MENU_NEW + 1;
            }
            // clear data
            data_count = 0;
        }else{
            // A change to data will occur only if a non-control key was pressed
            
        }
    }
}


/**
 * Sample sketch for the Keyboard as a menu driver and data entry.
 */
