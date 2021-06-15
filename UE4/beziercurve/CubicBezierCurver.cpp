#include <cmath>
#include "CubicBezierCurve.h"

CubicBezierCurve::CubicBezierCurve() {
    computeCache();
}

CubicBezierCurve::CubicBezierCurve(Point p0, Point p1, Point p2, Point p3) : controlPoints{p0, p1, p2, p3} {
    computeCache();
}

void CubicBezierCurve::setControlPoint(int index, Point p) {
    controlPoints[index] = p;
    computeCache();
}

Point CubicBezierCurve::operator()(double t) const {
    return cache.contains(t) ? cache.at(t) : deCasteljauAlgorithm(t);
}

int CubicBezierCurve::binomialCoefficient(int n, int k) {
    if (k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

void CubicBezierCurve::computeCache() {
    for (auto t = 0.0; t <= 1.0; t += 1.0 / 256.0) {
        cache[t] = deCasteljauAlgorithm(t);
        //cache[t] = bernsteinPolynom(t); <-- alternative
    }
}

Point CubicBezierCurve::deCasteljauAlgorithm(double t) const {
    std::array<Point, 4> copy = controlPoints;
    int n = controlPoints.size()-1;
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i <= n - k; i++) {
            copy[i] = (1 - t) * copy[i] + t * copy[i+1];
        }
    }
    return copy[0];
}

Point CubicBezierCurve::bernsteinPolynom(double t) {
    Point curvePoint = Point();
    for (int i = 0; i <= 3; i++) {
        Point p = binomialCoefficient(3, i) * std::pow(1 - t, 3 - i) * std::pow(t, i) * controlPoints[i];
        curvePoint += p;
    }
    return curvePoint;
}
