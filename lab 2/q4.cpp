#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cout << "enter the num of strings" << endl;
    cin >> n;

    string* strArray = new string[n];
    for(int i = 0; i < n;i++){
        cout << "enter string " << i+1 << ":" << endl;
        cin >> strArray[i];
    }

    cout << "strings in alphabetical order" << endl;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(strArray[i] > strArray[j]){
                string temp = strArray[i];
                strArray[i] = strArray[j];
                strArray[j] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << strArray[i] << " ";
    }

    delete[] strArray;
    return 0;
}