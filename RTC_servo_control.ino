
#include <DS3231.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver allservo = Adafruit_PWMServoDriver();
DS3231  rtc(A4, A5);

#define servoMIN 150
#define servoMAX 600

void setup() {
  Serial.begin(9600);
  allservo.begin();
  rtc.begin();
  allservo.setPWMFreq(60);

//  set time
//  rtc.setDate(21, 11, 2022);
//  rtc.setTime(00, 07, 00);
//  rtc.setDOW(0);
}



void loop(){
  if(rtc.getTimeStr() == "00:10:00") {
    for (int servo = 0; servo < 16; servo++ ) {
      allservo.setPWM(servo, 0, servoMIN);
      Serial.println(servo);
      delay(2000);
      
      Serial.print(rtc.getDOWStr());
      Serial.print(" ");
      Serial.print(rtc.getDateStr());
      Serial.print(" -- ");
      Serial.println(rtc.getTimeStr());
    }
  } if(rtc.getTimeStr() == "00.12.00"){
    for (int servo = 0; servo < 16; servo++ ) {
      allservo.setPWM(servo, 0, servoMAX);
      Serial.println(servo);
      delay(2000);

      Serial.print(rtc.getDOWStr());
      Serial.print(" ");
      Serial.print(rtc.getDateStr());
      Serial.print(" -- ");
      Serial.println(rtc.getTimeStr());
    }
  }
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
  Serial.println(rtc.getTimeStr());
}
