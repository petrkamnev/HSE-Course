#include "point.h"
#include <cmath>

Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(const double& x_, const double& y_){
    x = x_;
    y = y_;
}

bool Point::operator==(const Point& other){
    return (abs(x - other.x) < 1e-9) && (abs(y - other.y) < 1e-9);
}

bool Point::operator!=(const Point& other){
    return !(*this == other);
}