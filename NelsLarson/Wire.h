//
//  Wire.h
//  NelsLarsonA
//
//  Created by Robert Russell Millward on 7/28/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef Wire_h
#define Wire_h

typedef struct WireStruct
{
    void (*begin)(void);
}WireT;

extern WireT Wire;


#endif /* Wire_h */
/**
 * This is a stripped down simulation
 */
