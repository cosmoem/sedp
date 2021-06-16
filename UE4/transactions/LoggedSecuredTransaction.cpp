
#include "LoggedSecuredTransaction.h"

MI::LoggedSecuredTransaction::LoggedSecuredTransaction(const std::string &name) : LoggedTransaction(name), SecuredTransaction(name) {}

void MI::LoggedSecuredTransaction::onBeforeProcess(const std::string &operation) {
    LoggedTransaction::onBeforeProcess(operation);
    SecuredTransaction::onBeforeProcess(operation);
}

void MI::LoggedSecuredTransaction::onAfterProcess(const std::string &operation) {
    SecuredTransaction::onAfterProcess(operation);
    LoggedTransaction::onAfterProcess(operation);
}
