#pragma once

#include <iostream>
#include "Transaction.h"

namespace MI {
    class LoggedTransaction : public Transaction {
    public:
        explicit LoggedTransaction(const std::string &name) : Transaction(name) {}

    protected:
        void onBeforeProcess(const std::string &operation) override {
            std::cout << "[logged] ";
        }

        void onAfterProcess(const std::string &operation) override {
            std::cout << " [/logged]";
        }
    };
}


namespace NonMI {
    class LoggedTransaction : public Transaction {

    };
}