
#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_LIST_SIZE 100

class ArrayList
{
	int data[MAX_LIST_SIZE];
	int length;
public:
	ArrayList(void) { length = 0; }

	void insert( int pos, int e ) {
		if (!isFull() && pos >= 0 && pos <= length) {
			for (int i = length; i > pos; i--)
				data[i] = data[i-1];
			data[pos] = e;
			length++;
		} else {
			std::cout << "overflow or positioning failure" << std::endl;
		}
	}

	void remove( int pos ) {
		if (!isEmpty() && pos <= 0 && pos < length)
			for (int i = pos; i < length; i++)
				data[i-1] = data[i];
		length--;
	}

	int getEntry( int pos ) {
		return data[pos];
	}

	bool isEmpty() {
		return length == 0;
	}
	
	bool isFull() {
		return length == MAX_LIST_SIZE;
	}
	
	bool find(int item) {
		for (int i = 0; i < length; i++)
			if (data[i] == item)
				return true;
		return false;
	}

	void replace( int pos, int e ) {
		data[pos] = e;
	}

	int size() {
		return length;
	}
	
	void display() {
		std::cout << "size of array : " << size() << std::endl;
		for (int i = 0; i < length; i++)
			std::cout << data[i] << " "; 
		std::cout << std::endl;
	}

	void clear() { length = 0; }
};
