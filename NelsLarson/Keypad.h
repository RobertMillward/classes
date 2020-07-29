//
//  Keypad.h
//  NelsLarsonA
//
//  Created by Robert Russell Millward on 7/28/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef Keypad_h
#define Keypad_h

class Keypad
{
public:
    Keypad( int mkKeymap, int pin_rows, int pin_column, int ROW_NUM, int COLUMN_NUM );
    
    void (*init)(void);
    char (*getKey)(void);
private:
};

extern int makeKeymap(char[4][4]);

#endif /* Keypad_h */
/**
 * This is a stripped down simulation
 */
