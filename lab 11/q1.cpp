#include <iostream>
#include <exception>
#include <sstream>
using namespace std;

class DimensionMismatchexception : public exception {
    string message;

public:
    DimensionMismatchexception(int r1, int c1, int r2, int c2) {
        stringstream ss;
        ss << "Dimensions mismatch: (" << r1 << "x" << c1
           << ") != (" << r2 << "x" << c2 << ")";
        message = ss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class Matrix {
private:
    int row, col;
    T** data;

public:
    Matrix(int r, int c) : row(r), col(c) {
        data = new T*[row];
        for (int i = 0; i < row; i++) {
            data[i] = new T[col]{};
        }
    }

    Matrix(const Matrix& other) : row(other.row), col(other.col) {
        data = new T*[row];
        for (int i = 0; i < row; ++i) {
            data[i] = new T[col];
            for (int j = 0; j < col; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < row; ++i)
            delete[] data[i];
        delete[] data;
    }

    void set(int r, int c, T value) {
        data[r][c] = value;
    }

    T get(int r, int c) const {
        return data[r][c];
    }

    int getRows() const {
        return row;
    }

    int getCols() const {
        return col;
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (row != other.row || col != other.col)
            throw DimensionMismatchexception(row, col, other.row, other.col);

        Matrix<T> result(row, col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                result.set(i, j, data[i][j] + other.get(i, j));
            }
        }
        return result;
    }

    void print() const {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(3, 3);

        A.set(0, 0, 1); A.set(0, 1, 2);
        A.set(1, 0, 3); A.set(1, 1, 4);

        B.set(0, 0, 5); B.set(0, 1, 6); B.set(0, 2, 7);
        B.set(1, 0, 8); B.set(1, 1, 9); B.set(1, 2, 10);
        B.set(2, 0, 11); B.set(2, 1, 12); B.set(2, 2, 13);

        Matrix<int> C = A + B;
        C.print();

    } catch (const DimensionMismatchexception& e) {
        cout << e.what() << endl;
    }

    return 0;
}