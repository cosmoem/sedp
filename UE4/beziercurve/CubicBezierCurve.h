
#pragma once

#include <map>

class Point {
private:
    std::array<double, 3> coordinates;
public:
    Point() : coordinates{0,0,0} {}
    Point(double x, double y, double z) : coordinates{x, y, z} {}

    double operator[](int index) const {
        return coordinates[index];
    }

    friend Point operator*(double value, Point point) {
        return Point(
            value*point.coordinates[0],
            value*point.coordinates[1],
            value*point.coordinates[2]
        );
    }

    Point operator+(Point point) {
        return Point(
            point.coordinates[0]+this->coordinates[0],
            point.coordinates[1]+this->coordinates[1],
            point.coordinates[2]+this->coordinates[2]
        );
    }

    Point& operator+=(Point point) {
        this->coordinates[0] = (point.coordinates[0]+this->coordinates[0]);
        this->coordinates[1] = (point.coordinates[1]+this->coordinates[1]);
        this->coordinates[2] = (point.coordinates[2]+this->coordinates[2]);
        return *this;
    }
};

class CubicBezierCurve {
public:
    CubicBezierCurve() {
        computeCache();
    }
    explicit CubicBezierCurve(Point p0, Point p1, Point p2, Point p3) : controlPoints{p0, p1, p2, p3} {
        computeCache();
    }
    CubicBezierCurve(CubicBezierCurve const &curve) = default;
    CubicBezierCurve(CubicBezierCurve &&curve) = default;

    void setControlPoint(int index, Point p) {
        controlPoints[index] = p;
        computeCache();
    }

    Point operator()(double t) const {
        return cache.contains(t) ? cache.at(t) : deCasteljauAlgorithm(t);
    }

private:
    std::array<Point, 4> controlPoints;
    std::map<double, Point> cache;

    // https://www.geeksforgeeks.org/binomial-coefficient-dp-9/
    static int binomialCoefficient(int n, int k) {
        if (k > n) {
            return 0;
        }
        if (k == 0 || k == n) {
            return 1;
        }
        return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
    }

    // https://pages.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/Bezier/de-casteljau.html
    void computeCache() {
        for (auto t = 0.0; t <= 1.0; t += 1.0 / 256.0) {
            cache[t] = deCasteljauAlgorithm(t);
            //cache[t] = bernsteinPolynom(t); <-- alternative
        }
    }
    
    Point deCasteljauAlgorithm(double t) const {
        std::array<Point, 4> copy = controlPoints;
        int n = controlPoints.size()-1;
        for (int k = 1; k <= n; k++) {
            for (int i = 0; i <= n - k; i++) {
                copy[i] = (1 - t) * copy[i] + t * copy[i+1];
            }
        }
        return copy[0];
    }
    
    Point bernsteinPolynom(double t) {
        Point curvePoint = Point();
        for (int i = 0; i <= 3; i++) {
            Point p = binomialCoefficient(3, i) * std::pow(1 - t, 3 - i) * std::pow(t, i) * controlPoints[i];
            curvePoint += p;
        }
        return curvePoint;
    }
};
