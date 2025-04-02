#include <iostream>
using namespace std;

class Car{
    private:
    string model;
    double price;

    public:
    Car(string m, double p){
        model = m;
        price = p;
    }

    friend class InventoryManager;

    friend void comparePrice(const Car& c1, const Car& c2);
};

class InventoryManager{
    public:
    void updatePrice(Car& c, double newPrice){
        c.price = newPrice;
    }

    void displayCar(const Car& c){
        cout << "Model: " << c.model << ", Price: $" << c.price << endl;
    }
};

void comparePrice(const Car& c1, const Car& c2){
    if(c1.price < c2.price){
        cout << "Car 1 is cheaper." << endl;
    } else if(c1.price > c2.price){
        cout << "Car 2 is cheaper." << endl;
    } else {
        cout << "Both cars have the same price." << endl;
    }
}

int main(){
    Car car1("Toyota", 30000);
    Car car2("Honda", 40000);

    InventoryManager inventoryManager;
    
    cout << "initial car details: " << endl;
    inventoryManager.displayCar(car1);
    inventoryManager.displayCar(car2);

    inventoryManager.updatePrice(car1, 35000);
    
    cout << "\nupdated car details: " << endl;
    inventoryManager.displayCar(car1);

    comparePrice(car1, car2);

    return 0;
}