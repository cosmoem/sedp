#include "dice.h"

Dice::Dice() {
    randomGenerator = std::default_random_engine {r()};
    distribution = std::uniform_int_distribution {1,6};
}

int Dice::roll() {
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
