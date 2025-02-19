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

    Car(const Car &obj) {
        brand = obj.brand;
        model = obj.model;
        rentalPrice = obj.rentalPrice;
        days = obj.days;
        availabilityStatus = obj.availabilityStatus;
        cout << "Copy Constructor\n";
    }

    ~Car() {
        cout << "Destructor. Object is being destroyed\n";
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
            cout << "Car not Available!\n";
        }
    }
    void applyDiscount() {
        if (days > 5 && days <= 10) {
            rentalPrice *= 0.95;  // 5% discount
        } else if (days > 10) {
            rentalPrice *= 0.90;  // 10% discount
        }
    }

    void update(string newBrand, string newModel, float newRentalPrice, int newDays) {
        brand = newBrand;
        model = newModel;
        rentalPrice = newRentalPrice;
        days = newDays;
    }

    void display() {
        cout << "Car: " << brand << " " << model<< " | Rental Price: $" << rentalPrice << " | Days: " << days 
             << " | Available: " << (availabilityStatus ? "Yes" : "No") << endl;
    }
};

int main() {
    Car c1("Toyota", "Corolla", 500.5, 7, true);
    
    c1.display();
    Car c2(c1);
    
    c2.display();
    c1.update("honda", "civic", 600.0, 10);
    
    c1.display();
    c2.display();
    
    c2.rent();
    return 0;
}