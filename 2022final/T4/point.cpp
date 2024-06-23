#include "point.h"

static int allocate_num = 0;
static int destroy_num = 0;

Point::Point(){
    allocate_num++;
}

Point::Point(int _x, int _y) : x(_x), y(_y){
    allocate_num++;
}

Point::Point(const Point& other): x(other.x), y(other.y){
    allocate_num++;
}

Point::~Point(){
    destroy_num++;
}

void Point::show_status(){
    std::cout << allocate_num << " " << destroy_num << std::endl;
}