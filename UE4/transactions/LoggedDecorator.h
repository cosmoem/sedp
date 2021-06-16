#pragma once

#include <iostream>
#include "Decorator.h"

namespace NonMI {
    class LoggedDecorator : public Decorator {

    public:
        explicit LoggedDecorator(std::unique_ptr<Transaction> transaction);

        ~LoggedDecorator() override = default;

    protected:
        void onBeforeProcess(const std::string &operation) override;

        void onAfterProcess(const std::string &operation) override;
    };
}
