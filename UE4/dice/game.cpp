#include "game.h"

#include <vector>
#include <iostream>
#include <numeric>

void Game::addPlayer(const Player &player) {
    this->players.push_back(player);
}

void Game::printGameState() {
    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player " << i + 1 << ": " << players.at(i).getScore() << '\n';
    }
    printTeamResults();
}


void Game::printTeamResults() {
    if (gameType == GameType::Seven) {
        std::cout << "-------" << '\n';
        std::cout << "First Team Score: " << getTeamScore(teams.first) << '\n';
        std::cout << "Second Team Score: " << getTeamScore(teams.second) << '\n';
    }
    std::cout << std::flush;
}

int Game::getTeamScore(std::vector<Player *> &team) {
    return std::accumulate(team.begin(), team.end(), 0, [](int acc, Player *player) {
        return acc + player->getScore();
    });
}


void Game::simulateNumberOfRounds(int numberOfRounds) {
    for (int i = 0; i < numberOfRounds; i++) {
        for (auto &player : players) {
            int scoreToAdd = 0;
            switch (this->gameType) {
                case GameType::Mud: {
                    this->simulateMudRound(scoreToAdd);
                    break;
                }
                case GameType::Seven: {
                    this->simulateSevenRound(scoreToAdd);
                    break;
                }
            }
            player.addScore(scoreToAdd);
        }
    }
}

Game::Game(int numberOfPlayers, GameType gameType) : gameType(gameType) {
    for (int i = 0; i < numberOfPlayers; i++) {
        this->addPlayer(Player());
    }

    if (gameType == Game::GameType::Seven) {
        this->generateTeams();
    }
}

void Game::generateTeams() {
    bool addFirst = true;
    for (auto &player : players) {
        if (addFirst) {
            teams.first.push_back(&player);
        } else {
            teams.second.push_back(&player);
        }

        addFirst = !addFirst;
    }
}

void Game::simulateSevenRound(int &scoreToAdd) {
    std::vector<int> roll = dice.rollVector(2);
    scoreToAdd = std::accumulate(roll.begin(), roll.end(), 0) == 7 ? 1 : 0;
}

void Game::simulateMudRound(int &scoreToAdd) {
    // for lean class design purposes, we decided to roll 1 dice 5 times. Otherwise it gets ugly
    int numberOfRolls = 5;
    while (numberOfRolls >= 1) {
        std::vector<int> roll = dice.rollVector(numberOfRolls);

        for (auto value : roll) {
            if (value == 2 || value == 5) {
                numberOfRolls--;
            } else {
                scoreToAdd += value;
            }
        }
    }
}

void Game::play(int numRounds) {
    this->simulateNumberOfRounds(numRounds);
}
