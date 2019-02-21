#include <LiquidCrystal.h>
int motion_1 = 8;
#define led 13

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


int sensor_1=LOW;                   
int sensor_2=LOW;
int sensor_3=LOW;
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
   delay(1600);
  if (sensor_1_flag != 1) {
    sensor_1 = digitalRead(motion_1);           //read the value which SENSOR gets through pin 12 and put the value in sansor variable.
    Serial.println(sensor_1);
    
    if (sensor_1 == HIGH )
    {
      delay(1500);
      sensor_1_flag=1;
      sensor_1=LOW;
    }
  }
    //delay(300);
  if (sensor_2_flag != 1) {
    sensor_2 = digitalRead(motion_1);
    Serial.println(sensor_2);
  
    if (sensor_2 == HIGH )
    {
      delay(1500);
      sensor_2_flag=1;
      sensor_2=LOW;
    }
  }
  //delay(300);
  if (sensor_3_flag != 1) {
    sensor_3 = digitalRead(motion_1);
   
    Serial.println(sensor_3);
    if (sensor_3 == HIGH )
    {
       delay(1500);
       sensor_3_flag=1;
       sensor_3=LOW;
    }
  }


  if (sensor_3_flag == 1 &&  sensor_1_flag == 1 &&  sensor_2_flag == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("Intruder Alert");
    Serial.println("Motion detected");
    while (true) {
      digitalWrite(led, HIGH);
      //delay(200);
     sensor_3_flag=0;
     sensor_1_flag=0;
     sensor_2_flag=0;
    }
  } else
  {
   // Serial.println("Motion NOT detected");
    digitalWrite(led, LOW);
    //delay(800);
    
  }


}
