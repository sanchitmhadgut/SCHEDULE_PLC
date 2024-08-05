void init_pwr_cmd() {

  pwr_cmd.LF = '\n';
  pwr_cmd.CRC = crc_cal();
  pwr_cmd.CMD_LEN = len_data();
  pwr_cmd.PROTO_ID[0] = '"';
  pwr_cmd.PROTO_ID[1] = 'N';
  pwr_cmd.PROTO_ID[2] = 'U';
  pwr_cmd.PROTO_ID[3] = 'L';
  pwr_cmd.PROTO_ID[4] = 'L';
  pwr_cmd.PROTO_ID[5] = '"';
  pwr_cmd.PROTO_ID[6] = 0;
  pwr_cmd.LINE_NO;
  pwr_cmd.PANEL_ID;
  pwr_cmd.ZONE_NO[0] = '[';
  pwr_cmd.ZONE_NO[1] = ']';
  pwr_cmd.ZONE_NO[2] = '_';
  pwr_cmd.ZONE_NO[3] = 0;

  pwr_cmd.CRET = '\r';

}

void seq_no() {
  char seq_buff[8];
  int number = 0;
  sprintf(seq_buff, "%04d", number);
  Serial.println(seq_buff);
  strcpy(pwr_cmd.SEQ_NO, seq_buff);
}

void rec_no() {
  char rec_buff[10];
  int number = 1;
  sprintf(rec_buff, "R%06d", number);
  Serial.println(rec_buff);
  strcpy(pwr_cmd.REC_NO, rec_buff);
}

void line_no() {
  char line_buff[8];
  int number = 82;
  sprintf(line_buff, "L%06d", number);
  Serial.println(line_buff);
  strcpy(pwr_cmd.LINE_NO, line_buff);
}

void panel_id() {
  char panel_buff[10];
  int number = 700001;
  str_len = sprintf(panel_buff, "#%06d", number);
  Serial.println(panel_buff);
  strncpy(pwr_cmd.PANEL_ID, panel_buff, str_len);
  pwr_cmd.PANEL_ID[str_len] = 0;
}

void Time_f() {
  char time_cmd[10];
  str_len = sprintf(time_cmd, "%02d:%02d:%02d", r_hour, r_min, r_sec);
  strncpy(pwr_cmd.TIME, time_cmd, str_len);
  pwr_cmd.TIME[str_len] = 0;
}

void Date_f() {
  char date_cmd[20];
  str_len = sprintf(date_cmd, ",%02d-%02d-%04d", r_mon, r_mday, r_year);
  strncpy(pwr_cmd.DATE, date_cmd, str_len);
  pwr_cmd.DATE[str_len] = 0;
  //Serial.println(pwr_cmd.DATE);
}

void poweron() {

  str_len = sprintf(POWERON, "\n%04X%04X%s%s", pwr_cmd.CRC, pwr_cmd.CMD_LEN, pwr_cmd.PROTO_ID, pwr_cmd.SEQ_NO);
  //Serial.println(POWERON);
  str_len += sprintf(POWERON + str_len, "%s%s%s%s", pwr_cmd.REC_NO, pwr_cmd.LINE_NO, pwr_cmd.PANEL_ID, pwr_cmd.ZONE_NO);
  //Serial.println(POWERON);
  str_len = sprintf(POWERON + str_len, "%s%s\r", pwr_cmd.TIME, pwr_cmd.DATE);
  //Serial.println(POWERON);

  Serial.print("Data: ");
  Serial.println(POWERON);

    // Attempt to connect to the server
  Serial.println("Connecting to server...");
  if (client.connect(server, port)) {
    Serial.println("Connected to server");
    // Send a packet
    client.println(POWERON);
    Serial.println("Packet sent has been sent");
  } else {
    Serial.println("Connection failed.");
  }



  delay(3000);
}
