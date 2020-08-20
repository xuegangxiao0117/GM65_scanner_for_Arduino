#include <SoftwareSerial.h>
#include "GM60_scanner.h"
SoftwareSerial mySerial(10, 11); // RX, TX

GM60_scanner scanner(&mySerial);

int buf[30];
int* pointer = buf;
int count;

void setup() {

  Serial.begin(115200);

  mySerial.begin(9600);
  Serial.println("initialize the scanner...");
  scanner.init();
  Serial.println("enable the setting QR code");
  scanner.enable_setting_code();

}

void read_info() {
  if (mySerial.available() > 0) {
    count = 0;
    while (mySerial.available()) {
      buf[count] = mySerial.read();
      count++;
    }
  }
}


void loop() {

  if (mySerial.available() > 0) {
    int buf[30];
    int count = 0;
    while (mySerial.available()) {
      buf[count] = mySerial.read();
      count++;
    }
  for (int i =0; i<count; i++){
    Serial.println(char(buf[i]));
    }
  }
  
}

//  if (mySerial.available() > 0) {
//    while (mySerial.available()) {
//      Serial.write(mySerial.read());
//    }
//  }
