#include <SoftwareSerial.h>
#include "GM60_scanner.h"
SoftwareSerial mySerial(10, 11); // RX, TX

GM60_scanner scanner(&mySerial);
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
  Serial.println(scanner.get_mode());
  delay(1000);

  //silent mode on
  Serial.println("change to silent mode on ...");
  scanner.set_silent_mode(1);
  delay(3000);
  Serial.println("get current mode");
  Serial.println(scanner.get_mode());

  //silent mode off
  Serial.println("change to silent mode off ...");
  scanner.set_silent_mode(0);
  delay(3000);
  Serial.println("get current mode");
  Serial.println(scanner.get_mode());

  //LED on
  Serial.println("change to LED mode on ...");
  scanner.set_LED_mode(1);
  delay(3000);
  Serial.println("get current mode");;
  Serial.println(scanner.get_mode());

  //LED off
  Serial.println("change to LED mode off ...");
  scanner.set_LED_mode(0);
  delay(3000);
  Serial.println("get current mode");;
  Serial.println(scanner.get_mode());

  //change working mode, 0 - manually
  Serial.println("change working mode, 0 - manually");
  scanner.set_working_mode(0);
  delay(3000);
  Serial.println("get current mode");;
  Serial.println(scanner.get_mode());

  //change working mode, 1 - trigger by command 
  Serial.println("change working mode, 1 - trigger by command ");
  scanner.set_working_mode(1);
  delay(3000);
  Serial.println("get current mode");;
  Serial.println(scanner.get_mode());

  //change working mode, 2 - continueous
  Serial.println("change working mode, 2 - continueous");
  scanner.set_working_mode(2);
  delay(3000);
  Serial.println("get current mode");;
  Serial.println(scanner.get_mode());

  //change working mode, 3 - detect
  Serial.println("change working mode, 3 - detect");
  scanner.set_working_mode(3);
  delay(3000);
  Serial.println("get current mode");;
  Serial.println(scanner.get_mode());

}



void loop() {

  if (mySerial.available() > 0) {
    while (mySerial.available()) {
      Serial.write(mySerial.read());
    }
  }
}




//  int current_mode = 214;
//  Serial.println(~(1ul << 6)&current_mode);
//  mySerial.write(test, 9);
//  delay(1000);
//  if (mySerial.available() > 0) {
//    //Serial.println("return value:");
//    cont = 0;
//    while (mySerial.available()) {
//      int temp;
//      temp = mySerial.read();
//      arr[cont] = temp;
//      cont++;
//    }
//    Serial.println("count:");
//    Serial.print(cont);
//    Serial.println("arr:");
//    Serial.println(arr[0]);
//    Serial.println(arr[1]);
//    Serial.println(arr[2]);
//    Serial.println(arr[3]);
//    Serial.println(arr[4]);
//    Serial.println(arr[5]);
//    Serial.println(arr[6]);
//    Serial.println("arr the second to last:");
//    Serial.print(arr[cont - 2]);
//  }
//Serial.print("get_mode_info");
//Serial.println(scanner.get_mode());
//  mySerial.write(read_reg, 9);
//  delay(1000);
//  if (mySerial.available() > 0) {
//    //Serial.println("return value:");
//    count = 0;
//    while (mySerial.available()) {
//      //Serial.write(mySerial.read());
//      //buf[count] = mySerial.read();
//      int temp;
//      temp = mySerial.read();
//      Serial.println(temp);
//      //count++;
//    }
//  }
//int buf_size = count;
//Serial.print("size of buf:");
//Serial.println(buf_size);
//Serial.print("buf:");
//Serial.println(buf);
//Serial.print("buf[the second to last]:");
//Serial.println((uint8_t)buf[buf_size-2]);






//if (mySerial.available() > 0) {
//  //Serial.println("return value:");
//  while (mySerial.available()) {
//    Serial.write(mySerial.read());
//  }
//}
