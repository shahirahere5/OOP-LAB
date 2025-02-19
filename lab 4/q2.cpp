#include <iostream>
#include <string>
using namespace std;

class Car {
    string brand;
    string model;
    float rentalPrice;
    int days;
    bool availabilityStatus;

public:

    Car(string b, string m, float r, int d, bool avail) 
        {
          brand=b;
          model=m;
          rentalPrice=r;
          days=d;
          availabilityStatus=avail;
        }

    bool isAvailable() {
        return availabilityStatus;
    }

void rent() {
        if (availabilityStatus) {
            applyDiscount();
            availabilityStatus = false;
            cout << "Car is Rented. Final Rental Price: $" << rentalPrice << endl;
        } else {
            cout << "Car not Available!" << endl;
        }
    }

    void applyDiscount() {
        if (days > 5 && days <= 10) {
            rentalPrice *= 0.95;  // 5% discount
        } else if (days > 10) {
            rentalPrice *= 0.90;  // 10% discount
        }
    }
};

int main() {
    Car c1("Toyota", "Corolla", 500.5, 7, true);
    c1.rent();

    return 0;
}