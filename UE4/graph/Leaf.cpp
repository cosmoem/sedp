#include "Leaf.h"

void Leaf::print(std::ostream &os, int indentationCounter) {
    os << std::string(indentationCounter * 2, ' ');
    os << identifier << " : " << weight_ << '\n';
}

int Leaf::weight() {
    return weight_;
}

void Leaf::getChildIdentifiers(std::vector<int> &childIdentifiers) {
    childIdentifiers.push_back(this->identifier);
}
