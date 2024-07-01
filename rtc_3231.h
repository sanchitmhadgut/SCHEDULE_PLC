#include <Wire.h>
#include <ErriezDS3231.h>


// Create RTC object
ErriezDS3231 rtc;

#define DATE_STRING_SHORT           2

// Month names in flash
const char monthNames_P[] PROGMEM = "010203040506070809101112";

unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 4000;

uint8_t r_hour;
uint8_t r_min;
uint8_t r_sec;


uint8_t r_mday;
uint8_t r_mon;
uint16_t r_year;


void rtc_gettime() {
  char name[DATE_STRING_SHORT + 1];

  uint8_t hour;
  uint8_t min;
  uint8_t sec;

  uint8_t mday;
  uint8_t mon;
  uint16_t year;
  uint8_t wday;

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    rtc.getDateTime(&hour, &min, &sec, &mday, &mon, &year, &wday);
    strncpy_P(name, &(monthNames_P[(mon - 1) * DATE_STRING_SHORT]), DATE_STRING_SHORT);
    name[DATE_STRING_SHORT] = '\0';
    
    r_mon = (name[0] - '0') * 10 + (name[1] - '0');
    r_mday = mday;
    r_year = year;

    r_hour = hour;
    r_min = min;
    r_sec = sec;

  }
}
