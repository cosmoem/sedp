#include "Group.h"

void Group::print(std::ostream &os, int indentationCounter) {
    os << std::string(indentationCounter * 2, ' ') << identifier << "\n";
    indentationCounter++;
    for (auto &child : children) {
        child->print(os, indentationCounter);
    }
}

int Group::weight() {
    return std::accumulate(children.begin(), children.end(), 0, [](int acc, std::unique_ptr<Node> &child) {
        return acc + child->weight();
    });
}

void Group::appendNode(std::unique_ptr<Node> node) {
    // check if append would cause graph to be cyclic
    std::vector<int> nodeChildIdentifiers{};
    node->getChildIdentifiers(nodeChildIdentifiers);
    std::sort(nodeChildIdentifiers.begin(), nodeChildIdentifiers.end());

    if (std::find(nodeChildIdentifiers.begin(), nodeChildIdentifiers.end(), this->identifier) !=
        nodeChildIdentifiers.end()) {
        // If cycle is found
        throw CyclicDependencyException();
    }

    numberOfChildNodes++;
    children.push_back(std::move(node));
}

void Group::getChildIdentifiers(std::vector<int> &childIdentifiers) {
    childIdentifiers.push_back(this->identifier);

    for (auto &child : children) {
        child->getChildIdentifiers(childIdentifiers);
    }
}
