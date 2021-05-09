
#include <string>
#include <iostream>
#include <signal.h>
#include <cstdlib>
#include <algorithm>
#include "externallibrary.h"

// signal handlers
void signal_handler(int sig) {
    static int count{0};
    std::string sigName = sys_signame[sig];
    std::transform(sigName.begin(), sigName.end(), sigName.begin(), ::toupper);
    switch (sig) {
        // SIGKILL and SIGSTOP cannot be handled, ignored or blocked --> no handling needs to be defined
        // should terminate the program at the second occurrence using exit(int)
        case SIGINT:
            if (count == 0) { std::cout << "Received SIG" << sigName << " " << sig << " - IGNORING AND CONTINUING..." << std::endl; }
            else { std::cout << "Received SIG " sigName << " " << sig << " for the second time - EXITING NOW" << std::endl; exit(1); }
            break;
        // other signals defined by C and C++ should get ignored if permitted by the standard TODO use SIG_IGN ???
        default:
            std::cout << "Received SIG" << sigName << " " << sig << " - IGNORING AND CONTINUING..." << std::endl; break;
        // should be terminated using quick_exit(int) if not possible to ignore TODO ????
        // The program should not terminate in the case of other signals or thrown exceptions (those declared by C and C++ are sufficing) TODO ??????
    }
}

// Expected calls:
// ./runner 1
// ./runner 1000000
int main(int argc, char * argv[])
{
    signal(SIGFPE, (*signal_handler));
    signal(SIGABRT, (*signal_handler));
    signal(SIGINT, (*signal_handler));

    bool dryRun = atoi(argv[1]) < 1000000;
    initialize(dryRun);

    while (running())
    {
        //std::cout << "Processing events..." << std::endl;
        try {
            processEvents();
        }
        // exception handler
        catch(std::out_of_range::exception) {
            std::cout << "Caught Out Of Range Exception..." << std::endl;
            break;
        }
    }

    //std::cout << "Made it here! :)" << std::endl;
    return 0;
}
