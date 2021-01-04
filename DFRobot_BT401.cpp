/*!
 * @file DFRobot_BT401.cpp
 * @brief Define the basic structure of DFRobot_BT401 class and the implementation of underlying methods
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [Eddard](eddard.liu@dfrobot.com)
 * @version  V1.0
 * @date  2020-12-29
 * @get from https://www.dfrobot.com
 * @url https://github.com/cdjq/DFRobot_BT401
 */

#include <DFRobot_BT401.h>
#include <Arduino.h>
#include <string.h>
#include <stdio.h>


DFRobot_BT401::DFRobot_BT401()
{

}

bool DFRobot_BT401::begin(Stream &s){
  _s = &s;
  if(_s == NULL){
      return false;
  }
  return true;
}

//Set volume 
bool DFRobot_BT401::setVOl(uint8_t vol)
{
  char data[2];
    DBG("\r\n");
  itoa(vol, data, 10);
    DBG("\r\n");
  if(vol > 9){
    sendCMD("CA", data);
  } else{
    sendCMD("CA0", data);
  }
    DBG("\r\n");
  if(readAck() == "OK\r\n"){
    DBG("true\r\n");
    return true;
  } else{
    DBG("false\r\n");
    return false;
  }
}

//Set working mode 
bool DFRobot_BT401::switchFunction(eFunction_t function)
{
  char data[1];
  itoa(function, data, 10);
  sendCMD("CM0", "1");
  if(readAck() == "OK\r\n"){
    return true;
  } else{
    return false;
  }
}

//Playback mode 
bool DFRobot_BT401::setPlayMode(ePlayMode_t mode)
{
  char data[1];
  itoa(mode, data, 10);
  sendCMD("AC0", data);
  if(readAck() == "OK\r\n"){
    return true;
  } else{
    return false;
  }
}

//Play control   Only valid for playback by TF card and U-disk   AA
bool DFRobot_BT401::playControl(ePlayControl_t cmd)
{
  char data[1];
  itoa(cmd, data, 10);
  sendCMD("AA0", data);
  if(readAck() == "OK\r\n"){
    return true;
  } else{
    return false;
  }
}

//Next 
bool DFRobot_BT401::next()
{
  sendCMD("CD");
  if(readAck() == "OK\r\n"){
    return true;
  } else{
    return false;
  }
}

//Last 
bool DFRobot_BT401::last()
{
  sendCMD("CC");
  if(readAck() == "OK\r\n"){
    return true;
  } else{
    return false;
  }
}

//Play the N-th file of the device 
bool DFRobot_BT401::playFileNum(uint16_t number)
{
  char data[5];
  itoa(number, data, 10);
  sendCMD("AB", data);
  if(readAck() == "OK\r\n"){
    return true;
  } else{
    return false;
  }
}

//Repeat all songs in the specified file folder 
bool DFRobot_BT401::playSpecFile(const char* path)
{
  sendCMD("AF", path);
  if(readAck() == "OK\r\n"){
    return true;
  } else{
    return false;
  }
}

//Delete the currently playing file 
bool DFRobot_BT401::delCurFile()
{
  sendCMD("AA08");
  if(readAck() == "OK\r\n"){
    return true;
  } else{
    return false;
  }
}

//Dail a phone number 
bool DFRobot_BT401::callOut(const char *phoneNumber)
{
  sendCMD("BT", phoneNumber);
  if(readAck() == "OK\r\n"){
    return true;
  } else{
    return false;
  }
}

//Calling control 
bool DFRobot_BT401::controltalk(eControltalk_t cmd)
{
  char data[1];
  itoa(cmd, data, 10);
  sendCMD("BA0", data);
  if(readAck() == "OK\r\n"){
    return true;
  } else{
    return false;
  }
}
DFRobot_BT401::eBtStatus DFRobot_BT401::getBtStatus(){

  sendCMD("TS", NULL);
  String status = readAck(7);
  if(status == "TS+00\r\n"){
    return eStandby;
  }else if(status == "TS+01\r\n"){
    return eBTIdle;
  }else if(status == "TS+02\r\n"){
    return ePlaying;
  }else if(status == "TS+03\r\n"){
    return eCalling;
  }else if(status == "TS+04\r\n"){
    return eOnphone;
  }
  
   return eError;
}
String DFRobot_BT401::getTelNumber(){
  delay(50);
  sendCMD("TT", NULL);
  String phone="";
  String data = readAck(0);
  for(uint8_t i = 0;i < data.length()-3;i++){
      phone += data[3+i];
  }
  
  return phone;

}
//Reset 
bool DFRobot_BT401::reset()
{
  sendCMD("CZ");
  if(readAck() == "OK\r\n"){
    return true;
  } else{
    return false;
  }
}

void DFRobot_BT401::sendCMD(const char *cmd, const char *payload)
{
  String data = "";
    DBG("\r\n");
  data += "AT+";
    DBG("\r\n");
  data += cmd;
    DBG("\r\n");
  if(payload != NULL)
     data +=payload;
  data += "\r\n";
    DBG("\r\n");
  uint8_t length = data.length();
    DBG("\r\n");
  uint8_t at[20];
  
  DBG("\r\n");
  while(_s->available()) {
    DBG("\r\n");
    _s->read();
  }
    DBG(data);
  for(uint8_t i=0;i<length;i++)
    at[i] = data[i];
  _s->write(at,length);
   data="";
}

void DFRobot_BT401::sendCMD(const char *cmd)
{
  String data;
  data = "AT+";
  data += cmd;
  data += "\r\n";
  uint8_t length = data.length();
  uint8_t at[20];
  while(_s->available()) {
        _s->read();
  }
  for(uint8_t i=0;i<length;i++)
    at[i] = data[i];
  _s->write(at,length);
}

String DFRobot_BT401::readAck(uint8_t len)
{
  String str="                             ";
  size_t offset = 0,left = len;
  long long curr = millis();
  if(len == 0){
    while(1) {
      if(_s->available()) {
        str[offset]= _s->read();
        left--;
        offset++;
      }
      if(str[offset - 1] == '\n' && str[offset - 2] == '\r') break;
      if(millis() - curr > 1000) {
        return "error";
        break;
      }
    }
  } else {
    while(left) {
      DBG(left);
      if(_s->available()) {
         str[offset]= _s->read();
        left--;
        DBG(str[offset]);
        offset++;
      }
      if(millis() - curr > 1000) {
        return "error";
        
      }
  }
  str[len]=0;
  }
  DBG(str);
  delay(1);
  return str;
}




