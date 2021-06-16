
#include "Transaction.h"

#include <iostream>


MI::Transaction::Transaction(const std::string &name) : m_name{name} {}


const std::string &MI::Transaction::name() const {
    return m_name;
}


void MI::Transaction::process(const std::string &operation) {
    onBeforeProcess(operation);

    std::cout << "TA '" << m_name << "': " << operation;

    onAfterProcess(operation);
}


void MI::Transaction::onBeforeProcess(const std::string &operation) {}


void MI::Transaction::onAfterProcess(const std::string &operation) {}

//////////////////////

NonMI::Transaction::Transaction(const std::string &name) : m_name{name} {}


const std::string &NonMI::Transaction::name() const {
    return m_name;
}


void NonMI::Transaction::process(const std::string &operation) {
    onBeforeProcess(operation);

    std::cout << "TA '" << m_name << "': " << operation;

    onAfterProcess(operation);
}


void NonMI::Transaction::onBeforeProcess(const std::string &operation) {}


void NonMI::Transaction::onAfterProcess(const std::string &operation) {}

NonMI::Transaction::Transaction() = default;
