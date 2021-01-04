# DFRobot_AS7341

This Bluetooth module features Bluetooth/U-disk/TF-card playback, and Bluetooth call function, supporting simple and clear serial port control function, BLE pass-through, and SPP pass-through functions. The highlight of this product is the dual-mode Bluetooth, which also means that it can run the Bluetooth audio playback and data transmission at the same time, greatly reducing the development difficulty of embedded Bluetooth in other products.
## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary
1. Play music<br>
2. Answer calls


## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods
```C++
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
  bool playSpecFile(uint16_t number);
  
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
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno        |      √       |              |             | 
Mega2560        |      √       |              |             | 
Leonardo        |      √       |              |             | 
ESP32        |      √       |              |             | 
ESP8266        |      √       |              |             | 
M0        |      √       |              |             | 


## History

- Date 2020-12-29
- Version V0.1


## Credits

Written by fengli(eddard.liu@dfrobot.com), 2020.12.29 (Welcome to our [website](https://www.dfrobot.com/))





