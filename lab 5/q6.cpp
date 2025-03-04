
#include "iostream"
#include <string>
using namespace std;

class Level
{
private:
    int level;
    string difficulty;

public:
    Level() : level(0), difficulty("Unknown") {}
    Level(int level, string d) : level(level), difficulty(d) {}
    void display()
    {
        cout << "Level: " << level << " Difficulty: " << difficulty << endl;
    }
};
class Videogame
{
private:
    string title, genre;
    Level l[10];
    int count;

public:
    Videogame(string t, string g) : title(t), genre(g), count(0) {}

    void addLevel(int n, string d)
    {
        if (count < 10)
        {
            l[count++] = Level(n, d);
        }
        else
        {
            cout << "Can't add more levels!" << endl;
        }
    }
    void display()
    {
        cout << "Game title:" << title <<"- Genre: " << genre << endl;
        cout << "Levels in the Game:" << endl;
        for (int i = 0; i < count; i++)
        {
            l[i].display();
        }
    }
};

int main()
{
    Videogame g("Candy Crush", "Entertaining");
    g.addLevel(1, "Easy");
    g.addLevel(2, "Medium");
    g.addLevel(3, "Hard");
    g.display();
    return 0;
}
