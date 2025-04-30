#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream outFile("large_log.txt");
    if(!outFile){
        cerr << "error,cant open file" << endl;
        return 1;
    }

    outFile << "line 1: start\n" ;
    outFile << "line 2: data\n" ;
    outFile << "line 3: more\n";
    outFile.close();

    ifstream inFile("large_log.txt");
    if(!inFile){
        cerr << "error,cant open file" << endl;
        return 1;
    }

    char buffer[11];
    inFile.read(buffer,10);
    buffer[10] = '\0';

    streampos position = inFile.tellg();

    cout << "read content: \"" << buffer << "\"" << endl;
    cout << "current read position: " << position << endl;

    inFile.close();
    return 0;

}