#include <SoftwareSerial.h>
#include "GM65_scanner.h"
SoftwareSerial mySerial(10, 11); // RX, TX

GM65_scanner scanner(&mySerial);


void setup() {

  Serial.begin(115200);

  mySerial.begin(9600);
  Serial.println("initialize the scanner...");
  scanner.init();
  Serial.println("enable the setting QR code");
  scanner.enable_setting_code();

  //sleep function, only works in manual mode
  Serial.println("change to manual mode");
  scanner.set_working_mode(0);

  Serial.println("set the sleep mode, scanner will go to sleep if the module keep idle for 30s ");
  scanner.set_sleep_mode(1);
}



void loop() {

  String str = "";
  str = scanner.get_info();
  if (str.length() > 0) {
    Serial.println(str);
  }
  
}
