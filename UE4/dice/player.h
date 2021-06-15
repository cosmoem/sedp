#pragma once

#include <string>

class Player {
public:
    int addScore(int scoreToAdd);
    int getScore() const;
private:
    int score;
};