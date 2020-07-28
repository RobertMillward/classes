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
    void (*init)(void);
    char (*getKey)(void);
private:
};

#endif /* Keypad_h */
/**
 * This is a stripped down simulation
 */
