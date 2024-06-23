#include <iostream>

#include "Animal.h"
#include "Bird.h"
#include "Fish.h"

const int N = 100;

void action(Animal* pAnimal) {
	pAnimal -> sing();
	pAnimal -> swim();
}

int main(){
    freopen("test.in", "r", stdin);
    int n = 0;
    std::cin >> n;

    int op = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> op;
        if (op == 0) {
            int color = 0;
            std::cin >> color;
            Animal *myBird = new Bird(color);
            action(myBird);
            delete myBird;
        }
        else {
            int color = 0;
            std::cin >> color;
            Animal *myFish = new Fish(color);
            action(myFish);
            delete myFish;
        }
    }

    return 0;
}
