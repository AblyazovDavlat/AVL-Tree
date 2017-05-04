#include "AVL-Trees.h"

AVLNode::AVLNode(const Node& node) {
    this->parent = node.parent;
    this->left = node.left;
    this->right = node.right;
    this->key = node.key;
    this->data = node.data;
}

int AVLNode::getBalance() const {
    return balance;
}

int AVLNode::setBalance(const int balance) {
    this->balance = balance;
    return 0;
}

int AVLTree::insert(AVLNode*& const node) {
    node->parent = 0;
    node->left = 0;
    node->right = 0;
    node->setBalance(0);
    if (root == 0) {
        root = node;
        return 0;
    }
    int result = recursiveIns((AVLNode*&)root, node);
    return result;
}

int AVLTree::insert(const float key) {
    AVLNode* node = new AVLNode;
    node->key = key;
    node->data = 0;
    return insert(node);
}

int AVLTree::recursiveIns(AVLNode*& const localRoot, AVLNode *&node) {
    if (node->key < localRoot->key)
        if (localRoot->left == 0) {
            localRoot->left = node;
            node->parent = localRoot;
        }
        else
            recursiveIns((AVLNode*&)localRoot->left, node);
    else if (node->key > localRoot->key)
        if (localRoot->right == 0) {
            localRoot->right = node;
            node->parent = localRoot;
        }
        else
            recursiveIns((AVLNode*&)localRoot->right, node);
    else
        return -1;
    decisionOnBalancing(localRoot);
    return 0;
}

int AVLTree::remove(const float key) {
    Node* deletingNode = recursiveRem((AVLNode*&)root, key);
    if (deletingNode == 0)
        return -1;
    delete deletingNode;
    return 0;
}

void AVLTree::remove(Node* node) {
    delete recursiveRem((AVLNode*&)root, node->key);
}

Node* AVLTree::pull(const float key) {
    return recursiveRem((AVLNode*&)root, key);
}

Node* AVLTree::pull(Node* node) {
    return recursiveRem((AVLNode*&)root, node->key);
}

Node* AVLTree::recursiveRem(AVLNode*& const localRoot, const float key) {
    Node *result;
    if (localRoot == 0)
        return 0;
    if (key < localRoot->key)
        result = recursiveRem((AVLNode*&)localRoot->left, key);
    else if (key > localRoot->key)
        result = recursiveRem((AVLNode*&)localRoot->right, key);
    else {
        if (localRoot->left == 0 && localRoot->right == 0) {
            Node* killed = localRoot;
            if (localRoot->parent != 0)
                if (localRoot->parent->left == localRoot)
                    localRoot->parent->left = 0;
                else
                    localRoot->parent->right = 0;
            else
                root = 0;
            return killed;
        }
        else if (localRoot->left != 0 && localRoot->right == 0) {
            Node* son = localRoot->left;
            Node* killed = localRoot;
            son->parent = localRoot->parent;
            if (localRoot->parent != 0)
                if (localRoot->parent->left == localRoot)
                    localRoot->parent->left = son;
                else
                    localRoot->parent->right = son;
            else
                root = son;
            return killed;
        }
        else if (localRoot->left == 0 && localRoot->right != 0) {
            Node* son = localRoot->right;
            Node* killed = localRoot;
            son->parent = localRoot->parent;
            if (localRoot->parent != 0)
                if (localRoot->parent->left == localRoot)
                    localRoot->parent->left = son;
                else
                    localRoot->parent->right = son;
            else
                root = son;
            return killed;
        }
        else {
            Node *next = searchNext(localRoot);
            recursiveRem((AVLNode*&)localRoot->right, next->key);
            Node *killed = localRoot;
            next->left = localRoot->left;
            if (next->left != 0)
                next->left->parent = next;
            next->right = localRoot->right;
            if (next->right != 0)
                next->right->parent = next;
            next->parent = localRoot->parent;
            if (localRoot->parent != 0)
                if (localRoot->parent->left == localRoot)
                    localRoot->parent->left = next;
                else
                    localRoot->parent->right = next;
            else
                root = next;
            return killed;
        }
    }

    decisionOnBalancing(localRoot);
    return result;
}
