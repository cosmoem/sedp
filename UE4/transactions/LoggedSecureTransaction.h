#pragma once

#include "Transaction.h"
#include "LoggedTransaction.h"
#include "SecuredTransaction.h"

namespace MI {
    class LoggedSecureTransaction : public LoggedTransaction, public SecuredTransaction {
    public:
        explicit LoggedSecureTransaction(const std::string &name) : LoggedTransaction(name), SecuredTransaction(name) {}

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

