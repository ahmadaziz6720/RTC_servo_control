
#include <DS3231.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver srituhobby = Adafruit_PWMServoDriver();
DS3231  rtc(A4, A5);

#define servoMIN 150
#define servoMAX 600

void setup() {
  Serial.begin(9600);
  srituhobby.begin();
  rtc.begin();
  srituhobby.setPWMFreq(60);

  // set time
  //  rtc.setDate(07, 4, 2018);
  //  rtc.setTime(22, 00, 00);
  //  rtc.setDOW(6);
}

void loop() {
  for (int servo = 0; servo < 4; servo++ ) {
    srituhobby.setPWM(servo, 0, servoMIN);
    Serial.println(servo);
    delay(300);
  }

  for (int servo = 3; servo >= 0; servo-- ) {
    srituhobby.setPWM(servo, 0, servoMAX);
    Serial.println(servo);
    delay(300);
  }

  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  Serial.println(rtc.getTimeStr());
}
