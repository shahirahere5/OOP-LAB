#include <iostream>
#include <string>
using namespace std;

class Car
{
    string brand;
    string model;
    float rentalPrice;
    float totalrevenue;
    int days;
    bool availabilityStatus;
    string regno;

public:
    Car(string reg, string b, string m, float r, int d, bool avail)
        : regno(reg), brand(b), model(m), rentalPrice(r),
          days(d), availabilityStatus(avail), totalrevenue(0) {}

    Car(const Car &obj, string newregno) 
          : regno(newregno), brand(obj.brand), model(obj.model),
            rentalPrice(obj.rentalPrice), days(obj.days),
            availabilityStatus(obj.availabilityStatus), totalrevenue(obj.totalrevenue) 
      {
          cout << "Copy Constructor\n";
      }
    ~Car() {
        cout << "Destructor: Car " << regno << " removed from memory.\n";
    }
    
    bool isAvailable()
    {
        return availabilityStatus;
    }
    void rent()
    {
        if (availabilityStatus)
        {
            applyDiscount();
            this->totalrevenue += this->rentalPrice * this->days;
            availabilityStatus = false;

            cout << "Car " << regno << " is Rented. Rental Price: $" << rentalPrice << endl;
            cout << "Total Revenue generated: $" << totalrevenue << endl;
        }
        else
        {
            cout << "Car not Available!\n";
        }
    }
    void applyDiscount()
    {
        if (days > 5 && days <= 10)
        {
            rentalPrice *= 0.95; 
        }
        else if (days > 10)
        {
            rentalPrice *= 0.90; 
        }
    }

    void update(string newBrand, string newModel, float newRentalPrice, int newDays)
    {
        this->brand = newBrand;
        this->model = newModel;
        this->rentalPrice = newRentalPrice;
        this->days = newDays;
    }

    void display()
    {
        cout << "\nCar ID: " << regno << "\n"
             << brand << " " << model << "\n  Rental Price: $" << rentalPrice << "\n  Days: " << days
             << "\n  Available: " << (availabilityStatus ? "Yes" : "No") << endl;
    }
};

int main()
{
    Car c1("ABC123", "Toyota", "Corolla", 500.5, 7, true);
    Car c2("DLG039", "Honda", "Civic", 140, 2, true);
    Car c3("AFV438", "Suzuki", "Maruti", 200, 1, true);
    
    c1.display();
    c2.display();
    c3.display();
    
    c1.rent();
    c3.rent();
    c1.display();
    c3.display();
    return 0;
}