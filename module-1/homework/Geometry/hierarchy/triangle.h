#pragma once
#include "polygon.h"
#include "circle.h"

class Triangle : public Polygon{
    public:
    Triangle(const Point&a , const Point&b, const Point&c);
    Circle circumscribedCircle();
    Circle inscribedCircle();
};