
int crc_cal() {
  uint16_t crc = 0;
  
  str_len_x = sprintf(crc_data, "%s%s", pwr_cmd.PROTO_ID, pwr_cmd.SEQ_NO);

  str_len_x += sprintf(crc_data + str_len_x, "%s%s%s%s", pwr_cmd.REC_NO, pwr_cmd.LINE_NO, pwr_cmd.PANEL_ID, pwr_cmd.ZONE_NO);

  str_len_x = sprintf(crc_data + str_len_x, "%s%s", pwr_cmd.TIME, pwr_cmd.DATE);
//  Serial.print("crc_data: ");
//  Serial.println(crc_data);
  
  for (uint16_t count = 0; count < strlen(crc_data); count++) {
    crc = (crc >> 8) ^ key[(crc ^ crc_data[count]) & 0xFF];
  }
  //  Serial.print("CRC: ");
  //  Serial.println(crc, HEX);  // Print CRC value in hexadecimal format
  return crc;
}

int len_data() {
  int data_len;
  data_len = strlen(crc_data);
  return data_len;
}
