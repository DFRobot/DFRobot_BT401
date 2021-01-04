/*!
 * @file answerCall.ino.ino
 * @brief Get incoming call information 
 * @n Experiment Phenomenon：Print phone number and answer the phone when a call comes 
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
  Serial.begin(115200);
  btSerial.begin(115200);
  /*Delay 2s for the BT401 to start*/
  delay(2000);
  while(!bt.begin(btSerial)){
    Serial.println("Init failed, please check wire connection!");
    delay(1000);
  }
  bt.setVOl(30);
  bt.switchFunction(bt.eBluetooth);
}

void loop(){
    //If a call comes, print phone number and answer it 
    if(bt.getBtStatus() == bt.eCalling){
      Serial.println(bt.getTelNumber());
      delay(1000);
      //Answer
      bt.controltalk(bt.eAnswer);
      //Refuse to answer
      //bt.controltalk(bt.eRejectCall);
    }
    //If you are on the phone, print the incoming phone number 
    if(bt.getBtStatus() == bt.eOnphone){
      Serial.print("On the phone:");
      Serial.println(bt.getTelNumber());
      delay(1000);
      //Hang Up
      //bt.controltalk(bt.eHangUp);
    }
}
