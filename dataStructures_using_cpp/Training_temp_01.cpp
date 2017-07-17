
#include "BinaryTree.h"

class BinSrchTree : public BinaryTree
{
public:
	BinSrchTree(void) {}
	~BinSrchTree(void) {}

	BinaryNode* search(int key) {
		BinaryNode* node = searchRecur(root, key);

		if (node != NULL)
			std::cout << "Search success key :" << node->getData() << "node :"<< node << std::endl;
		else
			std::cout << "fail" << std::endl;

		return node;
	}
	BinaryNode* searchRecur(BinaryNode* n, int key)
	{
		if (n == NULL)
			return NULL;
		if (key == n->getData())
			return n;
		else if (key < n->getData())
			return searchRecur(n->getLeft(), key);
		else
			return searchRecur(n->getRight(), key);
	}

	void insert(BinaryNode* n) {
		if (n == NULL)
			return;
		if (isEmpty())
			root = n;
		else
			insertRecur(root, n);
	}
	void insertRecur(BinaryNode* r, BinaryNode* n)
	{
		if (n->getData() == r->getData())
			return ;
		else if (n->getData() < r->getData()) {
			if (r->getLeft() == NULL)
				r->setLeft(n);
			else
				insertRecur(r->getLeft(), n);
		} else {
			if (n->getRight() == NULL)
				r->setRight(n);
			else
				insertRecur(r->getRight(), n);
		}
	}

	void remove(int key) {
		if (isEmpty())
			return;

		BinaryNode* parent = NULL;
		BinaryNode* node = root;
		while (node != NULL && node->getData() != key) {
			parent = node;
			node = (key < node->getData()) ? node->getLeft() : node->getRight();
		}

		if (node ==NULL) {
			std::cout << "key is not in the tree!!" << std::endl;
			return;
		} else {
			remove(parent, node);
		}
	}
	
	void remove(BinaryNode* parent, BinaryNode* node)
	{
		if (node->isLeaf) {
			if (parent == NULL) {
				root = NULL;
			} else {
				if (parent->getLeft() == node)
					parent->setLeft(NULL);
				else
					parent->setright(NULL);
			}
		} 
		else if (node->getLeft() == NULL || node->getRight() == NULL) {
			BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();
			if (node == root)
				root = child;
			else {
				if (parent->getLeft() == node)
					parent->setLeft(child);
				else
					parent->setRight(child);
			}
		} 
		else {
			BinaryNode* succp = node; 
			BinaryNode* succ = node->getRight();
			while (succ->getLeft() != NULL) {
				succp = succ;
				succ = succ->getLeft();
			}

			if (succp->getLeft() == succ)
				succp->setLeft(succ->getRight());
			else
				succp->setRight(succ->getRight());

			node->setData(succ->getData());
			node = succ;
		}
		delete node;
	}

};



BinaryNode* searchIter(BinaryNode* n, int key)
{
	while (n != NULL)
	{
		if (key == n->getData())
			return n;
		else if (key < n->getData())
			n = n->getLeft();
		else
			n = n->getRight();
	}
	return NULL;
}


