
#include <iostream>

#include "Transaction.h"
#include "SecuredTransaction.h"
#include "LoggedTransaction.h"
#include "LoggedSecuredTransaction.h"
#include "SecuredDecorator.h"
#include "LoggedDecorator.h"

void testMI()
{
    using namespace MI;
    // Basic transaction
    Transaction t1{ "t1" };
    t1.process("do something");
    std::cout << std::endl;

    // Transaction with logging
    LoggedTransaction t2{ "t2" };
    t2.process("do something with logging");
    std::cout << std::endl;

    // Secured transaction
    SecuredTransaction t3{ "t3" };
    t3.process("do something secured");
    std::cout << std::endl;

    // Secured transaction with logging
    LoggedSecuredTransaction t4{ "t4" };
    t4.LoggedTransaction::process("do something secured with logging");
    std::cout << std::endl;
}


void testNonMI()
{
    using namespace NonMI;
    // Basic transaction
    Transaction t1{ "t1" };
    t1.process("do something");
    std::cout << std::endl;

    // Transaction with logging
    LoggedDecorator t2{ std::make_unique<Transaction>("t2") };
    t2.process("do something with logging");
    std::cout << std::endl;

    // Secured transaction
    SecuredDecorator t3{ std::make_unique<Transaction>( "t3" )};
    t3.process("do something secured");
    std::cout << std::endl;

    // Secured transaction with logging
    LoggedDecorator t4{ std::make_unique<SecuredDecorator>(std::make_unique<Transaction>( "t4" ))};
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
