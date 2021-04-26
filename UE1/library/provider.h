
#pragma once

#include <string>

// define PROVIDER_API for cross-platform use
#ifdef PROVIDER_API_EXPORTS
  // building the library
  #define PROVIDER_API __attribute__((visibility("default")))
#else
  // using the library
  #define PROVIDER_API __attribute__((visibility("default")))
#endif


namespace provider
{


PROVIDER_API std::string providerInfo(bool date = false);


} // namespace provider
