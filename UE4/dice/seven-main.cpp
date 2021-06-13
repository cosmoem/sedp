
#include <iostream>
#include "game.h"


int main(int argc, char * argv[])
{
    const auto printUsage = [argv] { std::cout << "usage: " << argv[0] << " <num players> <num rounds>" << std::endl; };
    if (argc != 3)
    {
        printUsage();
        return EXIT_FAILURE;
    }

    auto numPlayers = 0;
    auto numRounds = 0;
    try
    {
        numPlayers = std::stoul(argv[1]);
        numRounds = std::stoul(argv[2]);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        printUsage();
        return EXIT_FAILURE;
    }

    // TODO: create game
    Game game = Game("seven");

    // TODO: create players
    for (int i = 0; i < numPlayers; i++) {
        game.addPlayer(Player());
    }

    // TODO: create teams
    // TODO: was soll denn mit den Teams geschehen? XD
    game.generateTeams();

    // TODO: simulate game
    game.simulateNumberOfRounds(numRounds);

    // TODO: output results
    game.printGameState();
}
