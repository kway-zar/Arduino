

int day;

int sec,mins,hrs;
String timeAlarm_range1; //this are also strings
String timeAlarm_range2;

bool deviceIsActive;
bool dayCompleted;

int LDRSensor;
int LightRange1;
int LightRange2;

bool doMechanism;

#define pin1 4




void setup() {

  pinMode(pin1, OUTPUT);


}

void loop() {

    Serial.begin(9600);
    
    deviceIsActive = true;
    
    setTime(1,2,0)

    while(deviceIsActive !=false) {
        
        ;
        timeAlarm_range1 = cvtTime_to_str(1,2,3);
        timeAlarm_range2 = cvtTime_to_str(1,2,5);

        sec++;
        delay(1000);

        String time = cvtTime_to_str(hrs,mins,sec);

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
                  if(time == timeAlarm_range1 || time == timeAlarm_range2) {

                      bool condition1 = true;

                      

                      digitalWrite(pin1, HIGH);

                      // if(LDRSensor <= LightRange1 && LDRSensor >= LightRange2) {


                      // }
                      
                  }
                  if(day == 1) {

                    dayCompleted = true;
                    day = 0;
                    } if (sec == 2) {

                      dayCompleted = false;
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

};

void doMech(bool condition1, bool condition2) {
    if(condition1 == true && condition2 == true) {


    }

};


