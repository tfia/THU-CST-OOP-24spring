#include "Animal.h"

class Fish : public Animal
{
public:
    int color;
    Fish(int color) : color(color) {}
    void sing() override
    {
        cout << "Fish can not sing." << endl;
    }
    void swim() override
    {
        if(color == 0) cout << "Red ";
        else cout << "Blue ";
        cout << "fish is swimming." << endl;
    }
    ~Fish()
    {
        if(color == 0) cout << "Red ";
        else cout << "Blue ";
        cout << "fish is gone." << endl;
    }
};