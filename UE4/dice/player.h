#pragma once

#include <string>

class Player {
public:
    int addScore(int scoreToAdd);
    int getScore();
private:
    int score;
};