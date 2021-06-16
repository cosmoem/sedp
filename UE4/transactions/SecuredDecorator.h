#pragma once

#include <iostream>
#include "Decorator.h"

namespace NonMI {
    class SecuredDecorator : public Decorator {

    public:
        explicit SecuredDecorator(std::unique_ptr<Transaction> transaction);

        ~SecuredDecorator() override = default;

    protected:
        void onBeforeProcess(const std::string &operation) override;

        void onAfterProcess(const std::string &operation) override;
    };
}
