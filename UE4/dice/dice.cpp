#include <random>
#include "dice.h"

Dice::Dice() = default;

int Dice::roll() {
    std::random_device r;
    std::default_random_engine randomGenerator{r()};
    std::uniform_int_distribution<int> distribution{1,6};
    return distribution(randomGenerator);
}

std::vector<int> Dice::rollVector(int numberOfRolls) {
    std::vector<int> rolls{};
    rolls.reserve(numberOfRolls);
    for (int i = 0; i < numberOfRolls; i++) {
        rolls.push_back(roll());
    }
    return rolls;
}
