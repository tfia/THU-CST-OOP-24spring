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
    // Test 4.1
    std::cout << "[ Test 4.1 ]\n";
    PopStrategy<int>* d1Strategy = new FIFOStrategy<int>();
    MyDict<int, std::string> d1Inner;
    MyDict<int, std::string> d1(2, d1Strategy, &d1Inner);
    d1[0] = "hello ";   // level-1 miss; level-2 miss
    d1[2] = "!";        // level-1 miss; level-2 miss
    d1[0] = "Hello ";   // level-1 hit
    d1[1] = "";         // level-1 miss, d1[0] poped; level-2 miss (d1[0]) + miss (d1[1])
    d1[1] = "world";    // level-1 hit
    std::cout << d1[0]  // level-1 miss, d1[2] poped; level-2 hit (d1[0]) + miss (d1[2])
        << d1[1]        // level-1 hit
        << d1[2]        // level-1 miss, d1[1] poped; level-2 hit (d1[2]) + miss (d1[1])
        << '\n';
    outputInfo(d1, "d1");
    std::cout << '\n';

    // Test 4.2
    std::cout << "[ Test 4.2 ]\n";
    d1.clear();
    outputInfo(d1, "d1");
    std::cout << '\n';

    // Test 4.3
    std::cout << "[ Test 4.3 ]\n";
    PopStrategy<int>* cntStrategy[] = {
        new LRUStrategy<int>(),
        new FIFOStrategy<int>(),
    };
    MyDict<int, int> cntLevel3;
    MyDict<int, int> cntLevel2(12, cntStrategy[1], &cntLevel3);
    MyDict<int, int> cntLevel1(8, cntStrategy[0], &cntLevel2);
    MyDict<int, int>& cnt = cntLevel1;
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

    delete cntStrategy[0];
    delete cntStrategy[1];

    return 0;
}
