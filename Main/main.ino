

int day;
int sec,mins,hrs;
int LDRSensor;

String timeAlarm_range1; //this are also strings
String timeAlarm_range2;
String timeAlarm_range3;

bool deviceIsActive;
bool dayCompleted;
bool condition1;
bool condition2;

bool mechanismCompleted;


#define LDRpin A0




void setup() {

  pinMode(2,OUTPUT);


}

void loop() {

    Serial.begin(9600);
    deviceIsActive = true;

    LDRSensor = analogRead(LDRpin);
 
    setTime(23,59,50);

    while(deviceIsActive !=false) {

        

        timeAlarm_range1 = cvtTime_to_str(0,0,2);
        timeAlarm_range2 = cvtTime_to_str(1,2,10);

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
                      

                      condition1 = true;
                      
                      Serial.println(" condition completed");
                      

                       if(LDRSensor > 700 || LDRSensor <= 800) {

                          condition2 = true;
                          Serial.println("condtion2 completed");

                          doMech(condition1,condition2);



                       }
                      
                  }
                  if(day == 1) {

                    day = 0;
                    
                    } if (hrs == 0 && mins ==0 && sec == 0) {

                      dayCompleted = false;

                      mechanismCompleted = false;

                      Serial.println("day reset");
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

void doMech(bool condition1, bool condition2) {
    if(condition1 == true && condition2 == true) {

        digitalWrite(2,HIGH);

        dayCompleted = true;
        mechanismCompleted = true;
        

        delay(3000);
        sec +=3; // it equals to lost seconds
        digitalWrite(2, LOW);

    }

};


