#pragma once

#include <map>
#include "Point.h"

class CubicBezierCurve {
public:
    CubicBezierCurve();
    explicit CubicBezierCurve(Point p0, Point p1, Point p2, Point p3);
    CubicBezierCurve(CubicBezierCurve const &curve) = default;
    CubicBezierCurve(CubicBezierCurve &&curve) = default;

    void setControlPoint(int index, Point p);

    Point operator()(double t) const;

private:
    std::array<Point, 4> controlPoints;
    std::map<double, Point> cache;

    // https://www.geeksforgeeks.org/binomial-coefficient-dp-9/
    static int binomialCoefficient(int n, int k);

    // https://pages.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/Bezier/de-casteljau.html
    void computeCache();
    
    Point deCasteljauAlgorithm(double t) const;
    
    Point bernsteinPolynom(double t);
};
