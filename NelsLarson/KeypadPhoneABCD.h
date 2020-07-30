//
//  KeypadPhoneABCD.h
//  NelsLarsonA
//
//  Created by Robert Russell Millward on 7/30/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef KeypadPhoneABCD_h
#define KeypadPhoneABCD_h
#include "Keypad.h"

typedef unsigned char byte; // TODO: resolve

#define KYPD_MNUDN '#'
#define KYPD_ENTER '*'
#define KYPD_ROWS 4 //four rows
#define KYPD_COLS 4 //four columns
byte kypd_pin_rows[KYPD_ROWS] = {9, 8, 7, 6}; // row pinouts of the keypad
byte kypd_pin_cols[KYPD_COLS] = {5, 4, 3, 2}; // column pinouts of the keypad
char kypd_keys[KYPD_ROWS][KYPD_COLS] =
{
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {KYPD_ENTER, '0', KYPD_MNUDN, 'D'}
};
#define KYPD_COL_CHARS 2
#define KYPD_ROW_CHARS 3
#define KYPD_COL_ENTER 0
#define KYPD_COL_MNUDN 2

#include "KeyPadFinish.h"

#endif /* KeypadPhoneABCD_h */
/**
 * A phone pad plus a column of A, B, C, D
 */
