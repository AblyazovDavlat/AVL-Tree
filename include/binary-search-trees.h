#ifndef BINARY_SEARCH_TREES_H
#define BINARY_SEARCH_TREES_H

class Node {
public:
    float key;
    Node* left;
    Node* right;
    Node* parent;
    void* data;
};

class BinarySearchTree {
protected:
    Node* root;

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();

    Node* searchMin(Node* const node = 0) const;
    Node* searchMax(Node* const node = 0) const;
    Node* searchPrev(Node* const node) const;
    Node* searchNext(Node* const node) const;
    Node* search(const float key) const;

    virtual void insert(Node *&node);
    virtual void remove(float key);
    virtual Node* pull(float key);

    int isEmpty() const;

protected:
    void recursiveDel(Node *node);
};

#endif //BINARY_SEARCH_TREES_H
