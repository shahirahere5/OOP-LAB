#include <iostream>
#include <string>
using namespace std;

class Ticket{
    protected:
    int ticketID;
    string passengerName;
    float price;
    string date;
    string destination;

    public:
    Ticket(int id,string name, float p,string d,string dest): ticketID(id), passengerName(name), price(p), date(d), destination(dest){}

    virtual void reserve(){
        cout << "Ticket reserved for: " << passengerName << endl;
    }

    virtual void cancel(){
        cout << "Ticket cancelled for: " << passengerName << endl;
    }

    virtual void displayTicketInfo(){
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Passenger Name: " << passengerName << endl;
        cout << "Price: $" << price << endl;
        cout << "Date: " << date << endl;
        cout << "Destination: " << destination << endl;
    }
};

class FlightTicket : public Ticket{
    protected:
    string airlineName;
    int flightNumber;
    string seatClass;

    public:
    FlightTicket(int id, string name, float p, string d, string dest, string air, int f, string sc): Ticket(id,name,p,d,dest), airlineName(air), flightNumber(f), seatClass(sc){}

    void displayTicketInfo() override{
        Ticket::displayTicketInfo();
        cout << "Airline Name: " << airlineName << endl;
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Seat Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket{
    protected:
    int trainNumber;
    string coachType;
    string departureTime;

    public:
    TrainTicket(int id, string name, float p, string d, string dest,int trainNumber, string coachType, string departureTime):Ticket(id,name,p,d,dest),trainNumber(trainNumber),coachType(coachType),departureTime(departureTime){}

    void reserve() override{
        cout << "train seat auto-assigned for " << passengerName << " in " << coachType << " coach on train " << trainNumber << " departing at " << departureTime << endl;
    }
};

class BusTicket : public Ticket{
    protected:
    string busCompany;
    int seatNumber;

    public:
    BusTicket(int id, string name, float p, string d, string dest, string busCompany, int seatNumber):Ticket(id,name,p,d,dest), busCompany(busCompany), seatNumber(seatNumber){}

    void cancel() override { 
        cout << "bus seat cancelled for " << passengerName << ".refund processed(last-min allowed)" << endl;
    }
};    
    
class ConcertTicket : public Ticket{
    protected:
    string artistName;
    string venue;
    string seatType;

    public:
    ConcertTicket(int id, string name, float p, string d, string dest, string artist, string venue, string seatType):Ticket(id,name,p,d,dest), artistName(artist), venue(venue), seatType(seatType){}

    void displayTicketInfo() override{
        Ticket::displayTicketInfo();
        cout << "Artist Name: " << artistName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat Type: " << seatType << endl;
    }
};

int main(){
    FlightTicket flight(1, "shahira", 100.0, "10/01/2022", "New York", "Delta Airlines", 789, "Business");
    TrainTicket train(2, "shahira", 50.0, "11/02/2022", "Chicago", 456, "First Class", "09:00 AM");
    BusTicket bus(3, "shahira", 20.0, "12/03/2022", "San Francisco", "Amtrak", 876);
    ConcertTicket concert(4, "shahira", 150.0, "13/04/2022", "Los Angeles", "Madonna", "VIP Seat", "Standard");

    flight.reserve();
    train.reserve();
    bus.cancel();
    concert.displayTicketInfo();

    flight.displayTicketInfo(); 

    bus.cancel();
    return 0;
}