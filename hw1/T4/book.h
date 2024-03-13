#pragma once
#include <iostream>
using namespace std;

class Book{
private:
    using State = std::pair<bool, string>;
    int ID;
    string name;
    string author;
    string publishing_house;
    State state;
public:
    Book(int ID, string name, string author, string publishing_house);
    int get_ID();
    string get_name();
    string get_author();
    string get_publishing_house();
    bool get_state();
    void change_state();
    void change_state(string name);
    void print_message();
};

