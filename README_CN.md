# DFRobot_BT401
- [English Version](./README.md)

蓝牙模块具有蓝牙/ u盘/ tf卡、蓝牙呼叫功能，支持简单清晰的串口控制功能、BLE直通、SPP直通功能。本产品的亮点是双模式蓝牙，这也意味着它可以同时运行蓝牙音频播放和数据传输，大大降低了嵌入式蓝牙在其他产品中的开发难度。



![Product Image](./resources/images/DFR0781.png)


## 产品链接 (https://www.dfrobot.com/product-2177.html)
    DFR0781: Audio & BLE/SPP Pass-through Module - Bluetooth 5.0
## 目录

  * [概述](#概述)
  * [库安装](#库安装)
  * [方法](#方法)
  * [兼容性](#兼容性)
  * [历史](#历史)
  * [创作者](#创作者)
## 概述
1. Play music<br>
2. Answer calls


## 库安装

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## 方法
```C++
  /**
   * @fn begin
   * @brief 初始化函数
   * @param s serial
   * @return 布尔变量,表示初始化结果
   * @retval true 成功
   * @retval false 失败
   */
  bool begin(Stream &s);
  
  /**
   * @fn setBaudRate
   * @brief 设置波特率(需要复位后才能生效,掉电保存)
   * @param baud 9600,19200,38400,57600,115200
   * @return 布尔变量,表示设置结果
   * @retval true 成功
   * @retval false 失败
   */
  bool setBaudRate(uint32_t baud);

  /**
   * @fn setPlayMode
   * @brief 设置播放模式 
   * @param mode ePlayMode_t:SINGLECYCLE,ALLCYCLE,SINGLE,RANDOM,FOLDER
   * @return 布尔变量,表示设置结果
   * @retval true 成功
   * @retval false 失败
   */
  bool setPlayMode(ePlayMode_t mode);

  /**
   * @fn setLED
   * @brief 设置指示灯状态(掉电保存) 
   * @param on 打开或关闭
   * @return 布尔变量,表示设置结果
   * @retval true 成功
   * @retval false 失败
   */
  bool setLED(bool on);
  
  /**
   * @fn setPrompt
   * @brief 设置提示音状态(掉电保存) 
   * @param on 打开或关闭
   * @return 布尔变量,表示设置结果
   * @retval true 成功
   * @retval false 失败
   */
  bool setPrompt(bool on);
  
  /**
   * @fn setVol
   * @brief 设置音量
   * @param vol 0-30
   * @return 布尔变量,表示设置结果
   * @retval true 成功
   * @retval false 失败
  */
  bool setVol(uint8_t vol);
  
  /**
   * @fn switchFunction
   * @brief 设置工作模式
   * @param function eFunction_t:MUSIC,RECORD,UFDISK
   * @return 布尔变量,表示操作结果
   * @retval true 成功
   * @retval false 失败
   */
  bool switchFunction(eFunction_t function);
  
  /**
   * @fn next
   * @brief 下一曲 
   * @return 布尔变量,表示操作结果
   * @retval true 成功
   * @retval false 失败
   */
  bool next();
  
  /**
   * @fn last
   * @brief 上一曲 
   * @return 布尔变量,表示操作结果
   * @retval true 成功
   * @retval false 失败
   */
  bool last();
  
  /**
   * @fn start
   * @brief 开始播放歌曲 
   * @return 布尔变量,表示操作结果
   * @retval true 成功
   * @retval false 失败
   */
  bool start();
  
  /**
   * @fn pause
   * @brief 暂停 
   * @return 布尔变量,表示操作结果
   * @retval true 成功
   * @retval false 失败
   */
  bool pause();
  
  /**
   * @fn delCurFile
   * @brief 删除正在播放的文件 
   * @return 布尔变量,表示操作结果
   * @retval true 成功
   * @retval false 失败
   */
  bool delCurFile();
  
  /**
   * @fn playSpecFile
   * @brief 播放特定的文件
   * @return 布尔变量,表示操作结果
   * @retval true 成功
   * @retval false 失败
   */
  bool playSpecFile(String str);
  
  /**
   * @fn playFileNum
   * @brief 通过编号播放特定的文件
   * @param num 文件标号,能通过getCurFileNumber()获取
   * @return 布尔变量,表示操作结果
   * @retval true 成功
   * @retval false 失败
   */
  bool playFileNum(int16_t num);

  /**
   * @fn getVol
   * @brief 获取音量等级 
   * @return 音量
   */
  uint8_t getVol();

  /**
   * @fn getPlayMode
   * @brief 获取播放模式 
   * @return Play Mode
   */
  ePlayMode_t getPlayMode();
  
  /**
   * @fn getCurFileNumber
   * @brief 获取正在播放歌曲的文件编号 
   * @return 编号
   */
  uint16_t getCurFileNumber();
  
  /**
   * @fn getTotalFile
   * @brief 获取所有文件的个数
   * @return 文件个数
   */
  uint16_t getTotalFile();
  
  /**
   * @fn getCurTime
   * @brief 获取当前正在播放歌曲的时间节点
   * @return 时间节点
   */
  uint16_t getCurTime();
  
  /**
   * @fn getTotalTime
   * @brief 获取当前播放歌曲的总时长
   * @return 总时长
   */
  uint16_t getTotalTime();
  
  /**
   * @fn getFileName
   * @brief 获取当前正在播放歌曲的文件名 
   * @return 文件名
   */
  String   getFileName();
  
  /**
   * @fn enableAMP
   * @brief 使能功放芯片
   * @return 布尔变量,表示操作结果
   * @retval true 成功
   * @retval false 失败
   */
  bool enableAMP();
  
  /**
   * @fn disableAMP
   * @brief 关闭功放芯片,静音
   * @return 布尔变量,表示操作结果
   * @retval true 成功
   * @retval false 失败
   */
  bool disableAMP();
  
  /**
   * @fn fastForward
   * @brief 歌曲播放快进
   * @param second  快进时间(单位: 秒) 
   * @return 布尔变量,表示操作结果
   * @retval true 成功
   * @retval false 失败
   */
  bool fastForward(uint16_t second);
  
  /**
   * @fn fastReverse
   * @brief 歌曲播放快退
   * @param second  快退时间(单位: 秒)
   * @return 布尔变量,表示操作结果
   * @retval true 成功
   * @retval false 失败
   */
  bool fastReverse(uint16_t second);
  
  /**
   * @fn setPlayTime
   * @brief 使当前播放歌曲在某一个时间节点播放
   * @param second  时间节点
   * @return 布尔变量,表示操作结果
   * @retval true 成功
   * @retval false 失败
   */
  bool setPlayTime(uint16_t second);
```

## 兼容性

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno        |      √       |              |             | 
Mega2560        |      √       |              |             | 
Leonardo        |      √       |              |             | 
ESP32        |      √       |              |             | 
ESP8266        |      √       |              |             | 
M0        |      √       |              |             | 


## 历史

- 2020/12/29 - Version 1.0.0 released.

## 创作者

Written by eddard(eddard.liu@dfrobot.com), 2020.12.29 (Welcome to our [website](https://www.dfrobot.com/))
