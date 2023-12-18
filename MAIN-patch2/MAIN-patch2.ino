

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,12);

int day;
int sec,mins,hrs;
int LDRSensor;


String timeAlarm_range1; 


bool deviceIsActive;
bool dayCompleted;
bool condition1;
bool condition2;

bool mechanismCompleted;


#define LDRpin A0
#define motorPin 6
const trigPin = 9;
const echoPin = 10;
long duration;
int ULTRASONIC_TIME;
float distanceInch;


void setup() {

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(motorPin,OUTPUT);
  lcd.begin();
  lcd.backlight();
  pinMode(6,OUTPUT);
  setTime(0,0,0);
  timeAlarm = cvtTime_to_str(0,0,10);

}

void loop() {

    Serial.begin(9600);
    deviceIsActive = true; 
    
    
    while(deviceIsActive !=false) {

        digitalWrite(trigPin,LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin,LOW);
        duration = pulseIn(echoPin,HIGH);
        distanceInch = duration*0.0133/2;

        String time = cvtTime_to_str(hrs,mins,sec);
        sec++;
        lcd.print(time);
        delay(1000);
        lcd.clear();

        

        Serial.print("\nTime:");
        Serial.print(hrs);
        Serial.print(":");
        Serial.print(mins);
        Serial.print(":");
        Serial.print(sec);



        if(sec == 60) {
            
            mins++;
            sec = 0;
          } if(mins == 60) {
              
              hrs++;
              mins = 0;             
              } if(hrs == 24) {

                  day++;
                  hrs = 0;
                }
                  
                  if(time == timeAlarm) {
                      

                      condition1 = true;
                      
                      Serial.println(" condition completed");

                      doMech(true,true);
                      

                  }
                  if(day == 1) {

                    day = 0;
                    
                    } if (hrs == 0 && mins ==0 && sec == 0) {

                      dayCompleted = false;

                      mechanismCompleted = false;

                      Serial.println("day reset");
                    }
                    int LOW,MID;

                    if(distance < LOW) {

                        lcd.set(0,2);
                        lcd.print("LEVEL:LOW");


                    } else if(distance< MID ) {

                         lcd.set(0,2);
                         lcd.print("LEVEL: MID")
                    } else {

                          lcd.set(0,2);
                          lcd.print("LEVEL: HIGH");

                    }


      
    }

}

void setTime(int hours,int minutes, int seconds) {

    hrs = hours;
    mins = minutes;
    sec = seconds;

};

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
        
        
        
        delay(3000);
        sec +=3; // it equals to lost seconds
        
        digitalWrite(motorPin, LOW);

        lcd.setCursor(0,2); 
        lcd.print("Done. \n");
        delay(2000);
        sec+=2;
        lcd.clear();

    }
    
};