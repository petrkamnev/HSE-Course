#pragma once
struct Point{
    double x;
    double y;

    Point();
    Point(const double& x_, const double& y_);

    bool operator ==(const Point& other);
    bool operator !=(const Point& other);
};