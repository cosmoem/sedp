#pragma once

#include "Node.h"

class Proxy : public Node {

public:
    Proxy(int identifier, Node *subgraph) : Node(identifier), subgraph(std::shared_ptr<Node>(subgraph)) {}

    void print(std::ostream &os, int indentationCounter) override;

    int weight() override;

    void getChildIdentifiers(std::vector<int> &childIdentifiers) override;

private:
    std::shared_ptr<Node> subgraph;
};