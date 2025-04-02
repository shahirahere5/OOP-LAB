#include <iostream>
using namespace std;

class Vector2D{
    private:
    double x, y;

    public:
    Vector2D(double x = 0, double y = 0){
        this->x = x;
        this->y = y;
    }

    Vector2D operator+(const Vector2D& other) {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(double scalar){
        return Vector2D(x * scalar, y * scalar);
    }

    friend double dotProduct(const Vector2D& v1, const Vector2D& v2);

    friend ostream& operator<<(ostream&, const Vector2D& v);
};

double dotProduct(const Vector2D& v1, const Vector2D& v2){
    return (v1.x * v2.x) + (v1.y * v2.y);
}

ostream& operator<<(ostream& os, const Vector2D& v){
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

int main() {
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    cout << "vector 1: " << v1 << endl;
    cout << "vector 2: " << v2 << endl;

    Vector2D sum = v1 + v2;
    cout << "sum of vectors: " << sum << endl;

    Vector2D diff = v1 - v2;
    cout << "difference of vectors: " << diff << endl;

    Vector2D scaled = v1 * 2.0;
    cout << "scaled vector: " << scaled << endl;

    double dotProductResult = dotProduct(v1, v2);
    cout << "Dot product: " << dotProductResult << endl;

    return 0;
}