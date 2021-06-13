#pragma once

#include <vector>

class Dice {
public:
    Dice();
    std::vector<int> rollVector(int numberOfRolls);

private:
    int roll();
};