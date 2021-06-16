#pragma once

#include <iostream>
#include <vector>

class Node {
public:
    explicit Node(int identifier) : identifier(identifier) {}

    virtual void print(std::ostream &os, int indentationCounter = 0) = 0;

    virtual int weight() = 0;

    int getIdentifier() {
        return identifier;
    }
    virtual void getChildIdentifiers(std::vector<int> &childIdentifiers) = 0;

protected:

    int identifier;

};