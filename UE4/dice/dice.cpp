#include "dice.h"
#include <cstdlib>
#include <ctime>

Dice::Dice() {
    srand(time(NULL));
}

int Dice::roll() {
    return rand() % 6 + 1;
}

std::vector<int> Dice::rollVector(int numberOfRolls) {
    std::vector<int> rolls{};
    rolls.reserve(numberOfRolls);

    for (int i = 0; i < numberOfRolls; i++) {
        rolls.push_back(roll());
    }
    return rolls;
}
