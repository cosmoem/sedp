#include "Point.h"

Point::Point() : coordinates{0,0,0} {}

Point::Point(double x, double y, double z) : coordinates{x, y, z} {}

double Point::operator[](int index) const {
    return coordinates[index];
}

Point operator*(double value, Point point) {
    return Point(
            value*point.coordinates[0],
            value*point.coordinates[1],
            value*point.coordinates[2]
    );
}

Point Point::operator+(Point point) {
    return Point(
            point.coordinates[0]+this->coordinates[0],
            point.coordinates[1]+this->coordinates[1],
            point.coordinates[2]+this->coordinates[2]
    );
}

Point &Point::operator+=(Point point) {
    this->coordinates[0] = (point.coordinates[0]+this->coordinates[0]);
    this->coordinates[1] = (point.coordinates[1]+this->coordinates[1]);
    this->coordinates[2] = (point.coordinates[2]+this->coordinates[2]);
    return *this;
}
