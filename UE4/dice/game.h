#pragma once

#include "dice.h"
#include "player.h"
#include <string>
#include <vector>

class Game {
public:
    explicit Game(std::string gameType = "mud");
    void simulateNumberOfRounds(int numberOfRounds);
    void addPlayer(const Player& player);
    void printGameState();
    void generateTeams();
private:
    std::pair<std::vector<Player*>, std::vector<Player*>> teams;
    std::string gameType;
    Dice dice;
    std::vector<Player> players;
    enum GameType {
        Mud,
        Seven,
    };
    GameType resolveGameType(const std::string& type);
};