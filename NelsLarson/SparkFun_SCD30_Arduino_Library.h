//
//  SparkFun_SCD30_Arduino_Library.h
//  NelsLarsonA
//
//  Created by Robert Russell Millward on 7/28/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//

#ifndef SparkFun_SCD30_Arduino_Library_h
#define SparkFun_SCD30_Arduino_Library_h

#include "Wire.h" // is a <> file in reality, not quotes file

class SCD30
{
public:
    SCD30(void);
    
    bool begin(void);
private:
    float co2 = 0;
};

#endif /* SparkFun_SCD30_Arduino_Library_h */

/**
 * This is a stripped down simulation
 */
