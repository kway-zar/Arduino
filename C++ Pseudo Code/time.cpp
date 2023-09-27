#include <iostream>

#include <windows.h>

#include <string>

using namespace std;

int day;

int sec,mins,hrs;
string timeAlarm_range1;
string timeAlarm_range2;

bool deviceIsActive;
bool dayCompleted;

bool doMechanism;


void setTime(int hours, int minutes, int seconds) {
    
    hrs = hours;
    mins = minutes;
    sec = seconds;

};

string cvtTime_to_str(int hrs,int mins, int sec) {

    string cnvertdSTR;
    string hour = to_string(hrs);
    string minutes = to_string(mins);
    string seconds = to_string(sec);

    cnvertdSTR = hour + ":" + minutes + ":" + seconds;

    return cnvertdSTR;
    
};

void doMech(bool condition1, bool condition2 ) {

    if(condition1 == true && condition2 == true) {
    //mechanism here
    
    }
    
};



int main() {
  
    setTime(1,2,11);
    timeAlarm_range1 = cvtTime_to_str(1,2,10);
    timeAlarm_range2 = cvtTime_to_str(1,2,20); // set Alarm Time Range


    deviceIsActive = true;

    while(deviceIsActive != false) {

        cout <<"\rTime:" << hrs<< ":" << mins << ":" << sec<< "   ";

        sec++;
        Sleep(1000); //its in milliseconds

        if(sec == 60){
            
            mins++;
            sec = 00;

            } if(mins == 60) {

                hrs++;
                mins = 00;

                } if(hrs == 24) {

                    day++;
                    hrs = 00;
                    
                }
                string time = cvtTime_to_str(hrs,mins,sec);

                if(time == timeAlarm_range1 || time == timeAlarm_range2) {

                    bool condition1 = true;

                    // if(LDRSensor >= ThisBrightnessValueInt(600) || LDRSensor <= ThisBrightnessValue(800)) {

                        // bool condition2 = true;





                    // }
                    


                    //add sleep with randomness
                     
                    

                }

        if(day == 1) {
            
            dayCompleted = true;
            day = 0;
            
            if(sec==2) {

                dayCompleted = false; //means that it's the day after

            }
        }
        
    }

    return 0;
}