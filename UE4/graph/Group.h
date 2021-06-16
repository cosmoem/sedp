#pragma once

#include <vector>
#include <numeric>
#include <exception>
#include <iomanip>
#include "Node.h"

class Group : public Node {

public:
    explicit Group(int identifier) : Node(identifier), numberOfChildNodes(0) {}

    void print(std::ostream &os, int indentationCounter) override;

    int weight() override;

    void appendNode(std::unique_ptr<Node> node);

    void getChildIdentifiers(std::vector<int> &childIdentifiers) override;

private:
    int numberOfChildNodes;
    std::vector<std::unique_ptr<Node>> children;


    struct CyclicDependencyException : public std::exception {
        const char *what() const noexcept override {
            return "Cyclic Dependency is not allowed";
        }
    };
};