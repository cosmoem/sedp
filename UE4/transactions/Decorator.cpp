#include "Decorator.h"

NonMI::Decorator::Decorator(NonMI::Transaction* transaction)
: Transaction(transaction->name()), transaction(transaction) {
}
