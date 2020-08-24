/*!
   @file CM60_scanner.h
   @brief GM65条形识读模块，arduino库
   @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
   @licence     The MIT License (MIT)
   @author [Gangxiao Xue](gangxiao.xue@dfrobot.com)
   @version  V1.0
   @date  2020-08-19
   @https://github.com/xuegangxiao0117/
*/

#include "GM65_scanner.h"

GM65_scanner::GM65_scanner(Stream * serial) {
  mySerial = serial;
}


int *GM65_scanner::get_response()
{
  static int buf[20];
  int count = 0;
  if (mySerial->available() > 0) {
    while (mySerial->available()) {
      buf[count] = mySerial->read();
      count++;
    }
    return buf;
  }
}

void GM65_scanner::clear_buffer()
{
  if (mySerial->available()) {
    while (mySerial->available() > 0) {
      char temp =  mySerial->read();
    }
  }
}


void GM65_scanner::init()
{
  mySerial->write(set_default, 9);
  delay(10000);
  mySerial->write(set_serial_output, 9);
  delay(1000);
  //GM65_scanner::get_response();
  //GM65_scanner::clear_buffer();
}

void GM65_scanner::enable_setting_code()
{
  mySerial->write(enable_setttingcode, 9);
  delay(1000);
  //GM65_scanner::get_response();
  ///GM65_scanner::clear_buffer();
}

void GM65_scanner::disable_setting_code()
{
  mySerial->write(disable_setttingcode, 9);
  delay(1000);
  //GM65_scanner::get_response();
  //GM65_scanner::clear_buffer();
}

int GM65_scanner::get_mode(byte addr1, byte addr2)
{
  read_reg[4] = addr1;
  read_reg[5] = addr2;
  GM65_scanner::clear_buffer();
  mySerial->write(read_reg, 9);
  delay(1000);
  int *p;
  p = GM65_scanner::get_response();
  return *(p + 4);

}

void GM65_scanner::set_silent_mode(uint8_t silent_mode)
{
  int current_mode = get_mode(0x00, 0x00);
  int temp = ~(1ul << 6)&current_mode;
  byte mode_data;
  mode_data = temp + (silent_mode << 6);
  char mode_command[9] = {0x7E, 0x00, 0x08, 0x01, 0x00, 0x00, mode_data, 0xAB, 0xCD};
  mySerial->write(mode_command, 9);
  //GM65_scanner::get_response();
  //GM65_scanner::clear_buffer();
}

void GM65_scanner::set_LED_mode(uint8_t LED_mode)
{
  int current_mode = get_mode(0x00, 0x00);
  int temp = ~(1ul << 7)&current_mode;
  byte mode_data;
  mode_data = temp + (LED_mode << 7);
  char mode_command[9] = {0x7E, 0x00, 0x08, 0x01, 0x00, 0x00, mode_data, 0xAB, 0xCD};
  mySerial->write(mode_command, 9);
  //GM65_scanner::get_response();
  //GM65_scanner::clear_buffer();
}


void GM65_scanner::set_working_mode(uint8_t working_mode) //bit0-1
{
  int current_mode = get_mode(0x00, 0x00);
  int temp = ~(0b11ul)&current_mode;
  byte mode_data;
  mode_data = temp + working_mode;
  char mode_command[9] = {0x7E, 0x00, 0x08, 0x01, 0x00, 0x00, mode_data, 0xAB, 0xCD};
  mySerial->write(mode_command, 9);
}

void GM65_scanner::set_light_mode(uint8_t light_mode) //bit2-3
{
  int current_mode = get_mode(0x00, 0x00);
  int temp = ~(0b11ul << 2)&current_mode;
  byte mode_data;
  mode_data = temp + (light_mode << 2);
  char mode_command[9] = {0x7E, 0x00, 0x08, 0x01, 0x00, 0x00, mode_data, 0xAB, 0xCD};
  mySerial->write(mode_command, 9);
}

void GM65_scanner::set_aim_mode(uint8_t aim_mode) //bit4-5
{
  int current_mode = get_mode(0x00, 0x00);
  int temp = ~(0b11ul << 4)&current_mode;
  byte mode_data;
  mode_data = temp + (aim_mode << 4);
  char mode_command[9] = {0x7E, 0x00, 0x08, 0x01, 0x00, 0x00, mode_data, 0xAB, 0xCD};
  mySerial->write(mode_command, 9);
}

void GM65_scanner::scan_once()
{
    mySerial->write(scan_once_command, 9);
}

void GM65_scanner::set_sleep_mode(uint8_t sleep_mode){
  int current_mode = get_mode(0x00, 0x07);
  int temp = ~(0b1ul << 7)&current_mode;
  byte mode_data;
  mode_data = temp + (sleep_mode << 7);
  char mode_command[9] = {0x7E, 0x00, 0x08, 0x01, 0x00, 0x07, mode_data, 0xAB, 0xCD};
  mySerial->write(mode_command, 9);

}

String GM65_scanner::get_info(){
  String s = "";
  if (mySerial->available() > 0) {
    while (mySerial->available()) {
      s = s + char(mySerial->read());
    }
  }
  return s;
}