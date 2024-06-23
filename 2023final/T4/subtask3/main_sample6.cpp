#include <iostream>
#include "PopStrategy.hpp"
#include "MyDict.hpp"


int main() {
    freopen("sample6.in", "r", stdin);
    int n, dictCapacity;
    std::cin >> dictCapacity;
    PopStrategy<int>* fifoStrategyPtr = new FIFOStrategy<int>();
    PopStrategy<int>* lruStrategyPtr = new LRUStrategy<int>();
    MyDict<int, int> dictFIFO(dictCapacity, fifoStrategyPtr);
    MyDict<int, int> dictLRU(dictCapacity, lruStrategyPtr);
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string op;
        std::cin >> op;
        if (op == "update") {
            int key, value;
            std::cin >> key >> value;
            dictFIFO[key] = value;
            std::cout << "dictFIFO[" << key << "] := " << value << "; ";
            dictLRU[key] = value;
            std::cout << "dictLRU[" << key << "] := " << value << '\n';
        }
        else if (op == "query") {
            int key;
            std::cin >> key;
            int value = dictFIFO[key];
            std::cout << "dictFIFO[" << key << "] = " << value << "; ";
            value = dictLRU[key];
            std::cout << "dictLRU[" << key << "] = " << value << '\n';
        }
        else if (op == "stats") {
            std::cout << "dictFIFO.hitStats = " << dictFIFO.hitStats() << "; ";
            std::cout << "dictLRU.hitStats = " << dictLRU.hitStats() << '\n';
        }
        else if (op == "size") {
            std::cout << "dictFIFO.size = " << dictFIFO.size() << "; ";
            std::cout << "dictLRU.size = " << dictLRU.size() << '\n';
        }
        else if (op == "clear") {
            dictFIFO.clear();
            dictLRU.clear();
            std::cout << "dictFIFO & dictLRU cleared.\n";
        }
    }
    delete fifoStrategyPtr;
    delete lruStrategyPtr;
    return 0;
}
