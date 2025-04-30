#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream outFile("config.txt");

    if(!outFile){
        cerr << "error,cant open file" << endl;
        return 1;
    }

    outFile << "AAAAA" << endl;
    outFile << "BBBBB" << endl;
    outFile << "CCCCC" << endl;

    outFile.close();

    fstream file("config.txt",ios::in | ios::out);

    if(!file){
        cerr << "error,cant open file" << endl;
        return 1;
    }

    file.seekp(7,ios::beg);
    file.write("XXXXX",5);

    file.close();

    ifstream inFile("config.txt");

    if(!inFile){
        cerr << "error,cant open file" << endl;
        return 1;
    }

    string line;
    while(getline(inFile,line)){
        cout << line << endl;
    }

    inFile.close();

    return 0;
}