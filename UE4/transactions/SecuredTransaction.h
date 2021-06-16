#pragma once

#include <iostream>
#include "Transaction.h"

namespace MI {
    class SecuredTransaction : public Transaction {
    public:
        explicit SecuredTransaction(const std::string &name) : Transaction(name) {}

        ~SecuredTransaction() override = default;

    protected:
        void onBeforeProcess(const std::string &operation) override {
            std::cout << "[secured] ";
        }

        void onAfterProcess(const std::string &operation) override {
            std::cout << " [/secured]";
        }
    };
}
