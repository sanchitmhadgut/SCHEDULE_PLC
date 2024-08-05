#include <SPI.h>
#include "ethernet_w5500.h"
#include "crc_16.h"
#include "cms_comm.h"
#include "recv_cmd.h"
#include <esp_task_wdt.h>
#include <EEPROM.h>



void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);

  Wire.begin();
  Wire.setClock(100000);

  // Initialize RTC
  while (!rtc.begin()) {
    Serial.println(F("RTC not found"));
  }

  rtc_gettime();

  rec_no();
  line_no();
  panel_id();
  seq_no();

  Time_f();
  Date_f();
  len_data();

  init_pwr_cmd();

  eth_init();

  Recv_msg = PRO_ID;
}

void loop() {
  rtc_gettime();
  Time_f();
  Date_f();
  len_data();

  init_pwr_cmd();

  if (pwr_flg == false) {
    poweron();
    pwr_flg = true;
  }

  // Check if the client is connected and available to read
  if (client.connected() && client.available()) {
    // Read incoming data
    incomingResponse = client.readStringUntil('\n');
    Serial.println("Received response: " + incomingResponse);
    incomingResponse.toCharArray(recv_buff, incomingResponse.length() + 1);
    Serial.println(recv_buff);
    handle_recvtcp();
  }
}
