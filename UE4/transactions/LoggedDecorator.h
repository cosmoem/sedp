#pragma once

#include <iostream>
#include "Decorator.h"

namespace NonMI {
    class LoggedDecorator : public Decorator {

    public:
        explicit LoggedDecorator(Transaction* transaction) : Decorator(transaction) {}

        ~LoggedDecorator() override = default;

    protected:
        void onBeforeProcess(const std::string &operation) override {
            std::cout << "[logged] ";
            transaction->onBeforeProcess(operation);
        }

        void onAfterProcess(const std::string &operation) override {
            transaction->onAfterProcess(operation);
            std::cout << " [/logged]";
        }
    };
}
