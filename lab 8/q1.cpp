#include <iostream>
#include <cmath>
using namespace std;

class Complex{
    private:
    double real;
    double imaginary;

    public:
    Complex(double r=0,double i=0): real(r), imaginary(i){}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) {
        return Complex(real*other.real - imaginary*other.imaginary, real*other.imaginary + imaginary*other.real);
    }

    Complex operator/(const Complex& other) {
        double denominator = pow(other.real, 2) + pow(other.imaginary, 2);
        if(denominator == 0){
            cout << "Error: Division by zero" << endl;
        }else{
            return Complex((real*other.real + imaginary*other.imaginary) / denominator, (imaginary*other.real - real*other.imaginary) / denominator);
        }
    }
    
    friend double magnitude(const Complex& other);

    friend ostream& operator<<(ostream& out, const Complex& complex);

};

double magnitude(const Complex& other){
    return sqrt(pow(other.real, 2) + pow(other.imaginary, 2));
}

ostream& operator<<(ostream& out, const Complex& complex){
    cout << complex.real << "+" << complex.imaginary << "i" << endl;
    return out;
}

int main(){
    Complex c1(2,3);
    Complex c2(4,5);

    cout << "Complex number 1: " << c1 << endl;
    cout << "Complex number 2: " << c2 << endl;

    cout << "Addition: " << c1 + c2 << endl;
    cout << "Subtraction: " << c1 - c2 << endl;
    cout << "Multiplication: " << c1 * c2 << endl;
    cout << "Division: " << c1 / c2 << endl;
    cout << "Magnitude of c1: " << magnitude(c1) << endl;

    return 0;
}