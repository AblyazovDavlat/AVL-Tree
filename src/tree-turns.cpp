#include "AVL-Trees.h"

int AVLTree::depth(AVLNode* node)
{
	if (!node)
		return -1;
	int l = depth((AVLNode*)node->left);
	int r = depth((AVLNode*)node->right);
	node->setBalance(l - r);
	return r > l ? r+1 : l+1;
}

int AVLTree::balanceDetection(AVLNode *node, int &dep)
{
	dep = depth(node);
	return node->getBalance();
}

int AVLTree::decisionOnBalancing(AVLNode *&node)
{
	if (!node)
		return -1;
	int dep;
	char balance = balanceDetection(node, dep);
	if (balance == 2)
		if (((AVLNode*)node->left)->getBalance() > 0)
			singleRightTurn(node);
		else
			doubleRightTurn(node);
	if (balance == -2)
		if (((AVLNode*)node->right)->getBalance() < 0)
			singleLeftTurn(node);
		else
			doubleLeftTurn(node);
	return dep;
}

int AVLTree::singleRightTurn(AVLNode *&node)
{
	AVLNode *A  = node;
	AVLNode *B  = (AVLNode*)A->left;
	AVLNode *t1 = (AVLNode*)B->left;
	AVLNode *t2 = (AVLNode*)B->right;
	AVLNode *t3 = (AVLNode*)A->right;

	A->left  = t2;
	B->right = A;
	B->parent = A->parent;
	A->parent = B;
	if(t2) t2->parent = A;

	int depA, depB;
	balanceDetection(A, depA);
	balanceDetection(B, depB);

	node = B;
	return depB;
}

int AVLTree::singleLeftTurn(AVLNode *&node)
{
	AVLNode *A  = node;
	AVLNode *B  = (AVLNode*)A->right;
	AVLNode *t1 = (AVLNode*)A->left;
	AVLNode *t2 = (AVLNode*)B->left;
	AVLNode *t3 = (AVLNode*)B->right;

	A->right = t2;
	B->left = A;
	B->parent = A->parent;
	A->parent = B;
	if(t2) t2->parent = A;

	int depA, depB;
	balanceDetection(A, depA);
	balanceDetection(B, depB);

	node = B;
	return depB;
}

int AVLTree::doubleRightTurn(AVLNode *&node)
{
	AVLNode *A  = node;
	AVLNode *B  = (AVLNode*)A->left;
	AVLNode *C  = (AVLNode*)B->right;
	AVLNode *t1 = (AVLNode*)B->left;
	AVLNode *t2 = (AVLNode*)C->left;
	AVLNode *t3 = (AVLNode*)C->right;
	AVLNode *t4 = (AVLNode*)A->right;

	C->right = A;
	C->left  = B;
	C->parent = A->parent;
	A->parent = C;
	B->parent = C;
	B->right = t2;
	A->left = t3;
	if(t2) t2->parent = B;
	if(t3) t3->parent = A;

	int depA, depB, depC;
	balanceDetection(A, depA);
	balanceDetection(B, depB);
	balanceDetection(C, depC);

	node = C;
	return depC;
}

int AVLTree::doubleLeftTurn(AVLNode *&node)
{
	AVLNode *A  = node;
	AVLNode *B  = (AVLNode*)A->right;
	AVLNode *C  = (AVLNode*)B->left;
	AVLNode *t1 = (AVLNode*)A->left;
	AVLNode *t2 = (AVLNode*)C->left;
	AVLNode *t3 = (AVLNode*)C->right;
	AVLNode *t4 = (AVLNode*)B->right;

	C->left = A;
	C->right  = B;
	C->parent = A->parent;
	A->parent = C;
	B->parent = C;
	B->left = t3;
	A->right = t2;
	if(t2) t2->parent = A;
	if(t3) t3->parent = B;

	int depA, depB, depC;
	balanceDetection(A, depA);
	balanceDetection(B, depB);
	balanceDetection(C, depC);

	node = C;
	return depC;
}