#include <iostream>
using namespace std;

class Matrix2x2{
    private:
    int elements[2][2];

    public:
    Matrix2x2(int a=0,int b=0,int c=0,int d=0){
        elements[0][0] = a;
        elements[0][1] = b;
        elements[1][0] = c;
        elements[1][1] = d;
    }

    friend class MatrixHelper;

    Matrix2x2 operator+(const Matrix2x2& other){
        return Matrix2x2(
            elements[0][0] + other.elements[0][0],
            elements[0][1] + other.elements[0][1],
            elements[1][0] + other.elements[1][0],
            elements[1][1] + other.elements[1][1]
        );
    }
    
    Matrix2x2 operator-(const Matrix2x2& other){
        return Matrix2x2(
            elements[0][0] - other.elements[0][0],
            elements[0][1] - other.elements[0][1],
            elements[1][0] - other.elements[1][0],
            elements[1][1] - other.elements[1][1]
        );
    }

    Matrix2x2 operator*(const Matrix2x2& other){
        return Matrix2x2(
            elements[0][0] * other.elements[0][0] + elements[0][1] * other.elements[1][0],
            elements[0][0] * other.elements[0][1] + elements[0][1] * other.elements[1][1],
            elements[1][0] * other.elements[0][0] + elements[1][1] * other.elements[1][0],
            elements[1][0] * other.elements[0][1] + elements[1][1] * other.elements[1][1]
        );
    }

    friend ostream& operator<<(ostream& out, const Matrix2x2& other){
        out << other.elements[0][0] << " " << other.elements[0][1] << endl;
        out << other.elements[1][0] << " " << other.elements[1][1] << endl;
        return out;
    }

    friend int determinant(const Matrix2x2& other);
};

int determinant(const Matrix2x2& other){
    return (other.elements[0][0] * other.elements[1][1]) - (other.elements[0][1] * other.elements[1][0]);
}

class MatrixHelper{
    public:
    void updateElement(Matrix2x2& m, int row, int col, int newValue){
        if(row >= 0 && row < 2 && col >= 0 && col < 2){
            m.elements[row][col] = newValue;
        }
    }
};

int main(){
    Matrix2x2 m1(1,2,3,4);
    Matrix2x2 m2(5,6,7,8);

    cout << "matrix 1: " << m1 << endl;
    cout << "matrix 2: " << m2 << endl;

    Matrix2x2 sum = m1 + m2;
    cout << "sum: " << sum << endl;

    Matrix2x2 diff = m1 - m2;
    cout << "difference: " << diff << endl;

    Matrix2x2 prod = m1 * m2;
    cout << "product: " << prod << endl;

    cout << "determinant of matrix 1: " << determinant(m1) << endl;

    MatrixHelper helper;
    helper.updateElement(m1, 0, 0, 9);
    cout << "updated matrix 1: " << m1 << endl;

    return 0;
}    