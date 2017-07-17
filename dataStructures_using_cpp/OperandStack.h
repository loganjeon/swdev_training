
#include <cstdio>
#include <cstdlib>

#include <iostream>

const static int MAX_STACK_SIZE = 10;

inline void error(char* str) { std::cout << str << std::endl;}

class OperandStack 
{
	double data[MAX_STACK_SIZE];
	int top;
public:
	OperandStack() { top = -1; }
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE-1; }

	void push(double e) {
		if (isFull())
			error("stack overflow");
		data[++top] = e;
	}
	double pop() {
		if (isEmpty()) 
			error("stack empty error");
		return data[top--];
	}

};


