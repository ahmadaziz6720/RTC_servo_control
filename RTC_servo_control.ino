#include <DS3231.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver allservo = Adafruit_PWMServoDriver();
DS3231  rtc(A4, A5);

#define servoMIN 150
#define servoMAX 600

String coba = "16:41:00";
String coba2 = "16:42:00";

void setup() {
  Serial.begin(9600);
  allservo.begin();
  rtc.begin();
  allservo.setOscillatorFrequency(27000000);
  allservo.setPWMFreq(60);

//  uncomment to set time
//  rtc.setDate(21, 11, 2022);
//  rtc.setTime(00, 07, 00);
//  rtc.setDOW(0);
}

void loop(){
  if(String(rtc.getTimeStr()) == String(coba)) {
    for (int servo = 0; servo < 16; servo++ ) {
      allservo.setPWM(servo, 0, 325);
      Serial.println(servo);
      delay(500);
      
      Serial.print(rtc.getDOWStr());
      Serial.print(" ");
      Serial.print(rtc.getDateStr());
      Serial.print(" -- ");
      Serial.println(rtc.getTimeStr());
    }
    Serial.println("masuk1");
  }
  if(String(rtc.getTimeStr()) == String(coba2)){
    for (int servo = 0; servo < 16; servo++ ) {
      allservo.setPWM(servo, 0, servoMIN);
      Serial.println(servo);
      delay(500);

      Serial.print(rtc.getDOWStr());
      Serial.print(" ");
      Serial.print(rtc.getDateStr());
      Serial.print(" -- ");
      Serial.println(rtc.getTimeStr());
    }
    Serial.println("masuk2");
  }
//  Serial.print(rtc.getDOWStr());
//  Serial.print(" ");
//  Serial.print(rtc.getDateStr());
//  Serial.print(" -- ");
  Serial.println(rtc.getTimeStr());
}
