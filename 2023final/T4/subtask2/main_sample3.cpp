#include <iostream>
#include "PopStrategy.hpp"

int main() {
    // Test 2.1
    std::cout << "[ Test 2.1 ]\n";
    FIFOStrategy<char> fifo;
    fifo.visit('a');
    fifo.visit('b');
    fifo.visit('a');
    fifo.visit('c');
    std::cout << fifo.pop() << '\n'; // a
    fifo.visit('a');
    std::cout << fifo.pop() << '\n'; // b
    std::cout << '\n';

    // Test 2.2
    std::cout << "[ Test 2.2 ]\n";
    LRUStrategy<char> lru;
    lru.visit('a');
    lru.visit('b');
    lru.visit('a');
    lru.visit('c');
    std::cout << lru.pop() << '\n'; // b
    lru.visit('a');
    std::cout << lru.pop() << '\n'; // c

    return 0;
}