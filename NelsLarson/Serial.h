//
//  Serial.h
//  NelsLarsonA
//
//  Created by Robert Russell Millward on 7/28/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef Serial_h
#define Serial_h

typedef struct SerialStruct
{
    void begin(int);
    void println(void);
}SerialT;

extern SerialT Serial;


#endif /* Serial_h */
/**
 * This is a stripped down simulation
 */
