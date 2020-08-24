S#include <SoftwareSerial.h>
#include "GM65_scanner.h"
SoftwareSerial mySerial(10, 11); // RX, TX

GM65_scanner scanner(&mySerial);
int buttonPin = 4;

void setup() {

  pinMode(buttonPin,INPUT);
  Serial.begin(115200);

  mySerial.begin(9600);
  Serial.println("initialize the scanner...");
  scanner.init();
  Serial.println("enable the setting QR code");
  scanner.enable_setting_code();

  //scan once function, only works in command mode
  Serial.println("change to command trigger mode");
  scanner.set_working_mode(1);
}



void loop() {
  int button_state = digitalRead(buttonPin);
  if(button_state == HIGH){
      scanner.scan_once();
    }


}
