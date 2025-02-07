#include <iostream>
using namespace std;

int** dma(int rows,int cols){
    int** ptr = new int*[rows];
    for(int i = 0; i < rows; i++){
        ptr[i] = new int[cols];
    }
    return ptr;
}

void input(int** ptr, int rows,int cols){
    cout << "enter elements of matrix:\n";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> ptr[i][j];
        }
    }
}

void multiply(int** a, int* b, int** c,int r1,int c1,int c2){
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            c[i][j] = 0;
            for(int k = 0; k < c1; k++){
                c[i][j] += a[i][k] * b[k];
            }
        }
    }
}

void display(int** ptr, int rows, int cols){
    cout << "Resultant matrix:\n";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }
}

void dedma(int** ptr,int rows){
    for(int i = 0; i < rows; i++){
        delete[] ptr[i];
    }
    delete[] ptr;
}

int main(){
    int r1, c1,r2, c2;
    cout << "Enter the number of rows and columns of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter the number of rows and columns of second matrix: ";
    cin >> r2 >> c2;

    if(c1 != c2){
        cout << "multiplication not possible" ;
        return 1;
    }

    int** a = dma(r1, c1);
    int** b = dma(r2,c2);
    int** c = dma(r1, c2);

    input(a, r1, c1);
    input(b, r2, c2);

    multiply(a,b[0],c,r1,c1,c2);
    display(c, r1, c2);

    dedma(a, r1);
    dedma(b, r2);
    dedma(c, r1);

    return 0;
}