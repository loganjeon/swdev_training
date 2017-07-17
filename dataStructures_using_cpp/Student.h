
#include <cstdio>
#include <cstdlib>
#include <cstring>

const static int MAX_STRING = 100;

class Student
{
	int id;
	char name[MAX_STRING];
	char dept[MAX_STRING];
public:
	Student(int i=0, char* n="", char* d="") {
		set( i, n, d);
	}

	void set(int i, char* n, char* d)
	{
		id = i;
		strcpy(name, n);
		strcpy(dept, d);
	}

	void display() {
		std::cout << id << " " << n << " " << d << std::endl;
	}
};
