
#include "provider.h"

#include <sstream>
#include <string>

// pass PROVIDER_NAME using compiler options
#define PROVIDER_NAME "Test Provider Name" // TODO das ist wahrscheinlich falsch.. aufgagbe sagt "to be passed as compile-time arguments"

namespace provider
{


std::string providerInfo(const bool date)
{
    auto stream = std::stringstream { };

    // output provider name using the PROVIDER_NAME defined for compilation
    stream << "Provider Name: " << PROVIDER_NAME;

    // if date is true, output the date of compilation as well using predefined c++ macros
    if(date) {
        stream << ", Compilation Date: " __DATE__;
    }

    stream << std::endl;

    return stream.str();
}


}