#include <String.h>


String incomingResponse; 
char recv_buff[120];

enum RECVMSG {
  PRO_ID, SEQ_NO, RECV_NO, LINE_NO, PANEL_ID, REC_HR, REC_MIN, REC_SEC
};

enum RECVMSG Recv_msg;




