#include "SecuredTransaction.h"

MI::SecuredTransaction::SecuredTransaction(const std::string &name) : Transaction(name) {}

void MI::SecuredTransaction::onBeforeProcess(const std::string &operation) {
    std::cout << "[secured] ";
}

void MI::SecuredTransaction::onAfterProcess(const std::string &operation) {
    std::cout << " [/secured]";
}
