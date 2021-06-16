#include "SecuredDecorator.h"

NonMI::SecuredDecorator::SecuredDecorator(std::unique_ptr<Transaction> transaction) : Decorator(std::move(transaction)) {}

void NonMI::SecuredDecorator::onBeforeProcess(const std::string &operation) {
    std::cout << "[secured] ";
    transaction->onBeforeProcess(operation);
}

void NonMI::SecuredDecorator::onAfterProcess(const std::string &operation) {
    transaction->onAfterProcess(operation);
    std::cout << " [/secured]";
}
