void rtc_gettime() {
  char name[DATE_STRING_SHORT + 1];

  uint8_t hour;
  uint8_t min;
  uint8_t sec;

  uint8_t mday;
  uint8_t mon;
  uint16_t year;
  uint8_t wday;

  unsigned long currentMillis = millis();  //4000

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
