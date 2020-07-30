//
//  KeypadFinish.h
//  MIT License
//
//  Created by Robert Russell Millward on 7/30/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef KeypadFinish_h
#define KeypadFinish_h

Keypad keypad = Keypad( makeKeymap(kypd_keys),
                       kypd_pin_rows,
                       kypd_pin_cols,
                       KYPD_ROWS,
                       KYPD_COLS );

char kypd_pressed = 0;

void getUserKey()
{
    kypd_pressed = keypad.getKey();
}

bool isUserKeyPresent()
{
    return kypd_pressed != 0;
}

bool isUserKeyEnter()
{
    return kypd_pressed == kypd_keys[KYPD_ROW_CHARS][KYPD_COL_ENTER];
}

bool isUserKeyMenuDown()
{
    return kypd_pressed == kypd_keys[KYPD_ROW_CHARS][KYPD_COL_MNUDN];
}


#endif /* KeypadFinish_h */
/**
 * Finish the given Keypad
 */
