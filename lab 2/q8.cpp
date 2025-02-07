#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int** arr = new int*[n];

    cout << "enter " << n << " integers:\n";
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int;
        cin >> *arr[i];
    }
    
    cout << "array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << *arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        delete arr[i];
    }
    delete[] arr;

    return 0;
}