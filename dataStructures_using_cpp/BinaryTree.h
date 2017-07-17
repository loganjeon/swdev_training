
#include "BinaryNode.h"

class BinaryTree
{
	BinaryNode*	root;
public:
	BinaryTree() : root(NULL) { }
	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot()	{ return root; }
	bool isEmpty() { return root == NULL; }

	void inorder() { 
		std::cout << std::endl << "inorder : ";
		inorder(root);
	}
	void inorder(BinaryNode* node) {
		if ( node != NULL ) {
			if ( node->getLeft() != NULL )
				inorder(node->getLeft());
			std::cout << node->getData();

			if ( node->getRight() != NULL)
				inorder(node->getRight());
		}
	}
	
	void preorder() {
		std::cout << std::endl << "preorder : ";
		preorder(root);
	}
	void preorder(BinaryNode* node) {
		if ( node != NULL ) {
			std::cout << node->getData() ;
			if (node->getLeft != NULL)
				preorder(node->getLeft());
			if (node->getRight != NULL)
				preorder(node->getRight());
		}
	}

	void postorder() {
		std::cout << std::endl << "postorder : ";
		postorder(root);
	}
	void postorder(BinaryNode* node) {
		if ( node != NULL ) {
			if (node->getLeft() != NULL)
				postorder(node->getLeft());
			if (node->getRight() != NULL)
				postorder(node->getRight());
			std::cout << node->getData() ;
		}
	}

	void levelorder() {
		std::cout << std::endl << "levelorder :";
		if (!isEmpty()) {
			CircularQueue q;
			q.enqueue( root );
			while (!q.isEmpty()) {
				BinaryNode* n = q.dequeue();
				if (n!=NULL) {
					std::cout << n->getData();
				   	q.enqueue(n->getLeft());
					q.enqueue(n->getRight());	
				}
			}
		}
		std::cout << std::endl;
	}

	int getCount() {
		return isEmpty() ? 0 : getCount(root);
	}
	int getCount(BinaryNode* node) {
		if (node == NULL) 
			return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}

	int getLeafCount() {
		return isEmptry() ? 0 : getLeafCount(root);
	}
	int getLeafCount(BinaryNode* node) {
		if (node == NULL) 
			return 0;
		if (node->isLeaf())
			return 1;
		else
			return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	int getHeight() {
		return isEmpty() ? 0 : getHeight(root)
	}
	int getHeight(BinaryNode* node)
	{
		if (node == NULL)
			return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return (hLeft > h Right) ? hLeft + 1 : hRight + 1;
	}

	int evaluate() { return evaluate(root); }
	int evaluate(BinaryNode* node) 
	{
		if (node == NULL)
			return 0;
		
		if (node->isLeaf() )
			return node->getData();
		else {
			int op1 = evaluate(node->getLeft());
			int op2 = evaluate(node->getRight());

			swhitch (node->getData()) {
				case '+' : return op1 + op2;
				case '-' : return op1 - op2;
				case '*' : return op1 * op2;
				case '/' : return op1 / op2;
			}
			return 0;
		}
	}

	int calcSize() {
		return calcSize(root);
	}
	int calcSize( BinaryNode* node ) {
		if (node == NULL)
			return 0;
		return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
	}
};
