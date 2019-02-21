#include <LiquidCrystal.h>
int motion_1 = 8;
#define led 13
int i = 0, j = 0, k = 0;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int pirState1 = LOW; // we start, assuming no motion detected
int pirState2 = LOW; // we start, assuming no motion detected
int pirState3 = LOW; // we start, assuming no motion detected
int sensor_1;                   //sensor_2=LOW,sensor_3=LOW;
int sensor_2;
int sensor_3;
int sensor_1_flag = 0;
int sensor_2_flag = 0;
int sensor_3_flag = 0;


void setup() {
  // put your setup code here, to run once:


  pinMode(led, OUTPUT);                                      // led set at pin 13
  pinMode(motion_1, INPUT);                                   // sensor set at pin 8
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   
  if (sensor_1_flag != 1) {
    sensor_1 = digitalRead(motion_1);           //read the value which SENSOR gets through pin 12 and put the value in sansor variable.
    Serial.println(sensor_1);
    delay(500);
    if (sensor_1 == HIGH )
    {
      if (i == 3) {
        pirState2 = HIGH;
        pirState3 = HIGH;
        sensor_2_flag = 1;
        sensor_3_flag = 1;
      }
      if (i == 2)
      {
        if (sensor_2 != HIGH && sensor_3 == HIGH)
        {
          pirState2 = HIGH;
          sensor_2_flag = 1;
          sensor_3_flag = 1;
        }
        if (sensor_2 == HIGH && sensor_3 != HIGH)
        {
          pirState3 = HIGH;
          sensor_2_flag = 1;
          sensor_3_flag = 1;
        }
        if (sensor_2 != HIGH && sensor_3 != HIGH)
        {
          pirState3 = HIGH;
          sensor_3_flag = 1;
        }
        i = 3;
      }
      if (i == 1)
      {
        if (sensor_2 != HIGH && sensor_3 == HIGH)
        {
          pirState2 = HIGH;
          sensor_2_flag = 1;
          sensor_3_flag = 1;
        }
        if (sensor_2 == HIGH && sensor_3 != HIGH)
        {
          pirState3 = HIGH;
          sensor_2_flag = 1;
          sensor_3_flag = 1;
        }
        if (sensor_2 != HIGH && sensor_3 != HIGH)
        {
          pirState2 = HIGH;
          sensor_2_flag = 1;
        }
        i = 2;
      }
      if (i == 0) {
        i = 1;
      }
      if (pirState1 == LOW) {

        pirState1 = HIGH;
        sensor_1_flag = 1; //-------

      }
    }
  }
  if (sensor_2_flag != 1) {
    sensor_2 = digitalRead(motion_1);
    Serial.println(sensor_2);
    delay(500);
    if (sensor_2 == HIGH )
    {

      if (j == 3) {
        pirState1 = HIGH;
        pirState3 = HIGH;
        sensor_1_flag = 1;
        sensor_3_flag = 1;
      }

      if (j == 2)
      {
        if (sensor_1 != HIGH && sensor_3 == HIGH)
        {
          pirState1 = HIGH;
          sensor_1_flag = 1;
          sensor_3_flag = 1;
        }
        if (sensor_1 == HIGH && sensor_3 != HIGH)
        {
          pirState3 = HIGH;
          sensor_1_flag = 1;
          sensor_3_flag = 1;
        }
        if (sensor_1 != HIGH && sensor_3 != HIGH)
        {
          pirState3 = HIGH;
          sensor_3_flag = 1;
        }
        j = 3;
      }
      if (j == 1)
      {
        if (sensor_1 != HIGH && sensor_3 == HIGH)
        {
          pirState1 = HIGH;
          sensor_1_flag = 1;
          sensor_3_flag = 1;
        }
        if (sensor_1 == HIGH && sensor_3 != HIGH)
        {
          pirState3 = HIGH;
          sensor_1_flag = 1;
          sensor_3_flag = 1;
        }
        if (sensor_1 != HIGH && sensor_3 != HIGH)
        {
          pirState1 = HIGH;
          sensor_1_flag = 1;
        }
        j = 2;
      }
      if (j == 0) {
        j = 1;
      }
      if (pirState2 == LOW) {
        pirState2 = HIGH;
        sensor_2_flag = 1;
      }
    }
  }

  if (sensor_3_flag != 1) {
    sensor_3 = digitalRead(motion_1);
    delay(500);
    Serial.println(sensor_3);
    if (sensor_3 == HIGH )
    {
      if (k == 3) {
        pirState2 = HIGH;
        pirState1 = HIGH;
        sensor_2_flag = 1;
        sensor_1_flag = 1;
      }

      if (k == 2)
      {
        if (sensor_1 != HIGH && sensor_2 == HIGH)
        {
          pirState1 = HIGH;
          sensor_1_flag = 1;
          sensor_2_flag = 1;
        }
        if (sensor_1 == HIGH && sensor_2 != HIGH)
        {
          pirState2 = HIGH;
          sensor_1_flag = 1;
          sensor_2_flag = 1;
        }
        if (sensor_1 != HIGH && sensor_2 != HIGH)
        {
          pirState2 = HIGH;
          sensor_2_flag = 1;
        }
        k = 3;
      }
      if (k == 1)
      {
        if (sensor_1 != HIGH && sensor_2 == HIGH)
        {
          pirState1 = HIGH;
          sensor_1_flag = 1;
          sensor_2_flag = 1;
        }
        if (sensor_1 == HIGH && sensor_2 != HIGH)
        {
          pirState2 = HIGH;
          sensor_1_flag = 1;
          sensor_2_flag = 1;
        }
        if (sensor_1 != HIGH && sensor_2 != HIGH)
        {
          pirState1 = HIGH;
          sensor_1_flag = 1;
        }
        k = 2;
      }
      if (k == 0) {
        k = 1;
      }
      if (pirState3 == LOW) {
        pirState3 = HIGH;
        sensor_3_flag = 1;
      }
    }
  }


  if ( pirState1 == HIGH &&  pirState2 == HIGH &&  pirState3 == HIGH)
  {
    pirState1 == LOW;
    pirState2 == LOW;
    pirState3 == LOW;
    lcd.setCursor(0, 0);
    lcd.print("Intruder Alert");
    Serial.println("Motion detected");
    while (true) {
      digitalWrite(led, HIGH);
      delay(500);
    }
  } else
  {
    //Serial.println("Motion NOT detected");
    digitalWrite(led, LOW);
    delay(500);
  }


}
