#include <iostream>
#include <string>
using namespace std;





void display(int **ptr,int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout << *(*(ptr+i)+j) << " ";
        }
        cout << endl;
    }
}



int main(){
    int rows,cols;
    cout << "Enter the number of rows in matrix 1 and 2: ";
    cin >> rows;
    cout << "Enter the number of columns in matrix 1 and 2: ";
    cin >> cols;
    int **matrix1 = new int*[rows];
    for(int i=0;i<rows;i++){
        matrix1[i] = new int[cols];
    }
    for(int i=0;i<rows;i++){
        
        for(int j=0;j<cols;j++){
            cout << "Enter elements of row " << i+1 << " col " << j+1 << " in matrix 1:" << endl;
            cin >> *(*(matrix1+i)+j);
        } 
    }

    int **matrix2 = new int*[rows];
    for(int i=0;i<rows;i++){
        matrix2[i] = new int[cols];
    }
    for(int i=0;i<rows;i++){
        
        for(int j=0;j<cols;j++){
            cout << "Enter elements of row " << i+1 << " col " << j+1 << " in matrix 2:" << endl;
            cin >> *(*(matrix2+i)+j);
        } 
    }

    int **ptr1 = new int*[rows];
    for(int i=0;i<rows;i++){
        ptr1[i] = new int[cols];
    }
    int **ptr2 = new int*[rows];
    for(int i=0;i<rows;i++){
        ptr2[i] = new int[cols];
    }

    cout << "addition of matrices" << endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            *(*(ptr1+i)+j) = *(*(matrix1+i)+j) + *(*(matrix2+i)+j);
        }
    }
    display(ptr1,rows,cols);    

    cout << "subtraction of matrices" << endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            *(*(ptr2+i)+j) = *(*(matrix1+i)+j) - *(*(matrix2+i)+j);
        }
    }
    display(ptr2,rows,cols);

    for(int i=0;i<rows;i++){
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] ptr1[i];
        delete[] ptr2[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] ptr1;
    delete[] ptr2;

    return 0;
}       