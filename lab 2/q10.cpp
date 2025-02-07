#include <iostream>
using namespace std;

int*** allocate3DArray(int x,int y,int z){
    int*** arr = new int**[x];
    for(int i=0;i<x;i++){
        arr[i] = new int*[y];
        for(int j=0;j<y;j++){
            arr[i][j] = new int[z];
        }
    }
    return arr;
}

void inputArray(int*** array,int x,int y,int z){
    cout << "enter elements of 3d array: ";
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                cin >> array[i][j][k];
            }
        }
    }
}

void display(int*** array,int x,int y,int z){
    cout << "elements of 3d array: " << endl;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                cout << array[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void deallocate(int*** array,int x,int y){
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;
}

int main(){
    int x,y,z;
    cout << "Enter the size of 3d array (x y z): ";
    cin >> x >> y >> z;

    int*** array = allocate3DArray(x,y,z);
    inputArray(array,x,y,z);
    display(array,x,y,z);
    deallocate(array,x,y);
    return 0;
}