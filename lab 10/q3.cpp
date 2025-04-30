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

        int year = stoi(yearstr);

        cout << "vehicle id: " << id << endl;
        cout << "year as int: " << year << endl;

    }

    inputFile.close();
    return 0;
}