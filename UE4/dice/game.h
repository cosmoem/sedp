#pragma once

#include "dice.h"
#include "player.h"
#include <string>
#include <vector>

class Game {
public:
    enum GameType {
        Mud,
        Seven,
    };
    explicit Game(int numberOfPlayers, GameType gameType = GameType::Mud);
    void simulateNumberOfRounds(int numberOfRounds);
    void addPlayer(const Player& player);
    void printGameState();
    void generateTeams();
    void play(int numRounds);
private:
    GameType gameType;
    std::pair<std::vector<Player*>, std::vector<Player*>> teams;
    Dice dice;
    std::vector<Player> players;
    void simulateSevenRound(int &scoreToAdd);
    void simulateMudRound(int &scoreToAdd);
    void printTeamResults();
    int getTeamScore(std::vector<Player*> &team);
};