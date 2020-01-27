//
//  HomeWorkHelper.h
//  General
//
//  Created by Robert Millward on 9/29/14.
//  Copyright (c) 2014 Robert Millward. All rights reserved.
//
// Columbia Basin College wanted the chapter report to be in a
// specific format which this helper facilitated.

#ifndef __HomeWorkHelper__
#define __HomeWorkHelper__

#include <stdio.h>
#include <string> 
#include <fstream>
using namespace std;

// Pass this in to the final call to newChallenge().
// Be sure to change the const string chap in the cpp file for each chapter.
// Be sure to set the two paths to fit your host.
extern const string HW_SAVER_CLOSE;

// In case you need to put content into the homework file.
// This is available from immediately after the first call to
// newChallenge() until just before the final call to newChallenge().
extern ofstream homeWorkFile;

typedef struct HomeWorkSaverY
{
    void(*newChallenge)(string nbr);
    void(*saveDollars)(string title, float dollars);
    void(*saveFloat)(string title, int precision, float value);
    void(*saveInt)(string title, int value);
    void(*saveString)(string title, string value);
    void(*saveIntString)(int title, string value);
    void(*saveIntFloat)(int title, int precision,float value);
}HomeWorkSaverX;

extern HomeWorkSaverX HmWrkSavr;

#endif /* defined(__HomeWorkHelper__) */
