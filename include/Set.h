#ifndef SET_H
#define SET_H

#include "AVL-trees.h"

class Set {
protected:
    AVLTree* tree;
public:
    Set();
    ~Set();
    
    const int empty() const;
    const int size() const;
    const int insert(const float key);
    const int erase(const float key);
    const int find(const float key);

};

#endif //SET_H
