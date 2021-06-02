#include "modcounter.h"

ModuloCounter::ModuloCounter(int value, int min, int max) : min(min), max(max) {
    this->value = wrap(value, min, max);
}

ModuloCounter::ModuloCounter(int min, int max) : min(min), max(max) {
    if (min <= 0 && max > 0) {
        this->value = 0;
    }
    else {
        this->value = min;
    }
}

ModuloCounter::ModuloCounter(ModuloCounter &other) : value(other.getValue()), min(other.getMin()), max(other.getMax()) {}

ModuloCounter::ModuloCounter(ModuloCounter &&other) noexcept: value(std::move(other.getValue())), min(std::move(other.getMin())),
                                                              max(std::move(other.getMax())) {}

ModuloCounter::operator int() const {
    return value;
}

ModuloCounter &ModuloCounter::operator=(const int &value) {
    this->value = wrap(value, this->min, this->max);
    return *this;
}

ModuloCounter &ModuloCounter::operator=(const ModuloCounter &modCounter) {
    this->value = wrap(modCounter.getValue(), this->min, this->max);
    return *this;
}

ModuloCounter operator+(const ModuloCounter &modCounter, const int &value) {
    int temp = modCounter.getValue() + value;
    return ModuloCounter(ModuloCounter::wrap(temp, modCounter.getMin(), modCounter.getMax()), modCounter.getMin(), modCounter.getMax());
}

int operator+(const int &value, ModuloCounter &modCounter) {
    return modCounter.getValue() + value;
}

ModuloCounter operator+(const ModuloCounter &modCounter, const ModuloCounter &modCounterTwo) {
    int temp = modCounter.getValue() + modCounterTwo.getValue();
    return ModuloCounter(ModuloCounter::wrap(temp, modCounter.getMin(), modCounter.getMax()), modCounter.getMin(), modCounter.getMax());
}

ModuloCounter &operator++(ModuloCounter &modCounter) {
    modCounter = modCounter + 1;
    return modCounter;
}

ModuloCounter &operator++(ModuloCounter &modCounter, int) {
    modCounter = modCounter + 1;
    return modCounter;
}

ModuloCounter operator-(const ModuloCounter &modCounter, const int &value) {
    int temp = modCounter.getValue() - value;
    return ModuloCounter(ModuloCounter::wrap(temp, modCounter.getMin(), modCounter.getMax()), modCounter.getMin(), modCounter.getMax());
}

int operator-(const int &value, const ModuloCounter &modCounter) {
    return modCounter.getValue() - value;
}

ModuloCounter operator-(const ModuloCounter &modCounter, const ModuloCounter &modCounterTwo) {
    int temp = modCounter.getValue() - modCounterTwo.getValue();
    return ModuloCounter(ModuloCounter::wrap(temp, modCounter.getMin(), modCounter.getMax()), modCounter.getMin(), modCounter.getMax());
}

ModuloCounter &operator--(ModuloCounter &modCounter) {
    modCounter = modCounter - 1;
    return modCounter;
}

ModuloCounter &operator--(ModuloCounter &modCounter, int) {
    modCounter = modCounter - 1;
    return modCounter;
}

ModuloCounter operator*(const ModuloCounter &modCounter, const int &value) {
    int temp = modCounter.getValue() * value;
    return ModuloCounter(ModuloCounter::wrap(temp, modCounter.getMin(), modCounter.getMax()), modCounter.getMin(), modCounter.getMax());
}

int operator*(const int &value, const ModuloCounter &modCounter) {
    return modCounter.getValue() * value;
}

ModuloCounter operator*(const ModuloCounter &modCounter, const ModuloCounter &modCounterTwo) {
    int temp = modCounter.getValue() * modCounterTwo.getValue();
    return ModuloCounter(ModuloCounter::wrap(temp, modCounter.getMin(), modCounter.getMax()), modCounter.getMin(), modCounter.getMax());
}

ModuloCounter operator/(const ModuloCounter &modCounter, const int &value) {
    int temp = modCounter.getValue() / value;
    return ModuloCounter(ModuloCounter::wrap(temp, modCounter.getMin(), modCounter.getMax()), modCounter.getMin(), modCounter.getMax());
}

int operator/(const int &value, const ModuloCounter &modCounter) {
    return modCounter.getValue() / value;
}

ModuloCounter operator/(const ModuloCounter &modCounter, const ModuloCounter &modCounterTwo) {
    int temp = modCounter.getValue() / modCounterTwo.getValue();
    return ModuloCounter(ModuloCounter::wrap(temp, modCounter.getMin(), modCounter.getMax()), modCounter.getMin(), modCounter.getMax());
}

int ModuloCounter::wrap(int value, int min, int max) {
    if (value >= max || value < min) {
        int intervalSize = max - min;
        int newValue = value - intervalSize * ((value - min) / intervalSize);
        if (newValue >= max || newValue < min) {
            newValue = value - intervalSize * ((value) / intervalSize);
        }
        return newValue;
    } else {
        return value;
    }
}

int ModuloCounter::getValue() const {
    return value;
}

const int ModuloCounter::getMin() const {
    return min;
}

const int ModuloCounter::getMax() const {
    return max;
}

std::ostream &operator<<(std::ostream &os, ModuloCounter &modCounter) {
    os << modCounter.getValue()<< " in [" << modCounter.getMin() << ", " << modCounter.getMax() << ")" << std::endl;
    return os;
}
