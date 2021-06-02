#ifndef SEDP_EXERCISE3_MODCOUNTER_H
#define SEDP_EXERCISE3_MODCOUNTER_H

#endif //SEDP_EXERCISE3_MODCOUNTER_H

#include <iostream>

class ModuloCounter {

private:
    signed int value;
    const signed int min;
    const signed int max;

public:
    ModuloCounter(signed int value, signed int min, signed int max);

    ModuloCounter(signed int min, signed int max);

    // Copy Constructor
    ModuloCounter(ModuloCounter &other);

    // Move Constructor
    ModuloCounter(ModuloCounter &&other)  noexcept;

    // Type Conversion Operators
    explicit operator int() const;

    // Assignment
    ModuloCounter& operator=(const int &value);

    ModuloCounter& operator=(const ModuloCounter &modCounter);

    // Arithmetic
    friend ModuloCounter operator+(const ModuloCounter &modCounter, const int &value);

    friend int operator+(const int &value, ModuloCounter &modCounter);

    friend ModuloCounter operator+(const ModuloCounter &modCounter, const ModuloCounter &modCounterTwo);

    friend ModuloCounter& operator++(ModuloCounter &modCounter);

    friend ModuloCounter& operator++(ModuloCounter &modCounter, int);

    friend ModuloCounter operator-(const ModuloCounter &modCounter, const int &value);

    friend int operator-(const int &value, const ModuloCounter &modCounter);

    friend ModuloCounter operator-(const ModuloCounter &modCounter, const ModuloCounter &modCounterTwo);

    friend ModuloCounter& operator--(ModuloCounter &modCounter);

    friend ModuloCounter& operator--(ModuloCounter &modCounter, int);

    friend ModuloCounter operator*(const ModuloCounter &modCounter, const int &value);

    friend int operator*(const int &value, const ModuloCounter &modCounter);

    friend ModuloCounter operator*(const ModuloCounter &modCounter, const ModuloCounter &modCounterTwo);

    friend ModuloCounter operator/(const ModuloCounter &modCounter, const int &value);

    friend int operator/(const int &value, const ModuloCounter &modCounter);

    friend ModuloCounter operator/(const ModuloCounter &modCounter, const ModuloCounter &modCounterTwo);

    static int wrap(int value, int min, int max);

    // Getters
    int getValue() const;

    const int getMin() const;

    const int getMax() const;

    // Stream
    friend std::ostream & operator <<(std::ostream &os, ModuloCounter &modCounter);
};
