#include <iostream>
#include <string>
using namespace std;

class Car {
    string brand;
    string model;
    float rentalPrice;
    float totalrevenue;
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
          totalrevenue=0;
        }

    Car(const Car &obj) {
        brand = obj.brand;
        model = obj.model;
        rentalPrice = obj.rentalPrice;
        days = obj.days;
        availabilityStatus = obj.availabilityStatus;
        totalrevenue = obj.totalrevenue;
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
            this->totalrevenue+=this->rentalPrice*this->days;
            availabilityStatus = false;

            cout << "Car is Rented. Final Rental Price: $" << rentalPrice << endl;
            cout<<"Revenue generated: $"<<totalrevenue<<endl;
        } else {
            cout << "Car not Available!\n";
        }
    }
    void applyDiscount() {
        if (days > 5 && days <= 10) {
            rentalPrice *= 0.95;  
        } else if (days > 10) {
            rentalPrice *= 0.90;  
        }
    }

    void update(string newBrand, string newModel, float newRentalPrice, int newDays) {
        this->brand = newBrand;
        this->model = newModel;
        this->rentalPrice = newRentalPrice;
        this->days = newDays;
    }

    void display() {
        cout << "Car: " << brand << " " << model<< "  Rental Price: $" << rentalPrice << "  Days: " << days 
             << "  Available: " << (availabilityStatus ? "Yes" : "No") << endl;
    }
};

int main() {
    Car c1("Toyota", "Corolla", 500, 9, true);
    
    c1.display();
    
    c1.rent();
    c1.display();
    return 0;
}