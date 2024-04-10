#pragma once

class Test {
public:
    std::vector<int> data;
    int id;
    static int count;

    Test() : id(count) {
        std::cout << "Test " << count << " created" << std::endl;
        count++;
    }

    Test(const Test &t) : id(count), data(t.data) {
        std::cout << "Test " << count << " created by reference" << std::endl;
        count++;
    }

    Test(Test &&t) : id(t.id), data(std::move(t.data)) {
        std::cout << "Test " << id << " moved by rvalue reference" << std::endl;
    }

    void func(int a) {
        std::cout << "Test " << id << " calling func with " << a << std::endl;
        data.push_back(a);
        std::cout << "data size: " << data.size() << std::endl;
    }

    static int getCount() {
        return count;
    }

    ~Test() {
        std::cout << "Test " << id << " destroyed" << std::endl;
        count--;
    }
};

int Test::count = 0;