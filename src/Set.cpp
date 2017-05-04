#include "Set.h"

Set::Set() {
    tree = new AVLTree();
}

Set::~Set() {
    delete tree;
}

const int Set::empty() const {
    return tree->isEmpty();
}

const int Set::size() const {
    return tree->size();
}

const int Set::insert(const float key) {
    return tree->insert(key);
}

const int Set::erase(const float key) {
    return tree->remove(key);
}

const int Set::find(const float key) {
    if (tree->search(key) == 0)
        return 0;
    else
        return 1;
}
