#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream outFile("sensor_log.txt");

    if(!outFile){
        cerr << "error,cant open file" << endl;
        return 1;
    }

    outFile << "Sensor 1: Temperature = 23.5°C" << endl;
    cout << "Current write position: " << outFile.tellp() << endl;

    outFile << "Sensor 2: Pressure = 101.3kPa" << endl;
    cout << "Current write position: " << outFile.tellp() << endl;

    outFile << "Sensor 3: Humidity = 60%" << endl;
    cout << "Current write position: " << outFile.tellp() << endl;

    outFile.close();
    return 0;
}