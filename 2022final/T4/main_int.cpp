#include "pvector.h"
using namespace std;

int main(){

    #ifdef SUBTASK1
    // Subtask 1
    cout << "Subtask 1" << endl;
    PVector<int> a1;                  // Create an empty PVector, a1 = []
    // cout << a1 << endl;               // Output: []
    auto a2 = a1.push_back(1);        // a2 = [1]
    // cout << a2 << endl;               // Output: [1]
    int index = 0, value = 2;
    auto a3 = a2.set(index, value);   // modify an element, a3 = [2]
    // cout << a3 << endl;               // Output: [2]
    auto a4 = a2.push_back(3);        // a4 = [1, 3]
    // cout << a4 << endl;               // Output: [1, 3]
    // cout << a4[1] << endl;            // Output: 3
    auto a5 = a4.push_back(5);        // a5 = [1, 3, 5]
    // cout << a5 << endl;               // Output: [1, 3, 5]
    #endif

    #ifdef SUBTASK2
    // Subtask 2
    cout << "Subtask 2" << endl;
    auto b4 = a5.undo();             // b4 = [1, 3]
    cout << b4 << endl;
    auto b2 = b4.undo();             // b3 = [1]
    cout << b2 << endl;
    auto b1 = b2.undo();             // b1 = []
    cout << b1 << endl;
    b1.undo();                       // Output: cannot undo
    auto b6 = b2.push_back(0);       // b6 = [1, 0]
    cout << b6 << endl;
    #endif

    #ifdef SUBTASK3
    // Subtask 3
    cout << "Subtask 3" << endl;
    auto c7 = a3.update(a5);        // c7 = [2, 3, 5]
    cout << c7 << endl;
    auto c3 = c7.undo();            // c3 = [2]
    cout << c3 << endl;
    auto c8 = a5.update(a3);        // c8 = [2, 3, 5]
    cout << c8 << endl;
    auto c5 = c8.undo();            // c5 = [1, 3, 5]
    cout << c5 << endl;
    auto c9 = a1.update(c8);        // c9 = [2, 3, 5]
    cout << c9 << endl;
    auto c10 = c8.update(a1);       // c10 = [2, 3, 5]
    cout << c10 << endl;
    auto c11 = c10.undo();          // c11 = [2, 3, 5]
    cout << c11 << endl;

    PVector<int> other;
    a3.update(other);                 // Output: cannot update: no origin found
    a4.update(b6);                    // Output: cannot update: conflicts found
    c10.update(b6);                   // Output: cannot update: conflicts found
    a2.update(c9);                    // Output: cannot update: conflicts found
    #endif

    return 0;
}
