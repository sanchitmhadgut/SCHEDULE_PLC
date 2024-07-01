#include <Ethernet.h>
#include <EthernetUdp.h>

/*
   W5500 "hardware" MAC address.
*/
uint8_t eth_MAC[] = {0x02, 0xF0, 0x0D, 0xBE, 0xEF, 0x01 };

// Your string representation of the IP address

IPAddress eth_IP;    // *** CHANGE THIS to something relevant for YOUR LAN. ***

IPAddress eth_MASK(255, 255, 255, 0);   // Subnet mask.

#define RESET_P 26        // Tie the Wiz820io/W5500 reset pin to ESP32 GPIO26 pin.

int localPort = 1234;    // Local port for UDP packets.




void WizReset()
{
  // Function to reset Wiz W5500 Ethernet Board
  Serial.print("Resetting Wiz W5500 Ethernet Board...  ");
  pinMode(RESET_P, OUTPUT);
  digitalWrite(RESET_P, HIGH);
  delay(250);
  digitalWrite(RESET_P, LOW);
  delay(50);
  digitalWrite(RESET_P, HIGH);
  delay(350);
  Serial.println("Done.");
}



void prt_hwval(uint8_t refval)
{
  // Print hardware type based on reference value
  switch (refval)
  {
    case 0:
      Serial.println("No hardware detected.");
      break;
    case 1:
      Serial.println("WizNet W5100 detected.");
      break;
    case 2:
      Serial.println("WizNet W5200 detected.");
      break;
    case 3:
      Serial.println("WizNet W5500 detected.");
      break;
    default:
      Serial.println("UNKNOWN - Update espnow_gw.ino to match Ethernet.h");
  }
}



void prt_ethval(uint8_t refval)
{
  // Print Ethernet status based on reference value
  switch (refval)
  {
    case 0:
      Serial.println("Unknown status.");
      break;
    case 1:
      Serial.println("Link flagged as UP.");
      break;
    case 2:
      Serial.println("Link flagged as DOWN. Check cable connection.");
      break;
    default:
      Serial.println("UNKNOWN - Update espnow_gw.ino to match Ethernet.h");
  }
}
