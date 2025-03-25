#include <iostream>
#include <string>
using namespace std;

class Device {
public:
    int deviceID;
    string deviceName;
    bool status;
    string location;

    Device(int id, string name, bool stat, string loc)
        : deviceID(id), deviceName(name), status(stat), location(loc) {}

    virtual void turnOn() {
        status = true;
        cout << "Turned on" << endl;
    }

    void turnOff() {
        status = false;
        cout << "Turned off" << endl;
    }

    virtual bool getStatus() {
        return status;
    }

    virtual void displayInfo() {
        cout << "Device ID: " << deviceID << endl;
        cout << "Device Name: " << deviceName << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
        cout << "Location: " << location << endl;
    }
};

class Light : public Device {
public:
    int brightnessLevel;
    string colorMode;

    Light(int id, string name, bool stat, string loc, int brightness, string color)
        : Device(id, name, stat, loc), brightnessLevel(brightness), colorMode(color) {}

    void displayInfo() {
        Device::displayInfo();
        cout << "Brightness Level: " << brightnessLevel << endl;
        cout << "Color Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device {
public:
    double temperature;
    string mode;
    double targetTemperature;

    Thermostat(int id, string name, bool stat, string loc, double temp, string m, double target)
        : Device(id, name, stat, loc), temperature(temp), mode(m), targetTemperature(target) {}

    bool getStatus() {
        cout << "Current Temperature: " << temperature << "°C" << endl;
        return status;
    }
};

class SecurityCameras : public Device {
public:
    int resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

    SecurityCameras(int id, string name, bool stat, string loc, int res, bool recording, bool nightVision)
        : Device(id, name, stat, loc), resolution(res), recordingStatus(recording), nightVisionEnabled(nightVision) {}

    void turnOn() {
        Device::turnOn();
        recordingStatus = true;
        cout << "Recording started." << endl;
    }
};

class SmartPlug : public Device {
private:
    float powerConsumption;
    string timerSetting;

public:
    SmartPlug(int id, string name, bool stat, string loc, float power, string timer)
        : Device(id, name, stat, loc), powerConsumption(power), timerSetting(timer) {}

    void turnOff() {
        Device::turnOff();
        cout << "Power Consumption: " << powerConsumption << " kWh logged." << endl;
    }

    void displayInfo() {
        Device::displayInfo();
        cout << "Power Consumption: " << powerConsumption << " kWh" << endl;
        cout << "Timer Setting: " << timerSetting << endl;
    }
};

int main() {
    Light light(1, "Living Room Light", false, "Living Room", 75, "Warm White");
    Thermostat thermo(2, "Living Room Thermostat", false, "Living Room", 22.5, "Heating", 24.0);
    SecurityCameras camera(3, "Front Door Camera", false, "Front Door", 1080, false, true);
    SmartPlug plug(4, "Kitchen Plug", false, "Kitchen", 1.5, "18:00-22:00");

    light.turnOn();
    light.displayInfo();

    thermo.turnOn();
    thermo.getStatus();

    camera.turnOn();
    camera.displayInfo();

    plug.turnOn();
    plug.turnOff();
    plug.displayInfo();

    return 0;
}