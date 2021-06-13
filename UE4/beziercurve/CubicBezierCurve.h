
#pragma once

#include <vector>
#include <map>
#include "Point.h"

class CubicBezierCurve {
public:
    // TODO init with 0
//    CubicBezierCurve() {
//
//    };

    CubicBezierCurve(std::initializer_list<std::initializer_list<double>> lists);

    Point operator()(double t) const;

    // TODO: copy constructor does not work for whatever reason -> so use assignment constructor
    CubicBezierCurve &operator=(const CubicBezierCurve &other) {
        this->controlPoints = other.controlPoints;
        this->cache = other.cache;
        return *this;
    }

    void setControlPoint(int index, Point controlPoint) {
        controlPoints[index] = controlPoint;
    }

private:
    std::vector<Point> controlPoints;
    std::map<double, double> cache;

    int binomialCoefficient(int n, int k) const {
        int res = 1;

        // Since C(n, k) = C(n, n-k)
        if (k > n - k)
            k = n - k;

        // Calculate value of
        // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
        for (int i = 0; i < k; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }

        return res;
    }
};

Point CubicBezierCurve::operator()(double t) const {
    // here werden die values returned :)
    // caching noch einbauen
    // und was ist wenn cache nicht genau trifft
    double x = 0;
    double y = 0;
    double z = 0;
    for (int i = 0; i < 4; i++) {
        x += binomialCoefficient(3, i) * std::pow((1-t), 3-i) * std::pow(t, i) * controlPoints[i][0];
        y += binomialCoefficient(3, i) * std::pow((1-t), 3-i) * std::pow(t, i) * controlPoints[i][1];
        z += binomialCoefficient(3, i) * std::pow((1-t), 3-i) * std::pow(t, i) * controlPoints[i][2];
    }

    return {x, y, z};
}

CubicBezierCurve::CubicBezierCurve(std::initializer_list<std::initializer_list<double>> lists) {
    // TODO: there must be an easier way to do this shit
    std::array<double, 3> temp{};
    for (auto list : lists) {
        std::copy(list.begin(), list.end(), temp.begin());
        controlPoints.emplace_back(temp);
    }

    // calculate cache
    /*
     *
     */
//    for (auto t = 0.0; t <= 1.0; t += 1.0 / 256.0) {
//        cache[t] =
//    }
}

//CubicBezierCurve::CubicBezierCurve() {
//
//}
