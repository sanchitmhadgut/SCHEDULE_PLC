#include <String.h>
#include "rtc_3231.h"


char POWERON[120];
int str_len;

bool pwr_flg = false;

struct CMS_CMD {
  int LF;
  int CRC;
  int CMD_LEN;
  char PROTO_ID[10];
  char SEQ_NO[5];
  char REC_NO[10];
  char LINE_NO[8];
  char PANEL_ID[8];
  char ZONE_ALT[4];
  char ZONE_NO[4]; // in pwr zone only []_
  char TIME[10];
  char DATE[20];
  int CRET;
};


struct CMS_CMD pwr_cmd;
