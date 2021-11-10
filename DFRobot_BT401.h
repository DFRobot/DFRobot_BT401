/*!
 * @file DFRobot_BT401.h
 * @brief Define basic structure of DFRobot_BT401 class
 * @details This Bluetooth module features Bluetooth/U-disk/TF-card playback, 
 * @n and Bluetooth call function, supporting simple and clear serial port 
 * @n control function, BLE pass-through, and SPP pass-through functions.
 * @copyright Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [Eddard](eddard.liu@dfrobot.com)
 * @version  V1.0
 * @date  2020-12-29
 * @url https://github.com/DFRobot/DFRobot_BT401
 */

#ifndef _DFRobot_BT401_H
#define _DFRobot_BT401_H

#include "Arduino.h"
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

  /**
   * @struct eFunction_t
   * @brief Working Mode 
   */
  typedef enum{
    eBluetooth = 1,  /**<Bluetooth */
    eUDisk,          /**<U-disk */
    eTFCard,         /**<TF card */
    eIdle = 8        /**<idle */
  }eFunction_t;

  /**
   * @struct ePlayMode_t
   * @brief Playback Mode 
   */
  typedef enum{
    eRepeatAll = 0,  /**<Repeat all */
    eDeviceCycle,      /**<Repeat all songs in one device */
    eSingleCycle,    /**<Repeat one song */
    eDeviceRandom,    /**<Play random in one device */
    eFileCycle      /**<Repeat all songs in file folder */
  }ePlayMode_t;

  /**
   * @struct ePlayControl_t
   * @brief Playback control  
   */
  typedef enum{
    eStop = 0,       /**<stop */
    ePlay,           /**<play */
    ePause,          /**<pause */
    ePPSwitch,       /**<Play & pause switch */
    eFF,             /**<fast forward*/
    eFR,             /**<fast backword */
    eNextFile,    /**<Play songs in next file folder */
    eLastFile     /**<Play songs in last file folder */
  }ePlayControl_t;

  /**
   * @struct eControltalk_t
   * @brief Calling control 
   */
  typedef enum{
    eCallBack = 0,       /**<Call back the last phone number*/
    eDisconnectBLE,              /**<Disconnect Bluetooth */
    eRejectCall,           /**<Refuse to answer */
    eHangUp,          /**<Hang up */
    eAnswer        /**<Answer */
  }eControltalk_t;

  /**
   * @struct eBtStatus
   * @brief Bluetooth Status 
   */
  typedef enum{
   eStandby,  /**<Wait for pairing */
   eBTIdle,   /**<idle */
   ePlaying,  /**<Playing music */
   eCalling,  /**<Phone call coming */ 
   eOnphone,  /**<On the phone */
   eError,
  }eBtStatus;
public:

  DFRobot_BT401();

  /**
   * @fn begin
   * @brief init function
   * @param s serial
   * @return Boolean type, Indicates the initialization result
   * @retval true The setting succeeded
   * @retval false Setting failed
   */
  bool begin(Stream &s);
  
  /**
   * @fn setVOl
   * @brief Set volume 
   * @param vol 0-30
   * @return Boolean type, the result of seted
   * @retval true The setting succeeded
   * @retval false Setting failed
  */
  bool setVOl(uint8_t vol);
  
  /**
   * @fn switchFunction
   * @brief Set working mode 
   * @param function eFunction_t:eBluetooth,eUDisk,eTFCard,eIdle
   * @return Boolean type, the result of seted
   * @retval true The setting succeeded
   * @retval false Setting failed
   */
  bool switchFunction(eFunction_t function);

  /**
   * @fn setPlayMode
   * @brief Set playback mode 
   * @param mode ePlayMode_t:eRepeatAll,eDeviceCycle,eSingleCycle,eDeviceRandom,eFileCycle
   * @return Boolean type, the result of seted
   * @retval true The setting succeeded
   * @retval false Setting failed
   */
  bool setPlayMode(ePlayMode_t mode);

  /**
   * @fn playControl
   * @brief Play control  Only valid for playback by TF card and U-disk
   * @param cmd ePlayControl_t
   * @return Boolean type, the result of seted
   * @retval true The setting succeeded
   * @retval false Setting failed
   */
  bool playControl(ePlayControl_t cmd);
  
  /**
   * @fn next
   * @brief Next 
   * @return Boolean type, the result of operation
   * @retval true The setting succeeded
   * @retval false Setting failed
   */
  bool next();
  
  /**
   * @fn last
   * @brief Previous 
   * @return Boolean type, the result of operation
   * @retval true The setting succeeded
   * @retval false Setting failed
   */
  bool last();

  /**
   * @fn playFileNum
   * @brief Play the file of specific number, the numbers are arranged according to the sequences the files copied into the U-disk 
   * @param number file number, can be obtained by getCurFileNumber()
   * @return Boolean type, the result of operation
   * @retval true The setting succeeded
   * @retval false Setting failed
   */
  bool playFileNum(uint16_t number);
  
  /**
   * @fn playSpecFile
   * @brief Play file of the specific path 
   * @return Boolean type, the result of operation
   * @retval true The setting succeeded
   * @retval false Setting failed
   */
  bool playSpecFile(const char* path);
  
  /**
   * @fn delCurFile
   * @brief Delete the currently-playing file 
   * @return Boolean type, the result of operation
   * @retval true The setting succeeded
   * @retval false Setting failed
   */
  bool delCurFile();
  
  /**
   * @fn callOut
   * @brief Dial a phone number 
   * @param phoneNumber phone number
   * @return Boolean type, the result of operation
   * @retval true The setting succeeded
   * @retval false Setting failed
   */
  bool callOut(const char* phoneNumber);
  
  /**
   * @fn controltalk
   * @brief Call control 
   * @param cmd eControltalk_t
   * @return Boolean type, the result of operation
   * @retval true The setting succeeded
   * @retval false Setting failed
   */
  bool controltalk(eControltalk_t cmd);

  /**
   * @fn reset
   * @brief Reset
   * @return Boolean type, the result of operation
   * @retval true The setting succeeded
   * @retval false Setting failed
   */
  bool reset();

  /**
   * @fn getBtStatus
   * @brief Obtain bluetooth status 
   * @return eBtStatus
   */
  eBtStatus getBtStatus();
  
  /**
   * @fn getTelNumber
   * @brief Obtain calling phone number 
   * @return phone number
   */
  String getTelNumber();
protected:
  void sendCMD(const char *cmd, const char *payload);
  void sendCMD(const char *cmd);
  
  String readAck(uint8_t len = 4);

private:
  Stream *_s;
};

#endif

