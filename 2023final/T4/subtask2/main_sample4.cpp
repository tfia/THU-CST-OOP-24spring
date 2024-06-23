#include <iostream>
#include "PopStrategy.hpp"

int main() {
    freopen("sample4.in", "r", stdin);
    std::pair<std::string, PopStrategy<int>*> popStrategy[] = {
        std::make_pair("FIFO", new FIFOStrategy<int>()),
        std::make_pair("LRU", new LRUStrategy<int>())
    };
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string op;
        std::cin >> op;
        if (op == "visit") {
            int element;
            std::cin >> element;
            for (auto popStrategyPair: popStrategy) {
                PopStrategy<int>* strategyPtr = popStrategyPair.second;
                strategyPtr -> visit(element);
            }
        }
        else { // op == "pop"
            for (auto popStrategyPair: popStrategy) {
                std::string strategyName = popStrategyPair.first;
                PopStrategy<int>* strategyPtr = popStrategyPair.second;
                std::cout << strategyName << ' ' << (strategyPtr -> pop()) << ' ';
            }
            std::cout << '\n';
        }
    }
    for (auto popStrategyPair: popStrategy) {
        delete popStrategyPair.second;
    }

    return 0;
}