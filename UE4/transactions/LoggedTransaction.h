#pragma once

#include <iostream>
#include "Transaction.h"

namespace MI {
    class LoggedTransaction : public Transaction {
    public:
        explicit LoggedTransaction(const std::string &name);

        ~LoggedTransaction() override = default;

    protected:
        void onBeforeProcess(const std::string &operation) override;

        void onAfterProcess(const std::string &operation) override;
    };
}
