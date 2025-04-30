#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int safe_stoi(const string& str){
    try{
        return stoi(str);
    }catch(const invalid_argument&){
        cerr << "invalid integer string: " << str << endl;
        return -1;
    }catch(const out_of_range&){
        cerr << "integer out of range: " << str << endl;
        return -1;
    }
}

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
        string type, id, name, yearstr, extradata, certif;

        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, yearstr, ',');
        getline(ss, extradata, ',');
        getline(ss, certif, ',');

        if(type == "AutonomousCar"){
            size_t pos = extradata.find(':');
            if(pos != string::npos){
                string versionstr = extradata.substr(pos + 1);
                float softwareVersion = stof(versionstr);
                cout << "autonomous car id: " << id << endl;
                cout << "software version: " << softwareVersion << endl;
            }
        } else if(type == "ElectricVehicle"){
            size_t pos = extradata.find(":");
            if(pos != string::npos){
                string batterystr = extradata.substr(pos + 1);
                int batteryCap = safe_stoi(batterystr);
                if (batteryCap != -1) {  // Only output if valid conversion
                    cout << "electric vehicle id: " << id << endl;
                    cout << "battery capacity: " << batteryCap << endl;
                }
            }
        } else if(type == "HybridTruck"){
            size_t posColon = extradata.find(":");
            size_t posPipe = extradata.find('|');

            if(posColon != string::npos && posPipe != string::npos){
                string cargostr = extradata.substr(posColon + 1, posPipe - posColon - 1);
                int cargo = safe_stoi(cargostr);

                string batterystr = extradata.substr(posPipe + 1);
                int battery = safe_stoi(batterystr);

                if (cargo != -1 && battery != -1) {  // Ensure valid conversions
                    cout << "hybrid truck id: " << id << endl;
                    cout << "cargo: " << cargo << endl;
                    cout << "battery capacity: " << battery << endl;
                }
            } else {
                cerr << "Invalid HybridTruck format for id: " << id << endl;
            }
        } else {
            cout << "unknown vehicle type: " << type << endl;
        }
    }

    inputFile.close();
    return 0;
}
