#pragma once
#include "rectangle.h"
#include "circle.h"

class Square : public Rectangle{
    Square(const Point& p1, const Point& p2);
    Circle circumscribedCircle();
    Circle inscribedCircle();
};
