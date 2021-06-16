
#include <iostream>

#include "Transaction.h"
#include "SecuredTransaction.h"
#include "LoggedTransaction.h"
#include "LoggedSecuredTransaction.h"
#include "SecuredDecorator.h"
#include "LoggedDecorator.h"

void testMI()
{
    // TODO: adapt declarations (t1..t4) to use your solution for a)
    using namespace MI;
    // Basic transaction

    Transaction t1{ "t1" };
    t1.process("do something");
    std::cout << std::endl;

    // Transaction with logging
    MI::LoggedTransaction t2{ "t2" };
    t2.process("do something with logging");
    std::cout << std::endl;

    // Secured transaction
    MI::SecuredTransaction t3{ "t3" };
    t3.process("do something secured");
    std::cout << std::endl;

    // Secured transaction with logging
    MI::LoggedSecuredTransaction t4{ "t4" };
    t4.LoggedTransaction::process("do something secured with logging");
    std::cout << std::endl;
}


void testNonMI()
{

    // TODO: adapt declarations (t1..t4) to use your solution for b)
    using namespace NonMI;
    // Basic transaction
    Transaction t1{ "t1" };
    t1.process("do something");
    std::cout << std::endl;

    // Transaction with logging
    NonMI::LoggedDecorator t2{ new Transaction {"t2"} };
    t2.process("do something with logging");
    std::cout << std::endl;

    // Secured transaction
    NonMI::SecuredDecorator t3{ new Transaction { "t3" }};
    t3.process("do something secured");
    std::cout << std::endl;

    // Secured transaction with logging
    NonMI::LoggedDecorator t4{ new NonMI::SecuredDecorator { new Transaction { "t4" }}};
    t4.process("do something secured with logging");
    std::cout << std::endl;
}


int main(int argc, char * argv[])
{
    std::cout << "Testing MI implementation..." << std::endl;
    testMI();
    std::cout << std::endl;

    std::cout << "Testing non-MI implementation..." << std::endl;
    testNonMI();
    std::cout << std::endl;
}
