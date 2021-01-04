/*!
 * @file DFRobot_BT401.h
 * @brief Define basic structure of DFRobot_BT401 class
 * @n This is an library for capacitive fingerprint module
 * @n Main functions: fingerprint image capturing, fingerprint comparison, fingerprint deletion
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [Eddard](eddard.liu@dfrobot.com)
 * @version  V1.0
 * @date  2020-12-29
 * @get from https://www.dfrobot.com
 * @url https://github.com/cdjq/DFRobot_BT401
 */

#ifndef _DFRobot_BT401_H
#define _DFRobot_BT401_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <Wire.h>
#include <stdint.h>
#include <SoftwareSerial.h>
//#define ENABLE_DBG
#ifdef ENABLE_DBG
#define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif

class DFRobot_BT401{
public:
  
  //Working Mode 
  typedef enum{
    eBluetooth = 1,  //Bluetooth 
    eUDisk,          //U-disk
    eTFCard,         //TF card
    eIdle = 8            //idle 
  }eFunction_t;
  
  //Playback Mode 
  typedef enum{
    eRepeatAll = 0,  //Repeat all 
    eDeviceCycle,      //Repeat all songs in one device 
    eSingleCycle,    //Repeat one song 
    eDeviceRandom,    //Play random in one device 
    eFileCycle      //Repeat all songs in file folder 
  }ePlayMode_t;
  
  //Playback control 
  typedef enum{
    eStop = 0,       //stop 
    ePlay,           //play 
    ePause,          //pause 
    ePPSwitch,       //Play & pause switch 
    eFF,             //fast forward
    eFR,             //fast backword 
    eNextFile,    //Play songs in next file folder 
    eLastFile     //Play songs in last file folder 
  }ePlayControl_t;
  
  //Calling control 
  typedef enum{
    eCallBack = 0,       //Call back the last phone number
    eDisconnectBLE,              //Disconnect Bluetooth 
    eRejectCall,           //Refuse to answer 
    eHangUp,          //Hang up 
    eAnswer        //Answer 
  }eControltalk_t;
  
  //Bluetooth Status 
  typedef enum{
   eStandby,  //Wait for pairing 
   eBTIdle,   //idle 
   ePlaying,  //Playing music 
   eCalling,  //Phone call coming  
   eOnphone,  //On the phone 
   eError,
  }eBtStatus;
public:
  DFRobot_BT401();
  bool begin(Stream &s);
  /**
   * @brief Set volume
   * @param volume(0-30)
   * @return true or false
   */
  bool setVOl(uint8_t vol);
  
  /**
   * @brief Set working mode
   * @param eFunction_t
   * @return true or false
   */
  bool switchFunction(eFunction_t function);

  /**
   * @brief Set play mode 
   * @param ePlayMode_t
   * @return true or false
   */
  bool setPlayMode(ePlayMode_t mode);

  /**
   * @brief Play control  Only valid for playback by TF card and U-disk
   * @param ePlayControl_t
   * @return true or false
   */
  bool playControl(ePlayControl_t cmd);
  
  /**
   * @brief Next
   * @return true or false
   */
  bool next();
  
  /**
   * @brief Last 
   * @return true or false
   */
  bool last();

  /**
   * @brief Play the N-th file, play song of the specified number 
   * @param specified number
   * @return true or false
   */
  bool playFileNum(uint16_t number);
  
  /**
   * @brief Play song of the specified path
   * @param specified path
   * @return true or false
   */
  bool playSpecFile(const char* path);
  
  /**
   * @brief Delete the currently playing file 
   * @return true or false
   */
  bool delCurFile();
  
  /**
   * @brief Dial a phone number 
   * @param phone number
   * @return true or false
   */
  bool callOut(const char* phoneNumber);
  
  /**
   * @brief Call control 
   * @param eControltalk_t
   * @return true or false
   */
  bool controltalk(eControltalk_t cmd);

  /**
   * @brief Reset
   * @return true or false
   */
  bool reset();

  /**
   * @brief Obtain bluetooth status 
   * @return eBtStatus
   */
  eBtStatus getBtStatus();
  
  /**
   * @brief Obtain calling phone number 
   * @return phone number
   */
  String getTelNumber();
protected:
 /**
  * @brief Send data 
  * @param Data frame
  */
  void sendCMD(const char *cmd, const char *payload);
  void sendCMD(const char *cmd);
  
  String readAck(uint8_t len = 4);

private:
  Stream *_s;
};

#endif

