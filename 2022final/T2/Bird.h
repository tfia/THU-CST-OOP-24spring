#include "Animal.h"

class Bird : public Animal
{
public:
    int color;
    Bird(int color) : color(color) {}
    void swim() override
    {
        cout << "Bird can not swim." << endl;
    }
    void sing() override
    {
        if(color == 0) cout << "Red ";
        else cout << "Blue ";
        cout << "bird is singing." << endl;
    }
    ~Bird()
    {
        if(color == 0) cout << "Red ";
        else cout << "Blue ";
        cout << "bird is gone." << endl;
    }
};