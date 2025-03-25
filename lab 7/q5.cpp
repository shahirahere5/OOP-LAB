#include <iostream>
#include <string>
using namespace std;

class Character{
    protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

    public:
    Character(int id, string n, int l, int h, string w):characterID(id),name(n),level(l),healthPoints(h),weaponType(w){}

    virtual void attack(){
        cout << name << " attacks with " << weaponType << "." << endl;
    }

    virtual void defend(){
        cout << name << " defends with " << weaponType << "." << endl;
    }

    virtual void displayStats(){
        cout << "Character ID: " << characterID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health Points: " << healthPoints << endl;
        cout << "Weapon Type: " << weaponType << endl;
    }
};

class Warrior : public Character{
    protected:
    int armorStrength;
    int meleeDamage;

    public:
    Warrior(int id, string n, int l, int h, string w, int a, int m): Character(id,n,l,h,w), armorStrength(a), meleeDamage(m){}

    void attack() override{
        cout << name << " performs a melee attack with damage: " << meleeDamage  << endl;
    }
};

class Mage : public Character{
    protected:
    int manaPoints;
    int spellPower;

    public:
    Mage(int id, string n, int l, int h, string w, int m, int sp): Character(id,n,l,h,w), manaPoints(m), spellPower(sp){}

    void defend() override{
        cout << name << " uses a magical barrier with spell power: " << spellPower << endl;
    }
};

class Archor : public Character{
    protected:
    int arrowCount;
    int rangedAccuracy;

    public:
    Archor(int id, string n, int l, int h, string w, int a, int r): Character(id,n,l,h,w), arrowCount(a), rangedAccuracy(r){}

    void attack() override{
        cout << name << " fires an arrow with accuracy: " << rangedAccuracy << endl;
    }
};

class Rogue : public Character{
    protected:
    int stealthLevel;
    int agility;

    public:
    Rogue(int id, string n, int l, int h, string w, int s, int a): Character(id,n,l,h,w), stealthLevel(s), agility(a){}

    void displayStats() override{
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main(){
    Warrior warrior(1, "John", 10, 100, "Sword", 10, 20);
    Mage mage(2, "Mary", 5, 80, "Staff", 50, 25);
    Archor archer(3, "Sam", 8, 90, "Bow", 5, 15);
    Rogue rogue(4, "Emily", 12, 110, "Dagger", 10, 18);

    warrior.displayStats();
    warrior.attack();

    mage.displayStats();
    mage.defend();

    archer.displayStats();
    archer.attack();

    rogue.displayStats();
    
    return 0;
}    