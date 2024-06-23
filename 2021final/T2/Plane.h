#include<iostream>
#include"Vehicle.h"
using namespace std;

class Plane: public Vehicle { 
    public:
        Plane() {
            set_max_wheel_num(3);
            set_max_wing_num(2);
        }
};