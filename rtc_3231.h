#include <Wire.h>
#include <ErriezDS3231.h>


// Create RTC object
ErriezDS3231 rtc;

#define DATE_STRING_SHORT           2

// Month names in flash
const char monthNames_P[] PROGMEM = "010203040506070809101112";

unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 500;

uint8_t r_hour;
uint8_t r_min;
uint8_t r_sec;


uint8_t r_mday;
uint8_t r_mon;
uint16_t r_year;
