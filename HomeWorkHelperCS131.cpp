//
//  HomeWorkHelper.cpp
//  General
//
//  Created by Robert Millward on 9/29/14.
//  Copyright (c) 2014 Robert Millward. All rights reserved.
//

#include <iomanip>
using namespace std;
#include "HomeWorkHelper.h"

/*
 Utility to output homework to a file.
 */
const string HW_SAVER_CLOSE = "99";
ofstream homeWorkFile;
#define HW_SAVER_LEFT_WIDTH 20
#define HW_SAVER_RIGHT_WIDTH 9
static const string chap = "7";
/**
 * Location of data files.
 */
static const string dataFileLocationWithSlash = "/Users/sbcbob/Downloads/Programs/Ch_0" + chap + "/";
static const string chapOutSlash = "/Users/Shared/Desktop/";

static void utilityHomeWorkSaver(string challengeNbr)
{
    static bool isSaverOpen = false;
    
    if(! isSaverOpen)
    {
        // The file is HWu to identify it as UNIX line feeds.
        string fileName = chapOutSlash + "MillwardCh" + chap + "HWu.txt";
        homeWorkFile.open(fileName.c_str());
        homeWorkFile << "Robert Millward" << "\n";
        homeWorkFile << "   Chapter: " << chap << "\n";
        homeWorkFile << "   Date   : October 08, 2014\n";
        homeWorkFile << endl << "<Replace with program>\n\n";
        
        isSaverOpen = true;
    }
    
    if(challengeNbr == HW_SAVER_CLOSE)
    {
        homeWorkFile.close();
    }
    else
    {
        homeWorkFile << "\n" << "Programming Challenge # " << challengeNbr << "\n";
    }
}


// Note lowercase Homework for these two inline functions...
static void utilityHomeworkSaveName(string name)
{
    homeWorkFile << left << setw(HW_SAVER_LEFT_WIDTH) << name << ": ";
}


static void utilityHomeworkSaveFloat(int precision, float value)
{
    homeWorkFile << right << setw(HW_SAVER_RIGHT_WIDTH) << fixed << showpoint
    << setprecision(precision) << value;
}


/**
 * The output looks like
 * <what is in the name   >$ 3000.00
 * The value will be right aligned.
 * The value will not go exponential because it is fixed.
 * The decimal point will always appear along with 2
 */
static void utilityHomeWorkSaveDollars(string name, float dollars)
{
    utilityHomeworkSaveName(name);
    
    homeWorkFile << "$";
    
    utilityHomeworkSaveFloat(2, dollars);
    
    homeWorkFile << "\n";
    
}

/*
 * The output looks like
 * <what is in the name      >3.0000
 * The value will be right aligned.
 * The value will not go exponential because it is fixed.
 * The decimal point will always appear along with the caller specified precision.
 */
static void utilityHomeWorkSaveFloat(string name, int precision, float value)
{
    utilityHomeworkSaveName(name);
    
    utilityHomeworkSaveFloat(precision, value);
    
    homeWorkFile << "\n";
}


static void utilityHomeWorkSaveInt(string name, int value)
{
    utilityHomeworkSaveName(name);
    
    homeWorkFile << right << setw(HW_SAVER_RIGHT_WIDTH - 5) << value << "\n";
}


static void utilityHomeWorkSaveString(string name, string value)
{
    utilityHomeworkSaveName(name);
    
    homeWorkFile << left << setw(HW_SAVER_LEFT_WIDTH) << value << "\n";
}



static void utilityHomeWorkSaveIntString(int ix, string value)
{
    homeWorkFile << left << setw(HW_SAVER_LEFT_WIDTH) << ix << ": "
    << left << setw(HW_SAVER_LEFT_WIDTH)
    << value << endl;
}




static void utilityHomeWorkSaveIntFloat(int ix, int precision, float value)
{
    homeWorkFile << left << setw(HW_SAVER_LEFT_WIDTH) << ix << ": ";
    
    utilityHomeworkSaveFloat(precision, value);
    
    homeWorkFile << "\n";
}


HomeWorkSaverX HmWrkSavr =
{
    utilityHomeWorkSaver,
    utilityHomeWorkSaveDollars,
    utilityHomeWorkSaveFloat,
    utilityHomeWorkSaveInt,
    utilityHomeWorkSaveString,
    utilityHomeWorkSaveIntString,
    utilityHomeWorkSaveIntFloat
};