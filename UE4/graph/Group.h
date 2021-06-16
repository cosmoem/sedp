#pragma once

#include <vector>
#include <numeric>
#include <exception>
#include <iomanip>
#include "Node.h"

class Group : public Node {

public:
    explicit Group(int identifier) : Node(identifier), numberOfChildNodes(0) {}

    void print(std::ostream &os, int indentationCounter) override {
        os << std::string(indentationCounter * 2, ' ') << identifier << "\n";
        indentationCounter++;
        for (auto &child : children) {
            child->print(os, indentationCounter);
        }
    }

    int weight() override {
        return std::accumulate(children.begin(), children.end(), 0, [](int acc, std::unique_ptr<Node> &child) {
            return acc + child->weight();
        });
    }

    void appendNode(std::unique_ptr<Node> node) {
        // check if append would cause graph to be cyclic
        std::vector<int> nodeChildIdentifiers{};
        node->getChildIdentifiers(nodeChildIdentifiers);
        std::sort(nodeChildIdentifiers.begin(), nodeChildIdentifiers.end());

        if (std::find(nodeChildIdentifiers.begin(), nodeChildIdentifiers.end(), this->identifier) != nodeChildIdentifiers.end()) {
            // If cycle is found
            throw CyclicDependencyException();
        }

        numberOfChildNodes++;
        children.push_back(std::move(node));
    }

    void getChildIdentifiers(std::vector<int> &childIdentifiers) override {
        childIdentifiers.push_back(this->identifier);

        for (auto &child : children) {
            child->getChildIdentifiers(childIdentifiers);
        }
    }

private:
    int numberOfChildNodes;
    std::vector<std::unique_ptr<Node>> children;


    struct CyclicDependencyException : public std::exception {
        const char *what() const noexcept override {
            return "Cyclic Dependency is not allowed";
        }
    };
};