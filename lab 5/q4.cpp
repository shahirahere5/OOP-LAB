
#include "iostream"
#include <string>
using namespace std;

class AlarmSystem
{
    private:
    string securitylevel;
    public:
    AlarmSystem(string sl): securitylevel(sl){}
    ~AlarmSystem(){}
    void display(){
        cout<<"Alarm Security Level: "<<securitylevel<<endl;
    }
};
class SmartHome{
    private:
    AlarmSystem as;
    public:
    SmartHome(string level): as(level){}
    void display(){
        cout<<"Smart home details:"<<endl;
        as.display();
    }

};

int main(){
    SmartHome s1("Low");
    AlarmSystem d("High");
    s1.display();
    d.display();
    return 0;
}
