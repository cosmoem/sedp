#pragma once

#include <array>

class Point {
private:
    std::array<double, 3> coordinates;
public:
    Point();
    Point(double x, double y, double z);

    double operator[](int index) const;

    friend Point operator*(double value, Point point);

    Point operator+(Point point);

    Point& operator+=(Point point);
};
