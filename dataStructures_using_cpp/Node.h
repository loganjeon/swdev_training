
#include "Student.h"

class Node : public Student
{
	Node* link;
public:
	Node( int id=0, char* n="", char* d="") : Student(id, n, d) {
		link = NULL;
	}
	~Node(void) {}
	
	Node* getLink() {
		return link;
	}

	void setLink(Node *p) {
		link = p;
	}

	void display() {
		std::cout << data << std::endl;
	}
};
