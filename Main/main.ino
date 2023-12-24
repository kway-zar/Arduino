
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,12);
RTC_DS3231 rtc;


int LDRSensor;

String WaterLevel;
String timeAlarm; 


bool deviceIsActive;

#define LDRpin A0
#define motorPin 6
const int trigPin = 9;
const  int echoPin = 10;
long duration;
int ULTRASONIC_TIME;

float distanceInch;


void setup() {

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(motorPin,OUTPUT);

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  lcd.begin(16,2);
  lcd.backlight();
  pinMode(6,OUTPUT);
  timeAlarm = cvtTime_to_str(9,2,30);
  rtc.begin();

}

void loop() {

    Serial.begin(9600);
    deviceIsActive = true; 
    
    
    while(deviceIsActive !=false) {

        DateTime now = rtc.now();
        
        duration = pulseIn(echoPin,HIGH);
        distanceInch = duration*0.0133/2;

        String time = cvtTime_to_str(now.hour(),now.minute(),now.second());
        
        lcd.print(time);
        lcd.setCursor(0,1);
        lcd.print(WaterLevel);
        delay(1000);
        lcd.clear();

        


        if(time == timeAlarm) {
            
            Serial.println(" condition completed");

            doMech(true);
            

        }
        
          int LOW_LEVEL, MID_LEVEL;
          LOW_LEVEL = 7;
          MID_LEVEL = 5;

          if(distanceInch > LOW_LEVEL) {

            WaterLevel = "LEVEL:LOW";

          } else if(distanceInch > MID_LEVEL ) {
              WaterLevel = "LEVEL:MID";

          } else if(distanceInch < 5){

              WaterLevel = "LEVEL:HIGH";
          }


      
    }

}


String cvtTime_to_str(int hrs, int mins, int sec) {

    String cnvertdSTR;
    String hours = String(hrs);
    String minutes = String(mins);
    String seconds = String(sec);

    cnvertdSTR = hours + ":" + minutes + ":" + sec;

    return cnvertdSTR;

};

void doMech(bool condition1) {
    if(condition1 == true) {
        
        lcd.print("Engaging...\n");
        digitalWrite(motorPin,HIGH);

        dayCompleted = true;
        mechanismCompleted = true;
        
        delay(20000);
         // it equals to lost seconds
        
        digitalWrite(motorPin, LOW);

        lcd.setCursor(0,2); 
        lcd.print("Done. \n");
        delay(2000);
        
        lcd.clear();

    }
    
};
