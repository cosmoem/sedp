#include "LoggedTransaction.h"

MI::LoggedTransaction::LoggedTransaction(const std::string &name) : Transaction(name) {}

void MI::LoggedTransaction::onBeforeProcess(const std::string &operation) {
    std::cout << "[logged] ";
}

void MI::LoggedTransaction::onAfterProcess(const std::string &operation) {
    std::cout << " [/logged]";
}
