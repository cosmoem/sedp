#include "Proxy.h"

void Proxy::print(std::ostream &os, int indentationCounter) {
    os << std::string(indentationCounter * 2, ' ') << identifier << " -> " << subgraph->getIdentifier() << '\n';
}

int Proxy::weight() {
    return subgraph->weight();
}

void Proxy::getChildIdentifiers(std::vector<int> &childIdentifiers) {
    childIdentifiers.push_back(this->identifier);
    subgraph->getChildIdentifiers(childIdentifiers);
}
