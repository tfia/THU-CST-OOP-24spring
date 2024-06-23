#include <iostream>
#include "MyDict.hpp"

template<class Key, class T>
void outputInfo(const MyDict<Key, T>& dict, const std::string& name) {
    std::cout << name << ".size = " << dict.size() << '\n';
    std::cout << name << ".hitStats : ";
    std::cout << dict.hitStats() << '\n';
}

int main() {
    // Test 1.1
    std::cout << "[ Test 1.1 ]\n";
    MyDict<int, std::string> d1;
    d1[0] = "hello ";   // miss
    d1[1] = "";         // miss
    d1[1] = "world";    // hit
    std::cout << d1[0]  // hit
        << d1[1]        // hit
        << '\n';
    outputInfo(d1, "d1");
    std::cout << '\n';

    // Test 1.2
    std::cout << "[ Test 1.2 ]\n";
    MyDict<std::string, std::string> d2;
    d2["hello"] = "h";      // miss
    d2["world"] = "w";      // miss
    std::cout << d2[d1[0]]  // d2 hit, d1 hit
        << d2[d1[1]]        // d2 hit, d1 hit
        << d2[d1[2]]        // d2 miss, d1 miss
        << '\n';
    outputInfo(d1, "d1");
    outputInfo(d2, "d2");
    std::cout << '\n';

    // Test 1.3
    std::cout << "[ Test 1.3 ]\n";
    d1.clear();
    d2.clear();
    outputInfo(d1, "d1");
    outputInfo(d2, "d2");
    std::cout << '\n';

    // Test 1.4
    std::cout << "[ Test 1.4 ]\n";
    MyDict<int, int> cnt;
    for (int i = 2; i < 100; ++ i) {
        int num = i;
        for (int j = 2; j * j <= num; ++j) {
            while (num % j == 0) {
                ++cnt[j];
                num /= j;
            }
        }
        if (num > 1) {
            ++cnt[num];
        }
    }
    outputInfo(cnt, "cnt");
    for (auto i: {2, 3, 5, 7, 11, 13, 17, 19}) {
        std::cout << "cnt[" << i << "] = " << cnt[i] << '\n';
    }

    return 0;
}
