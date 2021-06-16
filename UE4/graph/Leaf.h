#pragma once

class Leaf : public Node {
public:
    Leaf(int identifier, int weight) : Node(identifier), weight_(weight) {}

    void print(std::ostream &os, int indentationCounter) override {
        os << std::string(indentationCounter * 2, ' ');
        os << identifier << " : " << weight_ << '\n';
    }

    int weight() override {
        return weight_;
    }

    void getChildIdentifiers(std::vector<int> &childIdentifiers) override {
        childIdentifiers.push_back(this->identifier);
    }

private:

    int weight_;
};