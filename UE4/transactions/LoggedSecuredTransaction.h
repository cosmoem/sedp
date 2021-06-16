#pragma once

#include "Transaction.h"
#include "LoggedTransaction.h"
#include "SecuredTransaction.h"

namespace MI {
    class LoggedSecuredTransaction : public LoggedTransaction, public SecuredTransaction {
    public:
        explicit LoggedSecuredTransaction(const std::string &name) : LoggedTransaction(name), SecuredTransaction(name) {}

        ~LoggedSecuredTransaction() override = default;

    protected:
        void onBeforeProcess(const std::string &operation) override {
            LoggedTransaction::onBeforeProcess(operation);
            SecuredTransaction::onBeforeProcess(operation);
        }

        void onAfterProcess(const std::string &operation) override {
            SecuredTransaction::onAfterProcess(operation);
            LoggedTransaction::onAfterProcess(operation);
        }
    };
}

