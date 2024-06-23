#include<iostream>
#include"Line.cpp"
#include"Point.cpp"
using namespace std;

int main() {
    
    Point<int> p1(2,4);
    p1.move(3,2);
    p1.show();
    // 此处应该输出(5,6) 
     
    Line<int> line1(2);
    Line<int> line2(2, 4);
    cout << line1.intersect(line2) << endl;
    // 此处应输出 0

    Line<int> line3(3);
    Line<int> line4(2, 6);
    if (line3 < line4) line3.show();
    else line4.show();
    // 此处应输出 2,6
    
    Point<int> p2(4,12);
    cout<<p2.check(line2)<<endl;
    //此处应该输出1
    return 0;
}
