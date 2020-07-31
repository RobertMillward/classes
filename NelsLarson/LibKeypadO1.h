//
//  LibKeypadO1.h
//  MIT License
//
//  Created by Robert Russell Millward on 7/30/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef LibKeypadO1_h
#define LibKeypadO1_h

Keypad keypad = Keypad( makeKeymap(kypd_keys),
                       kypd_pin_rows,
                       kypd_pin_cols,
                       KYPD_ROWS,
                       KYPD_COLS );

char kypd_pressed = 0;
char Data[5];
int data_count = 0;

typedef enum menuEnum
{
    MENU_NEW = 0,
    MENU_TMP,
    MENU_HUM,
    MENU_CO2,
    MENU_RESET
}menuEnumT;
int menu_count = MENU_NEW;


void getNextMenuDown()
{
    menu_count = menu_count + 1;
    if (menu_count == MENU_RESET) {
        menu_count = MENU_NEW + 1;
    }
    // clear data
    data_count = 0;
}

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


#endif /* LibKeypadO1_h */
/**
 * Finish the given Keypad with a common interface for version O (2020) <sku series 1>
 * Start with Level 0.
 */
