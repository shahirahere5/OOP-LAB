#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int *arr = new int[n];

    cout << "enter elements:" ;
    for(int i = 0; i < n; i++){
        cin >> *(arr+i);
    }

    cout << "array elements:" ;
    for(int i = 0; i < n; i++){
        cout << *(arr+i) << " ";
    }
    cout << endl;

    int sum=0;
    for(int i = 0; i < n; i++){
        sum += *(arr+i);
    }

    cout << "Sum of the array elements: " << sum << endl;

    delete [] arr;
    return 0;
 
}