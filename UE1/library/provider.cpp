
#include "provider.h"

#include <sstream>
#include <string>

// pass PROVIDER_NAME using compiler options
#define PROVIDER_NAME "Alison Trettin & Anna-Frieda Gruse"
/*
 alternatively use the following when compiling to pass via command line:
 g++ -std=c++14 -D PROVIDER_API_EXPORTS -D PROVIDER_NAME="\"Alison Trettin & Anna-Frieda Gruse\"" -o provider.o -I./ -c ./provider.cpp
*/

namespace provider
{


std::string providerInfo(const bool date)
{
    auto stream = std::stringstream { };

    // output provider name using the PROVIDER_NAME defined for compilation
    stream << "Provider Name: " << PROVIDER_NAME;

    // if date is true, output the date of compilation as well using predefined c++ macros
    if(date) {
        stream << ", Compilation Date and Time: " __DATE__ << ", " << __TIME__;
    }

    stream << std::endl;

    return stream.str();
}


}