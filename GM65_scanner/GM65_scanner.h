/*!
   @file CM60_scanner.h
   @brief GM65条形识读模块，arduino库
   @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
   @licence     The MIT License (MIT)
   @author [Gangxiao Xue](gangxiao.xue@dfrobot.com)
   @version  V1.0
   @date  2020-08-19
   @https:https://github.com/xuegangxiao0117/
*/
#ifndef CM60_SCANNER_H
#define CM60_SCANNER_H

#include "Arduino.h"
#include "Stream.h"

const char set_default[9] = {0x7E, 0x00, 0x08, 0x01, 0x00, 0xD9, 0x55, 0xAB, 0xCD}; //出厂设置
const char set_serial_output[9] = {0x7E, 0x00, 0x08, 0x01, 0x00, 0x0D, 0x00, 0xAB, 0xCD}; //设置串口输出信息
const char enable_setttingcode[9] = {0x7E, 0x00, 0x08, 0x01, 0x00, 0x03, 0x01, 0xAB, 0xCD};
const char disable_setttingcode[9] = {0x7E, 0x00, 0x08, 0x01, 0x00, 0x03, 0x03, 0xAB, 0xCD};

const char scan_once_command[9] = {0x7E, 0x00, 0x08, 0x01, 0x00, 0x02, 0x01, 0xAB, 0xCD};




class GM65_scanner {
  char read_reg[9] = {0x7E, 0x00, 0x07, 0x01, 0x00, 0x00, 0x01, 0xAB, 0xCD};

  private:

    Stream * mySerial;
    //int *count;


  public:

    GM65_scanner(Stream * serial);

    /**
      @brief 初始化GM65 条形码扫描
    */
    void init();

    /**
      @brief 开启设置码，通过扫描设置码来进行模块的参数配置。
    */
    void enable_setting_code();

    /**
      @brief 关闭扫描设置码功能，通过扫描设置码来进行模块的参数配置。
    */
    void disable_setting_code();

    /**
      @brief 获取当前模式。
    */
    int get_mode(byte addr1, byte addr2);

    /**
      @brief 获取反馈。
    */
    int *get_response();


    /**
      @brief 清除串口缓存。
    */
    void clear_buffer();



    /**
       @brief 设置GM65的各种模式，工作模式，灯光模式，瞄准模式，指示灯模式。
       静音模式，1-开启，0-关闭。
    */
    void set_silent_mode(uint8_t silent_mode);// bit 6

    /**
       @brief 设置GM65的各种模式，工作模式，灯光模式，瞄准模式，指示灯模式。
       LED指示灯模式，扫描成功，蓝色LED灯闪烁。1-开启，0-关闭。
    */
    void set_LED_mode(uint8_t LED_mode);// bit 7

    /**
       @brief 设置GM65的各种模式，工作模式，灯光模式，瞄准模式，指示灯模式。
       GM65工作模式，0-手动模式，1-命令触发模式，2-连续模式，3-感应模式
    */
    void set_working_mode(uint8_t working_mode); //bit0-1
    
    /**
       @brief 设置GM65的各种模式，工作模式，灯光模式，瞄准模式，指示灯模式。
       灯光模式，0-无照明，1-普通，2/3-常亮
    */
    void set_light_mode(uint8_t light_mode); //bit2-3


    /**
       @brief 设置GM65的各种模式，工作模式，灯光模式，瞄准模式，指示灯模式。
       瞄准模式，0-无瞄准，1-普通，2/3-常亮
    */
    void set_aim_mode(uint8_t aim_mode); //bit4-5

    /**
       @brief 执行扫描一次，只能在命令触发模式下执行。
    */
    void scan_once();


    /**
       @brief 睡眠模式，1-开启，0-关闭。只能在手动模式下执行，开启睡眠功能后，30s内不操作，会自动睡眠。
    */
    void set_sleep_mode(uint8_t sleep_mode);
    

    // int *get_info();

    /**
      @brief 获取信息。
    */
    String get_info();


};




#endif
