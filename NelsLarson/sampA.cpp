
//#include <Wire.h>
//#include <LiquidCrystal_I2C.h>
// -- #include <Wire.h>
#include "SparkFun_SCD30_Arduino_Library.h" //Click here to get the library:
                                    // http://librarymanager/All#SparkFun_SCD30
//#include <EEPROM.h>
//#include <Keypad.h>
#include "EEPROM.h"
#include "Keypad.h"
#include "LiquidCrystal_I2C.h"

/*
 * Unused values

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args) print(args,BYTE);
#endif
bool temps = HIGH;
int hum = HIGH;
unsigned int AnalogValue;
double deadbandUp = 0;
double deadbandDown = 0;
double calc = 0;
bool bloop = false;
bool once = true;
String input_password = "1000";
String password = "1000";
char key = 'A';
char keyA = ' ';


int Read = LOW;
byte master_count = 0;
 */

typedef enum relayEnum
{
    relay_co2 = 10,
    relay_hum,
    relay_temp
}relay;

bool aloop = true;
char keyB = ' ';
int menu_count = 0;
int value_set1 = 0;
bool done_save = true;
char Data[5];
byte data_count = 0;

int mapped_t = 100;
int mapped_c = 1000;
int mapped_h = 100;

SCD30 airSensor;
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display


const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns
byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
char keys[ROW_NUM][COLUMN_NUM] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};
Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

void setup()
{
    Serial.begin(9600);
    lcd.init();         // initialize the lcd
    lcd.backlight();
    lcd.home();
    Serial.println("SCD30 USAGE T, H, CO2");
    Wire.begin();
    if (airSensor.begin() == false)
    {
        Serial.println("Air sensor not detected. Please check wiring. Freezing...");
        while (1)
        ;
    }
#define OUTPUT 999
    pinMode(relay_co2, OUTPUT);// set relay pin as output
    pinMode(relay_hum, OUTPUT);// set relay pin as output
    pinMode(relay_temp, OUTPUT);// set relay pin as output
    //The SCD30 has data ready every two seconds
    mapped_t = EEPROM.read(0);
    mapped_h = EEPROM.read(1);
    mapped_c = EEPROM.read(2);
}

typedef enum menuEnum
{
    MENU_TMP = 1,
    MENU_HUM,
    MENU_CO2,
    MENU_RESET
}menuEnumT;

typedef enum lcdEnum
{
    LCD_TMP = 0,
    LCD_HUM,
    LCD_CO2
}lcdEnumT;

void processKeypadInput(int menu_count)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    
    int epromCol = -1;
    string menuName = "xxx";
    
    switch(menu_count)
    {
        case MENU_TMP:
            menuName = "TEMP";
            epromCol = 0;
            break;
        case MENU_HUM:
            menuName = "humidity";
            epromCol = 1;
            break;
        case MENU_CO2:
            menuName = "CO2";
            epromCol = 2;
            break;
    }
    lcd.print("Set " + menuName + ": ");
    
    char customKey = keypad.getKey();
    if (customKey) // makes sure a key is actually pressed, equal to (customKey != NO_KEY)
    {
        Data[data_count] = customKey; // store char into data array
        lcd.setCursor(data_count, 1); // move cursor to show each new char
        lcd.print(Data[data_count]); // print char at said cursor
        data_count++; // increment data array by 1 to store new char, also keep track of the number of chars entered
        
    }
    if (customKey == '*') // if the array index is equal to the number of expected chars, compare data to master
    {
        EEPROM.write(epromCol, Data);
        switch(menu_count)
        {
            case MENU_TMP: mapped_t = Data; break;
            case MENU_HUM: mapped_h = Data; break;
            case MENU_CO2: mapped_c = Data; break;
        }
        lcd.clear();
        lcd.setCursor(0, 0); // This matches the sent code:
        lcd.print("done setting for " + menuName);
        delay(1000);
        value_set1 = false;
        done_save = true;
        aloop = true;
    }
}

void loop()
{
    if (aloop) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Target Temp ");
        lcd.print(mapped_t);
        lcd.setCursor(0, 1);
        lcd.print("Target RH ");
        lcd.print(mapped_h);
        lcd.setCursor(0, 2 );
        lcd.print("Target CO2 ");
        lcd.print(mapped_c);
        delay(100);
        aloop = false;
    }
    
    keyB = keypad.getKey();
    if (keyB == '#' ) {
        menu_count = menu_count + 1;
        value_set1 = true;
        done_save = false;
        keyB = 'd';
        if (menu_count == MENU_RESET) {
            menu_count = MENU_TMP;
        }
        //       the temperature is set in this loop
        //==================================================
        while ( value_set1 == true && menu_count == 1) {
            processKeypadInput(menu_count);
        }
        //======================================================
        while ( value_set1 == true && menu_count == 2) {
            processKeypadInput(menu_count);
        }
        //=====================================================
        while ( value_set1 == true && menu_count == 3) {
            processKeypadInput(menu_count);
        }
    }
}
// END sampA.cpp
