#pragma once

#include <iostream>
#include "Decorator.h"

namespace NonMI {
    class SecuredDecorator : public Decorator {

    public:
        explicit SecuredDecorator(Transaction* transaction) : Decorator(transaction) {}

        ~SecuredDecorator() override = default;

    protected:
        void onBeforeProcess(const std::string &operation) override {
            std::cout << "[secured] ";
            transaction->onBeforeProcess(operation);
        }

        void onAfterProcess(const std::string &operation) override {
            transaction->onAfterProcess(operation);
            std::cout << " [/secured]";
        }
    };
}
