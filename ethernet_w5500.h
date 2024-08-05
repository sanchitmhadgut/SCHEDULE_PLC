#include <Ethernet.h>

// Initialize the Ethernet client
EthernetClient client;


/*
   W5500 "hardware" MAC address.
*/
uint8_t eth_MAC[] = {0x02, 0xF0, 0x0D, 0xBE, 0xEF, 0x01 };

// Your string representation of the IP address

IPAddress eth_IP(192, 168, 1, 177);    // *** CHANGE THIS to something relevant for YOUR LAN. ***

IPAddress eth_MASK(255, 255, 255, 0);   // Subnet mask.

#define RESET_P 26        // Tie the Wiz820io/W5500 reset pin to ESP32 GPIO26 pin.

int port = 9876;    // Local port for TCP packets.



IPAddress server(192, 168, 1, 103);
