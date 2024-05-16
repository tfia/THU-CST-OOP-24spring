#include "point.h"
#include "compare.h"
#include "priority_queue.h"
#include <iostream>
#include <cassert>

template<class T> void processOperation(PriorityQueue<T> &q) {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int op;
        std::cin >> op;
        assert(op == 1 || op == 2 || op == 3 || op == 4);
        if(op == 1) {
            T element;
            std::cin >> element;
            q.push(element);
        }
        else if(op == 2) {
            if(!q.empty()) {
                q.pop();
            }
        }
        else if(op == 3) {
            if(q.empty()) {
                std::cout << "invalid operation" << std::endl;
            }
            else {
                std::cout << q.top() << std::endl;
            }
        }
        else {
            std::cout << q.size() << std::endl;
        }
    }
    std::cout << "------------input finished------------" << std::endl;
    while(!q.empty()) {
        std::cout << q.top() << std::endl;
        q.pop();
    }
}

int main() {
    freopen("test4.in", "r", stdin);
    freopen("test4.out", "w", stdout);
    int type;
    std::cin >> type;

    if (type == 1 || type == 2) {
        AbstractCompare<int>* cmp = get_compare_int(type);
        auto q = PriorityQueue<int>(cmp);
        processOperation(q);
    } else if (type == 3 || type == 4) {
        AbstractCompare<Point>* cmp = get_compare_point(type);
        auto q = PriorityQueue<Point>(cmp);
        processOperation(q);
    }

    return 0;
}