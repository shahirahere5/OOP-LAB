#include <iostream>
#include <string>
using namespace std;

class Product{
    protected:
    int productID;
    string productName;
    float price;
    int stockQuantity;

    public:
    Product(int id, string name, float p, int q): productID(id), productName(name), price(p), stockQuantity(q){}

    virtual void applyDiscount()  {
        if(stockQuantity < 10)
            price *= 0.9;
    }

    virtual void calculateTotalPrice(int quantity){
        cout << "Total price for " << quantity << " " << productName << "s: $" << price * quantity << endl;
    }

    virtual void displayProductInfo(){
        cout << "Product ID: " << productID << ", Name: " << productName << ", Price: $" << price << ", Stock Quantity: " << stockQuantity << endl;
    }
};

class Electronics: public Product{
    public:
    int warrantyPeriod;
    string brand;

    Electronics(int id, string name, float p, int q, int w,string b): Product(id, name, p, q), warrantyPeriod(w),brand(b){}

    void displayProductInfo() override { 
        Product::displayProductInfo();
        cout << ", Warranty Period: " << warrantyPeriod << " years" << endl;
    }
};

class Clothing: public Product{
    public:
    string size;
    string color;
    string fabricMaterial;

    Clothing(int id, string name, float p, int q, string s, string c, string f): Product(id, name, p, q), size(s), color(c), fabricMaterial(f){}

    void applyDiscount() override {
        price *= 0.8;
    }

};

class FoodItem: public Product{
    public:
    string expirationDate;
    int calories;

    FoodItem(int id, string name, float p, int q, string d, int c): Product(id, name, p, q), expirationDate(d), calories(c){}

    void calculateTotalPrice(int quantity) override {
        float total = price * quantity;
        if(quantity > 5){
            total *= 0.9;
        }
        cout << "Total price for " << quantity << " " << productName << "s: $" << total << endl;
    }
};    

class Book: public Product{
    public:
    string author;
    string genre;

    Book(int id, string name, float p, int q, string a, string g): Product(id, name, p, q), author(a), genre(g){}

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << ", Author: " << author << ", Genre: " << genre << endl;
    }
};

int main(){
    Electronics laptop(101,"laptop",800.0,5,2,"hp");
    Clothing tshirt(201,"tshirt",20.0,15,"M","black","cotton");
    FoodItem cookie(301,"cookie",1.5,20,"2022-12-31",50);
    Book book(401,"book",15.0,10,"J.K. Rowling","Fantasy");

    laptop.applyDiscount();
    tshirt.applyDiscount();
    cookie.calculateTotalPrice(3);
    book.displayProductInfo();

    return 0;
}