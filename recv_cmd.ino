void handle_recvtcp() {
  // const char* delimiters = "\"_:#,"
  int tm_hr;
  int tm_min;
  int tm_sec;


  char* t_token = strtok(recv_buff, "\"");
  Recv_msg = PRO_ID;

  byte cms_flg = 1;

  while ((t_token != NULL) && cms_flg) {

    switch (Recv_msg) {
      case PRO_ID:
        if (strcmp(t_token, "NAK") == 0) {
          Recv_msg = SEQ_NO;
          Serial.println("NAK found");
          Serial.println(t_token);
          t_token = strtok(NULL, "R");


        } else if (strcmp(t_token, "ACK") == 0) {
          Recv_msg = SEQ_NO;
          Serial.println("ACK found");
          t_token = strtok(NULL, "R");
        } else {
          Serial.println("Not found");
          cms_flg = 0;
        }
        break;

      case SEQ_NO:
        Serial.print("Seq No: ");
        Serial.println(t_token);  //0000
        Recv_msg = RECV_NO;
        t_token = strtok(NULL, "L");
        break;

      case RECV_NO:
        Serial.print("RECV No: ");
        Serial.println(t_token);  //R000001
        Recv_msg = LINE_NO;
        t_token = strtok(NULL, "#");
        break;

      case LINE_NO:
        Serial.print("LINE No: ");
        Serial.println(t_token);  //L000000
        Recv_msg = PANEL_ID;
        t_token = strtok(NULL, "[]_");
        break;

      case PANEL_ID:
        Serial.print("PANEL No: ");
        Serial.println(t_token);  //#666666[]_
        Recv_msg = REC_HR;
        t_token = strtok(NULL, "_");
        t_token = strtok(NULL, ":");
        break;

      case REC_HR:
        tm_hr = atoi(t_token);
        Serial.print("REC_HR: ");
        Serial.println(tm_hr);  //16
        r_hour = tm_hr;

        Recv_msg = REC_MIN;
        t_token = strtok(NULL, ":");
        break;

      case REC_MIN:
        tm_min = atoi(t_token);
        Serial.print("REC_MIN: ");
        Serial.println(tm_min);  //19
        r_min = tm_min;

        Recv_msg = REC_SEC;
        t_token = strtok(NULL, ":");
        break;

      case REC_SEC:
        tm_sec = atoi(t_token);
        Serial.print("REC_SEC: ");
        Serial.println(tm_sec);  //15
        r_sec = tm_sec;

        rtc.setTime(r_hour, r_min, r_sec); //parse msg and set --> rtc time 

        Recv_msg = PRO_ID;
        t_token = strtok(NULL, ",");
        break;

      default:
        cms_flg = 0;
        break;
    }
  }
}