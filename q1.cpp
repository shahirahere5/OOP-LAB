#include <iostream>
#include <string>
using namespace std;

void registerParticipants(string event[],string eventname){
    cout << "enter participants for" << eventname << ":" <<endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "participant " << i+1 << ":";
        cin >> event[i];
    }  
}

bool checkAttendance(string event1[],string event2[],string name){
    for (int i = 0; i < 5; i++)
    {
        if(event1[i] == name){
            return true;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if(event2[i] == name){
            return true;
        }
    }
    return false;
}

int totalDonations(string event1[],string event2[]){
    int count = 0;
    for(int i = 0; i < 5;i++){
        if(!(event1[i] == "")){
            count++;
        }
    }   
    for(int i = 0; i < 5; i++){
        if(!(event2[i] == "")){
            count++;
        }
    }
    return count * 10;
}

void reversePrint(string event[],string name){
    for (int i = 4; i = 0; i--)
    {
        cout << "participants for " << name << "\n" ;
        cout << event[i] << endl;
    }   
    cout << endl;
}

void barChart(string event[],string name){
    cout << "event popularity bar chart:";
    cout  << name << endl;
    for (int i = 0; i < 5; i++)
    {
        if(!(event[i] == "")){
            cout << "*" ;
        }
    }
    cout << endl;
}

int main(){
    string event1[5],event2[5];
    registerParticipants(event1,"event 1");
    registerParticipants(event2,"event 2");

    string name;
    cout << "enter a participant name to check attendance: ";
    cin >> name;
    if(checkAttendance(event1,event2,name)){
        cout << name << " is present in either event." << endl;
    }else{
        cout << name << " is not present in either event." << endl;
    }

    cout << "total donations: $" << totalDonations(event1,event2) << endl;

    reversePrint(event1, "event 1");
    reversePrint(event2, "event 2");

    barChart(event1, "event 1");
    barChart(event2, "event 2");

    return 0;
}