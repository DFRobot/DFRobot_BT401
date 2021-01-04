/*!
 * @file playMusic.ino.ino
 * @brief Play song in TF card 
 * @n Experiment Phenomenon：play music and do the related actions 
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [Eddard](Eddard.liu@dfrobot.com)
 * @version  V1.0
 * @date  2020-12-29
 * @get from https://www.dfrobot.com
 * @url https://github.com/cdjq/DFRobot_ID809
*/

#include <DFRobot_BT401.h>
#include <SoftwareSerial.h>

SoftwareSerial btSerial(2, 3);  //RX TX

DFRobot_BT401 bt;

void setup(){
  btSerial.begin(115200);
  /*Delay 2s for the BT401 to start*/
  delay(2000);
  while(!bt.begin(btSerial)){
    Serial.println("Init failed, please check wire connection!");
    delay(1000);
  }
  bt.setVOl(30);
  bt.switchFunction(bt.eTFCard);
  bt.setPlayMode(bt.eDeviceCycle);
}

void loop(){
  //Play
  bt.playControl(bt.ePlay);
  delay(3000);
  //Pause 
  bt.playControl(bt.ePause);
  delay(3000);
  //Next 
  bt.next();
  delay(3000);
  //Last 
  bt.last();
  delay(3000);
  //Play song in the first file
  bt.playFileNum(1);
  while(1);
  /*Delete the currently playing file*/
  //bt.delCurFile();
}
