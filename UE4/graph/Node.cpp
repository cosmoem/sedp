#include "Node.h"

int Node::getIdentifier() const {
    return identifier;
}

void Node::print(std::ostream &os) {
    this->print(os, 0);
}
