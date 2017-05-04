#ifndef AVL_TREES_H
#define AVL_TREES_H

#include "binary-search-trees.h"

class AVLNode : public Node {
protected:
    int balance;
public:
    AVLNode() {};
    AVLNode(const Node& node);
    int getBalance() const;
    int setBalance(const int balance);
};

class AVLTree : public BinarySearchTree {
public:
    AVLTree() : BinarySearchTree() {};
    virtual ~AVLTree() {};

    virtual int insert(AVLNode*& const node);
    virtual int insert(const float key);
    virtual int remove(const float key);
    virtual void remove(Node* node);
    virtual Node* pull(const float key);
    virtual Node* pull(Node* node);

private:
    const int depth(AVLNode* const node);
    const int balanceDetection(AVLNode* const node, int &dep);
    const int decisionOnBalancing(AVLNode*& node);
    const int singleRightTurn(AVLNode*& node);
    const int singleLeftTurn(AVLNode*& node);
    const int doubleRightTurn(AVLNode*& node);
    const int doubleLeftTurn(AVLNode*& node);

    int recursiveIns(AVLNode*& const localRoot, AVLNode*& node);
    Node* recursiveRem(AVLNode*& const localRoot, const float key);
};

#endif //AVL_TREES_H
