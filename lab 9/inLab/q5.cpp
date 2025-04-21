#include <iostream>
#include <string>
using namespace std;

class Shipment{
    protected:
    string trackingNumber;
    double weight;

    public:
    Shipment(string trackingNumber,double weight):trackingNumber(trackingNumber),weight(weight){}
    virtual void estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
};

class AirFreight: public Shipment{
    public:
    AirFreight(string trackingNumber,double weight):Shipment(trackingNumber,weight){}
    void estimateDeliveryTime() override{
        cout << "estimating delivery time of air freight" << endl;
    }

    void showDetails() override{
        cout << "air freight: " << endl;
        cout << "tracking number: " << trackingNumber << endl;
        cout << "weight: " << weight << endl;
    }
};

class GroundShipment: public Shipment{
    public:
    GroundShipment(string trackingNumber,double weight):Shipment(trackingNumber,weight){}

    void estimateDeliveryTime() override{
        cout << "estimating delivery time of ground shipment" << endl;
    }

    void showDetails() override{
        cout << "ground shipment: " << endl;
        cout << "tracking number: " << trackingNumber << endl;
        cout << "weight: " << weight << endl;
    }
};

int main(){
    AirFreight AirFreight("PK101",20);
    GroundShipment GroundShipment("PK102",30);

    AirFreight.estimateDeliveryTime();
    AirFreight.showDetails();

    GroundShipment.estimateDeliveryTime();
    GroundShipment.showDetails();

    return 0;
}