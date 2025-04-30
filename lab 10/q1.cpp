#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream inputFile("vehicles.txt");

    if(!inputFile.is_open()){
        cerr << "error, cant open the file" << endl;
        return 1;
    }

    string line;
    while(getline(inputFile,line)){
        if(line.empty() || line[0] == '/') continue;
        cout << "line read: " << line << endl;
    }

    inputFile.close();
    return 0;
}