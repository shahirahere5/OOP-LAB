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
        string type,id,name,year,extradata,certification;

        getline(ss,type,',');
        getline(ss,id,',');
        getline(ss,name,',');
        getline(ss,year,',');
        getline(ss,extradata,',');
        getline(ss,certification,',');

        cout << "type: " << type << endl;
        cout << "id: " << id << endl;
        cout << "name: " << name << endl;
        cout << "year: " << year << endl;
        cout << "extradata: " << extradata << endl;
        cout << "certification: " << certification << endl;
    }

    inputFile.close();
    return 0;
}