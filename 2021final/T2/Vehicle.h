#pragma once
#include<iostream>

using namespace std;

class Vehicle
{
public:
    int max_wheel_num;
    int max_wing_num;
    int wheel_num;
    int wing_num;
    void set_max_wheel_num(int x) {max_wheel_num = x;}
    void set_max_wing_num(int x) {max_wing_num = x;}
    void add_wheel() {wheel_num++;}
    void add_wing() {wing_num++;}
    Vehicle() : max_wheel_num(0), max_wing_num(0), wheel_num(0), wing_num(0) {}
    bool finished() {return wheel_num >= max_wheel_num && wing_num >= max_wing_num;}
    void run()
    {
        if(wing_num > 0) cout << "I am running and flying" << endl;
        else cout << "I am running" << endl;
    }
};