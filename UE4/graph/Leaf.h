#pragma once

#include "Node.h"

class Leaf : public Node {
public:
    Leaf(int identifier, int weight) : Node(identifier), weight_(weight) {}

    void print(std::ostream &os, int indentationCounter) override;

    int weight() override;

    void getChildIdentifiers(std::vector<int> &childIdentifiers) override;

private:

    int weight_;
};