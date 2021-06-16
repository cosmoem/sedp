
#include "LoggedDecorator.h"

NonMI::LoggedDecorator::LoggedDecorator(std::unique_ptr<Transaction> transaction) : Decorator(std::move(transaction)) {}

void NonMI::LoggedDecorator::onBeforeProcess(const std::string &operation) {
    std::cout << "[logged] ";
    transaction->onBeforeProcess(operation);
}

void NonMI::LoggedDecorator::onAfterProcess(const std::string &operation) {
    transaction->onAfterProcess(operation);
    std::cout << " [/logged]";
}
