#include <iostream>
#include "MyDict.hpp"


int main() {
    freopen("sample2.in", "r", stdin);
    MyDict<int, int> dict;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string op;
        std::cin >> op;
        if (op == "update") {
            int key, value;
            std::cin >> key >> value;
            dict[key] = value;
            std::cout << "dict[" << key << "] := " << value << '\n';
        }
        else if (op == "query") {
            int key;
            std::cin >> key;
            int value = dict[key];
            std::cout << "dict[" << key << "] = " << value << '\n';
        }
        else if (op == "stats") {
            std::cout << "dict.hitStats = " << dict.hitStats() << '\n';
        }
        else if (op == "size") {
            std::cout << "dict.size = " << dict.size() << '\n';
        }
        else if (op == "clear") {
            dict.clear();
            std::cout << "dict cleared.\n";
        }
    }
    return 0;
}
