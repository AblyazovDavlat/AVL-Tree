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
    int balanceDetection(AVLNode *node, int &dep);
    int depth(AVLNode *node);
    int decisionOnBalancing(AVLNode *&node);
    int singleRightTurn(AVLNode *&node);
    int singleLeftTurn(AVLNode *&node);
    int doubleRightTurn(AVLNode *&node);
    int doubleLeftTurn(AVLNode *&node);

    void recursiveIns(AVLNode*& const localRoot, AVLNode*& node);
    Node* recursiveRem(AVLNode*& const localRoot, const float key);
};

#endif //AVL_TREES_H
