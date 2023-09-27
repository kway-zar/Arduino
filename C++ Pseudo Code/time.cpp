#include <iostream>

#include <windows.h>

#include <string>

using namespace std;

int day;

int sec,mins,hrs;
string timeAlarm;

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

void doMech(bool condition ) {

    //mechanism here
};



int main() {
  
    setTime(1,2,3);
    timeAlarm = cvtTime_to_str(1,2,10); // set Alarm Time

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

                if(time == timeAlarm) {

                    doMech(true);

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