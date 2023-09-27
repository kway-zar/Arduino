#include <iostream>

#include <windows.h>

#include <string>

using namespace std;

int day;

int sec,mins,hrs;

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

void doMech(bool condition, int day ) {
    
    //mechanism here
};



int main() {


    
    setTime(1,2,3);

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

        if(day == 1) {
            
            dayCompleted = true;
            day = 0;

            doMechanism = true;

        }
        
    }

    return 0;
}