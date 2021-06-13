#include "game.h"

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <numeric>

Game::GameType Game::resolveGameType(const std::string &type) {
    if (type == "mud") {
        return GameType::Mud;
    } else {
        return GameType::Seven;
    }
}

void Game::addPlayer(const Player &player) {
    this->players.push_back(player);
}

void Game::printGameState() {
    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player " << i+1 << ": " << players.at(i).getScore() << '\n';
    }
}

void Game::simulateNumberOfRounds(int numberOfRounds) {
    for (int i = 0; i < numberOfRounds; i++) {
        for (auto &player : players) {
            int scoreToAdd = 0;
            switch (resolveGameType(this->gameType)) {
                case GameType::Mud: {
                    std::vector<int> roll = dice.rollVector(5);
                    scoreToAdd = std::accumulate(roll.begin(), roll.end(), 0, [](int acc, int number) {
                        if (number == 2 || number == 5) {
                            return acc;
                        } else {
                            return acc + number;
                        }
                    });
                    break;
                }
                case GameType::Seven: {
                    std::vector<int> roll = dice.rollVector(2);
                    scoreToAdd = std::accumulate(roll.begin(), roll.end(), 0) == 7 ? 1 : 0;
                    break;
                }
            }
            player.addScore(scoreToAdd);
        }
    }
}

Game::Game(std::string gameType) : gameType(std::move(gameType)) {}

void Game::generateTeams() {
    bool addFirst = true;
    for (auto player : players) {
        if (addFirst) {
            teams.first.push_back(&player);
        } else {
            teams.second.push_back(&player);
        }

        addFirst = !addFirst;
    }
}
