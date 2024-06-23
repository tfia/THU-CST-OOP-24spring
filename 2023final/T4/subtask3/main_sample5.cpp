#include <iostream>
#include <cassert>
#include <utility>
#include "PopStrategy.hpp"
#include "MyDict.hpp"

template<class Key, class T>
void outputInfo(const MyDict<Key, T>& dict, const std::string& name) {
    std::cout << name << ".size = " << dict.size() << '\n';
    std::cout << name << ".hitStats : ";
    std::cout << dict.hitStats() << '\n';
}


int main() {
    // Test 3.1
    std::cout << "[ Test 3.1 ]\n";
    PopStrategy<int>* d1Strategy = new FIFOStrategy<int>();
    MyDict<int, std::string> d1(2, d1Strategy);
    d1[0] = "hello ";   // miss
    d1[2] = "!";        // miss
    d1[0] = "Hello ";   // hit
    d1[1] = "";         // miss, d1[0] poped
    d1[1] = "world";    // hit
    std::cout << d1[0]  // miss, d1[2] poped
        << d1[1]        // hit
        << d1[2]        // miss, d1[1] poped
        << '\n';
    outputInfo(d1, "d1");
    std::cout << '\n';

    // Test 3.2
    std::cout << "[ Test 3.2 ]\n";
    PopStrategy<std::string>* d2Strategy = new LRUStrategy<std::string>();
    MyDict<std::string, std::string> d2(2, d2Strategy);
    d2["hello"] = "h";          // miss
    d2["world"] = "w";          // miss
    d2["hello"] = "H";          // hit
    d2["!"] = "!";              // miss, d2["world"] poped
    std::cout << d2["hello"]    // hit
        << d2["!"]              // hit
        << d2["world"]          // miss, d2["hello"] poped
        << '\n';
    outputInfo(d2, "d2");
    std::cout << '\n';

    // Test 3.3
    std::cout << "[ Test 3.3 ]\n";
    d1.clear();
    d2.clear();
    outputInfo(d1, "d1");
    outputInfo(d2, "d2");
    std::cout << '\n';

    // Test 3.4
    std::cout << "[ Test 3.4 ]\n";
    PopStrategy<int>* cntFIFOStrategy = new FIFOStrategy<int>();
    PopStrategy<int>* cntLRUStrategy = new LRUStrategy<int>();
    MyDict<int, int> cntFIFO(8, cntFIFOStrategy), cntLRU(8, cntLRUStrategy);
    for (int i = 2; i < 100; ++ i) {
        int num = i;
        for (int j = 2; j * j <= num; ++j) {
            while (num % j == 0) {
                ++cntFIFO[j];
                ++cntLRU[j];
                num /= j;
            }
        }
        if (num > 1) {
            ++cntFIFO[num];
            ++cntLRU[num];
        }
    }
    outputInfo(cntFIFO, "cntFIFO");
    outputInfo(cntLRU, "cntLRU");
    for (auto i: {2, 3, 5, 7, 11, 13, 17, 19}) {
        std::cout << "cntFIFO[" << i << "] = " << cntFIFO[i] 
            << ", cntLRU[" << i << "] = " << cntLRU[i] << '\n';
    }

    delete cntFIFOStrategy;
    delete cntLRUStrategy;
    delete d1Strategy;
    delete d2Strategy;

    return 0;
}
