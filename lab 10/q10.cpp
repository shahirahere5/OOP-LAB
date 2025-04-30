#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outFile("data_records.txt");
    outFile << "Record 1\n";
    outFile << "Record 2\n";
    outFile << "Record 3\n";
    outFile << "Record 4\n";
    outFile.close();

    ifstream inFile("data_records.txt", ios::binary);
    if (!inFile) {
        cerr << "Error opening file.\n";
        return 1;
    }

    string temp;
    streampos offset = 0;
    for (int i = 0; i < 2; ++i) {
        getline(inFile, temp);
        offset = inFile.tellg(); 
    }

    inFile.clear(); 
    inFile.seekg(offset);

    string thirdRecord;
    getline(inFile, thirdRecord);
    cout << "Third record: " << thirdRecord << endl;

    inFile.close();
    return 0;
}
