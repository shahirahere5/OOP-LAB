#include <iostream>
using namespace std;

class WeatherSensor{
    public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
};

class Thermometer: public WeatherSensor{
    public:
    void readData() override{
        cout << "reading data from thermometer" << endl;
    }

    void displayReport() override{
        cout << "displaying report of thermometer" << endl;
    }
};

class Barometer: public WeatherSensor{
    public:
    void readData() override{
        cout << "reading data from barometer" << endl;
    }

    void displayReport() override{
        cout << "displaying report of barometer" << endl;
    }
};

int main(){
    Thermometer t1;
    Barometer b1;

    t1.readData();
    t1.displayReport();

    b1.readData();
    b1.displayReport();

    return 0;
}