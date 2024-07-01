#include <SPI.h>
#include "ethernet_w5500.h"
#include "crc_16.h"
#include "cms_pwron.h"
//#include "rtc_3231.h"
#include <esp_task_wdt.h>
#include <EEPROM.h>


void setup() {
  Serial.begin(115200);

  Wire.begin();
  Wire.setClock(100000);

  //  // Initialize Ethernet
  //  Ethernet.init(5);
  //  WizReset();
  //
  //  // Start Ethernet connection
  //  Serial.println("Starting ETHERNET connection...");
  //  //  Ethernet.begin(eth_MAC, eth_IP, eth_DNS, eth_GW, eth_MASK);
  //  Ethernet.begin(eth_MAC, eth_IP, eth_MASK);
  //  delay(200);
  //
  //  Serial.print("Ethernet IP is: ");
  //  Serial.println(Ethernet.localIP());
  //
  //  Serial.print("Checking connection.");
  //  bool rdy_flag = false;
  //
  //  // ****************Check Ethernet connection status***************
  //  for (uint8_t i = 0; i <= 20; i++)
  //  {
  //    if ((Ethernet.hardwareStatus() == EthernetNoHardware) || (Ethernet.linkStatus() == LinkOFF))
  //    {
  //      Serial.print(".");
  //      rdy_flag = false;
  //      delay(80);
  //    }
  //    else
  //    {
  //      rdy_flag = true;
  //      break;
  //    }
  //  }
  //
  //  if (rdy_flag == false)
  //  {
  //    // Handle hardware or cable connection issues
  //    Serial.println("\n\r\tHardware fault, or cable problem... cannot continue.");
  //    Serial.print("Hardware Status: ");
  //    prt_hwval(Ethernet.hardwareStatus());
  //    Serial.print("   Cable Status: ");
  //    prt_ethval(Ethernet.linkStatus());
  //    while (true)
  //    {
  //      delay(10);
  //    }
  //  }
  //  else
  //  {
  //    Serial.println("OK");
  //  }

  // ****************/Check Ethernet connection status***************

  rec_no();
  line_no();
  panel_id();
  seq_no();

}

void loop() {

  rtc_gettime();
  init_pwr_cmd();
  len_data();
  Time_f();
  Date_f();
  
  poweron();


//  Serial.print("Data: ");
//  Serial.println(pwr_cmd.CMD_LEN);

}
