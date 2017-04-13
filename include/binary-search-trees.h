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

    Node* searchMin(Node *node = 0) const;
    Node* searchMax(Node *node = 0) const;
    Node* searchPrev(Node *node);
    Node* searchNext(Node *node);
    Node* search(float key);

    virtual void insert(Node *&node);
    virtual void remove(float key);
    virtual Node* pull(float key);

    int isEmpty() const;

protected:
    void recursiveDel(Node *node);
};

#endif //BINARY_SEARCH_TREES_H
