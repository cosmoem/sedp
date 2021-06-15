#pragma once

#include <vector>
#include <random>

class Dice {
public:
    Dice();
    std::vector<int> rollVector(int numberOfRolls);

private:
    int roll();
    std::random_device r;
    std::default_random_engine randomGenerator;
    std::uniform_int_distribution<int> distribution;
};
