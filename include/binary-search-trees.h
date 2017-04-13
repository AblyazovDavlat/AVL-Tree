#pragma once

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
	void recursiveDel(Node *node);
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();

	Node* searchMin(Node *node = 0);
	Node* searchMax(Node *node = 0);
	Node* searchPrev(Node *node);
	Node* searchNext(Node *node);
	Node* search(float key);

	virtual void insert(Node *&node);
	virtual void remove(float key);
	virtual Node* pull(float key);

	int isEmpty() const;
};