
#include <cstdio>
#include <cstdlib>

const int MAX_STACK_SIZE = 20;

class ArrayStack
{
	int top;
	int data[MAX_STACK_SIZE];
public:
	ArrayStack() { top = -1; }
	~ArrayStack() {}

	bool isEmpty { return top == -1; }
	bool isFull { return top == MAX_STACK_SIZE; }

	void push( int e ) {
		if( isFull() ) 
			error("stack overflow");
		data[++top] = e;
	}

	int pop() {
		if( isEmpty() )
			error("stack empty error");
		return data[top--];
	}

	int peek() {
		if( isEmpty() )
			error("stack empty error");
		return data[top];
	}

	void display()
	{
		for(int i=0; i<=top; i++)
			cout << data[i] << "  ";
		cout << endl;
	}

}





void main()
{
	ArratyStack stack;
	for (int i=1; i<10; i++)
		stack.push( i );
	stack.display();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.display();
}

