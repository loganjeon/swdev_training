
#include "LinkedStack.h"

int main()
{
	LinkedStack stack;
	stack.push ( new Node("", "", "") );
	stack.push ( new Node("", "", "") );
	stack.push ( new Node("", "", "") );

	stack.display();

	Node* node = stack.pop();
	node->display();
	delete node;

	stack.display();
}
