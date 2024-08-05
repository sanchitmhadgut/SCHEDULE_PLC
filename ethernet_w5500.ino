void eth_init() {
  // Initialize Ethernet
  Ethernet.init(5);
  WizReset();

  // Start Ethernet connection
  Serial.println("Starting ETHERNET connection...");
  //  Ethernet.begin(eth_MAC, eth_IP, eth_DNS, eth_GW, eth_MASK);
  Ethernet.begin(eth_MAC, eth_IP, eth_MASK);
  delay(200);

  Serial.print("Ethernet IP is: ");
  Serial.println(Ethernet.localIP());

  Serial.print("Checking connection.");
  bool rdy_flag = false;

  // ****************Check Ethernet connection status***************
  for (uint8_t i = 0; i <= 20; i++)
  {
    if ((Ethernet.hardwareStatus() == EthernetNoHardware) || (Ethernet.linkStatus() == LinkOFF))
    {
      Serial.print(".");
      rdy_flag = false;
      delay(80);
    }
    else
    {
      rdy_flag = true;
      break;
    }
  }

  if (rdy_flag == false)
  {
    // Handle hardware or cable connection issues
    Serial.println("\n\r\tHardware fault, or cable problem... cannot continue.");
    Serial.print("Hardware Status: ");
    prt_hwval(Ethernet.hardwareStatus());
    Serial.print("   Cable Status: ");
    prt_ethval(Ethernet.linkStatus());
    while (true)
    {
      delay(10);
    }
  }
  else
  {
    Serial.println("OK");
  }

  // ****************/Check Ethernet connection status***************


  
}




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
