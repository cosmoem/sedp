#pragma once

#include "Transaction.h"

namespace NonMI {
    class Decorator : public Transaction {
    public:
        explicit Decorator(std::unique_ptr<NonMI::Transaction> transaction);

        ~Decorator() override = default;

    protected:
        std::unique_ptr<Transaction> transaction;
    };
}
