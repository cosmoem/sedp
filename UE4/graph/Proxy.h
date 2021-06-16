#pragma once

class Proxy : public Node {

public:
    Proxy(int identifier, Node *subgraph) : Node(identifier), subgraph(std::shared_ptr<Node>(subgraph)) {}

    void print(std::ostream &os, int indentationCounter) override {
        os << std::string(indentationCounter * 2, ' ') << identifier << " -> " << subgraph->getIdentifier() << '\n';
    }

    int weight() override {
        return subgraph->weight();
    }

    void getChildIdentifiers(std::vector<int> &childIdentifiers) override {
        childIdentifiers.push_back(this->identifier);
        subgraph->getChildIdentifiers(childIdentifiers);
    }

private:
    std::shared_ptr<Node> subgraph;
};