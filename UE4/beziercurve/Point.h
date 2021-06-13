#pragma once

class Point {

public:
    Point() = default;

    Point(double x, double y, double z) {
        this->values[0] = x;
        this->values[1] = y;
        this->values[2] = z;
    }

    Point(std::array<double, 3> array) : values(array) {
//        this->x = array[0];
//        this->y = array[1];
//        this->z = array[2];
    }

    double operator[](int index) const {
        return this->values[index];
    }

//    Point(std::initializer_list<double> list) {
//        std::array<double, 3> temp{};
//        std::copy(list.begin(), list.end(), temp.begin());
//        Point(temp);
//    }

private:
//    double x;
//    double y;
//    double z;
    std::array<double, 3> values;
};