#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    ifstream inputFile("vehicles.txt");

    if(!inputFile.is_open()){
        cerr << "error, cant open file" << endl;
        return 1;
    }

    string line;
    while(getline(inputFile,line)){
        if(line.empty() || line[0] == '/') continue;

        istringstream ss(line);
        string type,id,name,yearstr,extradata,certif;

        getline(ss,type,',');
        getline(ss,id,',');
        getline(ss,name,',');
        getline(ss,yearstr,',');
        getline(ss,extradata,',');
        getline(ss,certif,',');

        if(type == "AutonomousCar"){
            size_t pos = extradata.find(':');
            if(pos != string::npos){
                string versionstr = extradata.substr(pos + 1);
                float softwareVersion = stof(versionstr);
                cout << "autonomous car id: " << id << endl;
                cout << "software version: " << softwareVersion << endl;
            }
        }else if(type == "ElectricVehicle"){
            size_t pos = extradata.find(":");
            if(pos != string::npos){
                string batterystr = extradata.substr(pos + 1);
                int batteryCap = stoi(batterystr);
                cout << "electric vehicle id: " << id << endl;
                cout << "battery capacity: " << batteryCap << endl;
            }
        }
    }    

    inputFile.close();
    return 0;
}