
#include <cstdio>
#include <cstdlib>
#include <iostream>

const static int MAX_QUEUE_SIZE 100;

inline void error(char* str) { std::cout << "error" << std::endl;}

class CircularQueue
{
protected:
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
public:
	CircularQueue() { front = rear = 0; }
	~CircularQueue() {}
	bool isEmpty() { front = rear = 0; }
	bool isFull() { return (rear+1) % MAX_QUEUE_SIZE == front; }
	void enqueue(int val) {
		if(isFull())
			error();
		else {
			rear = (rear+1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	int dequeue() {
		if(isEmpty())
			error();
		else{
			front = (front+1) % MAX_QUEUE_SIZE;
			return data[front];
		}

	}
	int peek() {
		if(isEmpty())
			error();
		else {
			return data[(front+1) % MAX_QUEUE_SIZE];
		}
	}
	int display() {
		std::cout << "" << std::endl;
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front+1; i <= maxi; i++)
			std::cout << data[i%MAX_QUEUE_SIZE] << std::endl;
	}
}
