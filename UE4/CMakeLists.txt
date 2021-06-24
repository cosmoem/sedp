cmake_minimum_required(VERSION 3.6)
project(sedp_exercise3)

set(CMAKE_CXX_STANDARD 20)

# Task 4.1.1
add_executable(dice_mud
        dice/mud-main.cpp
        dice/dice.cpp
        dice/dice.h
        dice/game.cpp
        dice/game.h
        dice/player.cpp
        dice/player.h
        )

# Task 4.1.2
add_executable(dice_seven
        dice/seven-main.cpp
        dice/dice.cpp
        dice/dice.h
        dice/game.cpp
        dice/game.h
        dice/player.cpp
        dice/player.h
        )

# Task 4.2
add_executable(beziercurve
        beziercurve/CubicBezierCurve.h
        beziercurve/CubicBezierCurver.cpp
        beziercurve/test.cpp
        beziercurve/Point.cpp
        beziercurve/Point.h
        )

# Task 4.3
add_executable(graph
        graph/Graph.h
        graph/main.cpp
        )

# Task 4.4
add_executable(transactions
        transactions/main.cpp
        transactions/Transaction.cpp
        transactions/Transaction.h
        transactions/LoggedTransaction.cpp
        transactions/LoggedTransaction.h
        transactions/SecuredTransaction.cpp
        transactions/SecuredTransaction.h
        transactions/LoggedSecuredTransaction.cpp transactions/LoggedSecuredTransaction.h transactions/Decorator.cpp transactions/Decorator.h transactions/SecuredDecorator.cpp transactions/SecuredDecorator.h transactions/LoggedDecorator.cpp transactions/LoggedDecorator.h)