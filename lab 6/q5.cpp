#include <iostream>
#include <string>
using namespace std;

class Device{
    protected:
    int deviceID;
    bool status;

    public:
    Device(int id, bool s){
        deviceID = id;
        status = s;
    }

    void displayDetails(){
        cout << "device id: " << deviceID << endl;
        cout << "status: " << status << endl;
    }
};

class SmartPhone: public Device{
    protected:
    float screenSize;

    public:
    SmartPhone(int id,bool s,float ss): Device(id,s){
        screenSize = ss;
    }

    void displayDetails(){
        Device::displayDetails();
        cout << "screen size: " << screenSize << endl;
    }
};

class SmartWatch: public Device{
    protected:
    bool heartRateMonitor;

    public:
    SmartWatch(int id,bool s,bool h):Device(id,s){
        heartRateMonitor = h;
    }

    void displayDetails(){
        Device::displayDetails();
        cout << "heart rate monitor: " << heartRateMonitor << endl;
    }
};

class SmartWearable: public SmartPhone,public SmartWatch{
    protected:
    int stepCounter;

    public:
    SmartWearable(int id,bool s,float ss,bool h,int sc): SmartPhone(id,s,ss),SmartWatch(id,s,h){
        stepCounter = sc;
    }

    void displayDetails(){
        SmartPhone::displayDetails();
        cout << "heart rate monitor: " << (heartRateMonitor ? "yes" : "no") << endl;
        cout << "step counter: " << stepCounter << endl;
    }
};

int main(){
    SmartWearable s1(101,false,7.0,true,100);
    s1.displayDetails();
    return 0;
}