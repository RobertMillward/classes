
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
bool done_save = true;
 */
/**
 * LCD information
 */
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display
/**
 * Relay information
 */
typedef enum relayEnum
{
    relay_co2 = 10,
    relay_hum,
    relay_temp
}relay;

/**
 * Lcd information
 * note: the EEPROM code also uses these enum values
 */
#define LCDCOL_BEG 0
typedef enum lcdColEnum
{
    LCDCOL_TMP = LCDCOL_BEG,
    LCDCOL_HUM,
    LCDCOL_CO2
}lcdColEnumT;

typedef enum lcdOneRowEnum
{
    LCD1ROW_TOP,
    LCD1ROW_DTA
}lcdOneRowEnumT;

typedef enum lcdMultiRowEnum
{
    LCDNROW_TOP = 0,
    LCDNROW_TMP = 2,
    LCDNROW_HUM,
    LCDNROW_CO2
}lcdManyRowEnumT;

/**
 * The values from the keypad
 */
int mapped_t = 100;
int mapped_c = 1000;
int mapped_h = 100;

/**
 * Sensor information
 */
SCD30 airSensor;



/**
 * Keypad information
 */
#define KEY_SCRA 'A'
#define KEY_SCRB 'B'
#define KEY_MENU '#'
#define KEY_READ '*'
const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns
byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
char keys[ROW_NUM][COLUMN_NUM] = {
    {'1', '2', '3', KEY_SCRA},
    {'4', '5', '6', KEY_SCRB},
    {'7', '8', '9', 'C'},
    {KEY_READ, '0', KEY_MENU, 'D'}
};
Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );


/**
 * Other controls
 */
int value_set1 = 0;
char Data[5];
byte data_count = 0;
bool aloop = true;

/**
 * Menu information
 */
typedef enum menuEnum
{
    MENU_NEW = 0,
    MENU_TMP,
    MENU_HUM,
    MENU_CO2,
    MENU_RESET
}menuEnumT;
int menu_count = MENU_NEW;


void printMenuHeader(int menu_count)
{
    lcd.clear();
    lcd.setCursor(LCDCOL_BEG, LCDNROW_TOP);
    
    switch(menu_count)
    {
        case MENU_TMP: lcd.print("Set TEMP :");      break;
        case MENU_HUM: lcd.print("Set humidity :");  break;
        case MENU_CO2: lcd.print("Set CO2 :");       break;
    }
}

void printMenuFooter(int menu_count)
{
    lcd.clear();
    lcd.setCursor(LCDCOL_BEG, LCDNROW_TOP); // This matches the sent code:
    switch(menu_count)
    {
        case MENU_TMP: lcd.print("Done setting TEMP");      break;
        case MENU_HUM: lcd.print("Done setting humidity");  break;
        case MENU_CO2: lcd.print("Done setting CO2");       break;
    }
    
    delay(1000);
}


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

    pinMode(relay_co2, OUTPUT);// set relay pin as output
    pinMode(relay_hum, OUTPUT);// set relay pin as output
    pinMode(relay_temp, OUTPUT);// set relay pin as output
    //The SCD30 has data ready every two seconds
    mapped_t = EEPROM.read(LCDCOL_TMP);
    mapped_h = EEPROM.read(LCDCOL_HUM);
    mapped_c = EEPROM.read(LCDCOL_CO2);
}


void processKeypadInput(int menu_count)
{
    printMenuHeader(menu_count);
    
    char customKey = keypad.getKey();
    if (customKey) // makes sure a key is actually pressed, equal to (customKey != NO_KEY)
    {
        Data[data_count] = customKey; // store char into data array
        // TODO: might the LCD1ROW_DTA below be epromCol?
        lcd.setCursor(data_count, LCD1ROW_DTA); // move cursor to show each new char
        lcd.print(Data[data_count]); // print char at said cursor
        data_count++; // increment data array by 1 to store new char, also keep track of the number of chars entered
        
    }
    if (customKey == KEY_READ) // if the array index is equal to the number of expected chars, compare data to master
    {
        int epromCol = -1;
        switch(menu_count)
        {
            case MENU_TMP: epromCol = LCDCOL_TMP; break;
            case MENU_HUM: epromCol = LCDCOL_HUM; break;
            case MENU_CO2: epromCol = LCDCOL_CO2; break;
        }
        EEPROM.write(epromCol, Data[data_count]);
        
        switch(menu_count)
        {
            case MENU_TMP: mapped_t = Data[data_count]; break;
            case MENU_HUM: mapped_h = Data[data_count]; break;
            case MENU_CO2: mapped_c = Data[data_count]; break;
        }
        
        printMenuFooter(menu_count);
        
        value_set1 = false;
        aloop = true;
    }
}

void loop()
{
    if (aloop) {
        lcd.clear();
        lcd.setCursor(LCDCOL_BEG, LCDNROW_TMP);
        lcd.print("Target Temp ");
        lcd.print(mapped_t);
        
        lcd.setCursor(LCDCOL_BEG, LCDNROW_HUM);
        lcd.print("Target RH ");
        lcd.print(mapped_h);
        
        lcd.setCursor(LCDCOL_BEG, LCDNROW_CO2);
        lcd.print("Target CO2 ");
        lcd.print(mapped_c);
        
        delay(100);
        aloop = false;
    }
    
    char keyB = keypad.getKey();
    if (keyB == KEY_MENU ) {
        menu_count = menu_count + 1;
        value_set1 = true;
        //done_save = false; not needed
        keyB = 'd';
        if (menu_count == MENU_RESET) {
            menu_count = MENU_NEW + 1;
        }
        //       the temperature is set in this loop
        //==================================================
        while ( value_set1 == true && menu_count == MENU_TMP) {
            processKeypadInput(menu_count);
        }
        //======================================================
        while ( value_set1 == true && menu_count == MENU_HUM) {
            processKeypadInput(menu_count);
        }
        //=====================================================
        while ( value_set1 == true && menu_count == MENU_CO2) {
            processKeypadInput(menu_count);
        }
        
        // done_save = true; not needed
    }
}
// END sampA.cpp
