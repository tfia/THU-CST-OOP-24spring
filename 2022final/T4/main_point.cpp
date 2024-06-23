#include "pvector.h"
#include "point.h"
using namespace std;

int main(){

    {
        #ifdef SUBTASK1
        // Subtask 1
        PVector<Point> a1;
        cout << a1 << endl;
        auto pad1 = a1.push_back(Point(0, 0)); // make the sequence longer to check the allocation number
        auto pad2 = pad1.push_back(Point(0, 0));
        auto pad3 = pad2.push_back(Point(0, 0));
        auto pad4 = pad3.push_back(Point(0, 0));
        auto pad5 = pad4.push_back(Point(0, 0));
        auto pad6 = pad5.push_back(Point(0, 0));
        auto pad7 = pad6.push_back(Point(0, 0));
        auto pad8 = pad7.push_back(Point(0, 0));
        auto pad9 = pad8.push_back(Point(0, 0));
        auto pad0 = pad9.push_back(Point(0, 0));
        auto a2 = pad0.push_back(Point(1, 2));
        cout << a2 << endl;
        int index = 0; Point value(3, 4);
        auto a3 = a2.set(index, value);
        cout << a3 << endl;
        auto a4 = a2.push_back(Point(5, 6));
        cout << a4 << endl;
        cout << a4[1] << endl;
        auto a5 = a4.push_back(Point(9, 10));
        cout << a5 << endl;
        #endif

        #ifdef SUBTASK2
        // Subtask 2
        auto b4 = a5.undo();
        cout << b4 << endl;
        auto b2 = b4.undo();
        cout << b2 << endl;
        auto b1 = b2.undo();
        cout << b1 << endl;
        a1.undo();
        auto b6 = b2.push_back(Point(-1, 0));
        cout << b6 << endl;
        #endif

        #ifdef SUBTASK3
        // Subtask 3
        auto c7 = a3.update(a5);
        cout << c7 << endl;
        auto c3 = c7.undo();
        cout << c3 << endl;
        auto c8 = a5.update(a3);
        cout << c8 << endl;
        auto c5 = c8.undo();
        cout << c5 << endl;
        auto c9 = a1.update(c8);
        cout << c9 << endl;
        auto c10 = a3.update(b4);
        cout << c10 << endl;

        PVector<Point> other;
        a3.update(other);
        c10.update(b6);
        #endif
    }

    Point::show_status();

    return 0;
}
