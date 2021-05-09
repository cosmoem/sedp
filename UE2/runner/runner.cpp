
#include <string>
#include <iostream>
#include <signal.h>
#include "externallibrary.h"

void signal_handler(int sig) {
    switch (sig) {
        case SIGFPE:
            std::cout << "Received SIGFPE " << sig << " - Floating Point Exception..." << std::endl;
            break;
        case SIGABRT:
            std::cout << "Received SIGABRT " << sig << " - Abort Trap..." << std::endl;
            break;
    }
}

// Expected calls:
// ./runner 1
// ./runner 1000000
int main(int argc, char * argv[])
{
    signal(SIGFPE, (*signal_handler));
    signal(SIGABRT, (*signal_handler));

    bool dryRun = atoi(argv[1]) < 1000000;
    initialize(dryRun);

    while (running())
    {
        //std::cout << "Processing events..." << std::endl;
        try {
            processEvents();
        }
        catch(std::out_of_range::exception) {
            std::cout << "Caught Out Of Range Exception..." << std::endl;
            break;
        }
    }

    //std::cout << "Made it here! :)" << std::endl;
    return 0;
}
