#include <SoftwareSerial.h>
#include "GM65_scanner.h"
SoftwareSerial mySerial(10, 11); // RX, TX

GM65_scanner scanner(&mySerial);
int arr[10];
int cont = 0;
const char test[9] = {0x7E, 0x00, 0x07, 0x01, 0x00, 0x00, 0x01, 0xAB, 0xCD};

void setup() {
  Serial.begin(115200);
  //  while (!Serial) {
  //    ; // wait for serial port to connect. Needed for Native USB only
  //  }
  mySerial.begin(9600);
  Serial.println("initialize the scanner...");
  scanner.init();

  Serial.println("enable the setting QR code");
  scanner.enable_setting_code();

  Serial.println("get current mode");
  Serial.print("mode:");
  Serial.println(scanner.get_mode(0x00, 0x00));
  delay(1000);

  //silent mode on
  Serial.println("change to silent mode on ...");
  scanner.set_silent_mode(1);
  delay(3000);
  Serial.println("get current mode");
  Serial.println(scanner.get_mode(0x00, 0x00));

  //silent mode off
  Serial.println("change to silent mode off ...");
  scanner.set_silent_mode(0);
  delay(3000);
  Serial.println("get current mode");
  Serial.println(scanner.get_mode(0x00, 0x00));

  //LED on
  Serial.println("change to LED mode on ...");
  scanner.set_LED_mode(1);
  delay(3000);
  Serial.println("get current mode");;
  Serial.println(scanner.get_mode(0x00, 0x00));

  //LED off
  Serial.println("change to LED mode off ...");
  scanner.set_LED_mode(0);
  delay(3000);
  Serial.println("get current mode");;
  Serial.println(scanner.get_mode(0x00, 0x00));

  //change working mode, 0 - manually
  Serial.println("change working mode, 0 - manually");
  scanner.set_working_mode(0);
  delay(3000);
  Serial.println("get current mode");;
  Serial.println(scanner.get_mode(0x00, 0x00));

  //change working mode, 1 - trigger by command 
  Serial.println("change working mode, 1 - trigger by command ");
  scanner.set_working_mode(1);
  delay(3000);
  Serial.println("get current mode");;
  Serial.println(scanner.get_mode(0x00, 0x00));

  //change working mode, 2 - continueous
  Serial.println("change working mode, 2 - continueous");
  scanner.set_working_mode(2);
  delay(3000);
  Serial.println("get current mode");;
  Serial.println(scanner.get_mode(0x00, 0x00));

  //change working mode, 3 - detect
  Serial.println("change working mode, 3 - detect");
  scanner.set_working_mode(3);
  delay(3000);
  Serial.println("get current mode");;
  Serial.println(scanner.get_mode(0x00, 0x00));

}



void loop() {

  String str = "";
  str = scanner.get_info();
  if (str.length() > 0) {
    Serial.println(str);
  }

}

