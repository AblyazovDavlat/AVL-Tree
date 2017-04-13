#include "binary-search-trees.h"

BinarySearchTree::BinarySearchTree() {
    root = 0;
}

BinarySearchTree::~BinarySearchTree() {
    recursiveDel(root);
}

void BinarySearchTree::recursiveDel(Node *node) {
    if (!node)
        return;
    recursiveDel(node->left);
    recursiveDel(node->right);
    delete node;
}

Node* BinarySearchTree::searchMin(Node* const node) const {
    Node* currentNode;
    if (node == 0)
        currentNode = root;
    else
        currentNode = node;
    if (currentNode == 0)
        return 0;
    while (currentNode->left != 0)
        currentNode = currentNode->left;
    return currentNode;
}

Node* BinarySearchTree::searchMax(Node* const node) const {
    Node* currentNode;
    if (node == 0)
        currentNode = root;
    else
        currentNode = node;
    if (currentNode == 0)
        return 0;
    while (currentNode->right != 0)
        currentNode = currentNode->right;
    return currentNode;
}

Node* BinarySearchTree::searchPrev(Node* const node) const {
    if (node == 0)
        return 0;
    if (node->left != 0)
        return searchMax(node->left);

    Node* currentNode = node;
    while (currentNode->parent != 0 
        && currentNode == currentNode->parent->left)
        currentNode = currentNode->parent;
    return currentNode;
}

Node* BinarySearchTree::searchNext(Node* const node) const {
    if (node == 0)
        return 0;
    if (node->right != 0)
        return searchMin(node->right);

    Node* currentNode = node;
    while (currentNode->parent != 0 
        && currentNode == currentNode->parent->right)
        currentNode = currentNode->parent;
    return currentNode;
}

Node* BinarySearchTree::search(const float key) const {
    Node* currentNode = root;
    if (currentNode == 0)
        return 0;

    while (currentNode != 0 && currentNode->key != key)
        if (key < currentNode->key)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;

    return currentNode;
}

int BinarySearchTree::insert(Node *&node) {
    if (root == 0) {
        root = node;
        return 0;
    }

    Node* currentNode = root;
    Node* tmpPrev;
    while (currentNode != 0) {
        tmpPrev = currentNode;
        if (currentNode->key < node->key)
            currentNode = currentNode->right;
        else
            currentNode = currentNode->left;
    }

    node->parent = tmpPrev;
    if (tmpPrev->key <= node->key)
        tmpPrev->right = node;
    else
        tmpPrev->left = node;

    return 0;
}

int BinarySearchTree::insert(const float key) {
    Node* node = new Node;
    node->parent = 0;
    node->left = 0;
    node->right = 0;
    node->key = key;
    node->data = 0;

    return this->insert(node);
}

Node* BinarySearchTree::pull(const float key) {
    Node* x = 0;
    Node* y = 0;
    Node* z = search(key);

    //This is hardcode. Even I don't remember how to understand it.
    //But it works.

    if (z->left && z->right)
        y = searchNext(z);
    else
        y = z;
    if (y->left)
        x = y->left;
    else
        x = y->right;
    if (x)
        x->parent = y->parent;
    if (y->parent)
        if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    if (y != z)
        z->key = y->key;
    return y;
}

void BinarySearchTree::remove(float key) {
    delete pull(key);
}

int BinarySearchTree::isEmpty() const {
    if (root)
        return 0;
    else
        return 1;
}
