
#pragma once

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

    Point& operator+=(Point point) {
        this->coordinates[0] = (point.coordinates[0]+this->coordinates[0]);
        this->coordinates[1] = (point.coordinates[1]+this->coordinates[1]);
        this->coordinates[2] = (point.coordinates[2]+this->coordinates[2]);
        return *this;
    }
};

class CubicBezierCurve {
public:
    CubicBezierCurve() = default;
    explicit CubicBezierCurve(Point p0, Point p1, Point p2, Point p3) : controlPoints{p0, p1, p2, p3} {}
    CubicBezierCurve(CubicBezierCurve const &curve) = default;
    CubicBezierCurve(CubicBezierCurve &&curve) = default;

    void setControlPoint(int index, Point p) {
        controlPoints[index] = p;
    }

    Point operator()(double t) const {
        Point curvePoint = Point();
        for (int i = 0; i <= 3; i++) {
            Point p = binomialCoefficient(3, i) * std::pow(1 - t, 3 - i) * std::pow(t, i) * controlPoints[i];
            curvePoint += p;
        }
        return curvePoint;
    }

private:
    std::array<Point, 4> controlPoints;

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
};
