#include "Decorator.h"

NonMI::Decorator::Decorator(std::unique_ptr<NonMI::Transaction> transaction)
: Transaction(transaction->name()), transaction(std::move(transaction)) {
}
