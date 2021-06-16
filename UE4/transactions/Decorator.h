#pragma once

#include "Transaction.h"

namespace NonMI {
    class Decorator : public Transaction {
    public:
        explicit Decorator(NonMI::Transaction* transaction);

    protected:
        Transaction* transaction;

    };
}
