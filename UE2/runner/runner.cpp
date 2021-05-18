
#include <iostream>
#include <csignal>
#include <cstdlib>
#include <algorithm>
#include <regex>
#include "externallibrary.h"

void signal_handler(int sig) {
    static int count{0};
    std::string sigName = sys_signame[sig];
    std::transform(sigName.begin(), sigName.end(), sigName.begin(), ::toupper);
    switch (sig) {
        // SIGKILL and SIGSTOP cannot be handled, ignored or blocked --> no handling needs to be defined
        case SIGILL:
            std::cout << "Received SIG" << sigName << " " << sig << " - IGNORING AND CONTINUING..." << std::endl; exit(1);
        case SIGINT:
            count++;
            if (count == 1) { std::cout << "Received SIG" << sigName << " " << sig << " - IGNORING AND CONTINUING..." << std::endl; }
            else { std::cout << "Received SIG " << sigName << " " << sig << " for the second time - EXITING NOW" << std::endl; exit(1); }
            break;
        default:
            std::cout << "Received SIG" << sigName << " " << sig << " - IGNORING AND CONTINUING..." << std::endl; break;
    }
}

// Expected calls:
// ./runner 1
// ./runner 1000000
int main(int argc, char * argv[])
{
    signal(SIGFPE, (signal_handler));
    signal(SIGILL, (signal_handler));
    signal(SIGABRT, (signal_handler));
    signal(SIGINT, (signal_handler));

    bool dryRun = atoi(argv[1]) < 1000000;
    initialize(dryRun);

    // test handling of SIGINT
    //raise(SIGINT);
    //raise(SIGINT);

    while (running())
    {
        try {
            processEvents();
        }
        catch(std::out_of_range &e) {
            std::cout << "Caught " << e.what() << std::endl;
        }
        catch(std::regex_error &e) {
            std::cout << "Caught " << e.what() << std::endl;
        }
        catch(std::bad_cast &e) {
            std::cout << "Caught " << e.what() << std::endl;
        }
        catch(std::ios_base::failure &e) {
            std::cout << "Caught " << e.what() << std::endl;
        }
        catch(std::bad_function_call &e) {
            std::cout << "Caught " << e.what() << std::endl;
        }
        catch(std::system_error &e) {
            std::cout << "Caught " << e.what() << std::endl;
        }
        catch(std::invalid_argument &e) {
            std::cout << "Caught " << e.what() << std::endl;
        }
        catch(std::bad_alloc &e) {
            std::cout << "Caught " << e.what() << std::endl;
        }
    }

    return 0;
}
