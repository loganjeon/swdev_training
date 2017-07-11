
#include <iostream>
using namespace std;

void goo(int a, int b, int c)
{
	std::cout << a << ", " << b << ", " << c << std::endl;
}

int hoo(int a) { return -a; }

template<typename ... Types>
void foo(Types ... args)
{
	//int ar[] = { args... };
	//int ar[] = { ++args... };
	int ar[] = { hoo(args)... };

	//goo(args...);
	goo(hoo(args)...);

	for(int n : ar)
		std::cout << n << std::endl;
}

int main()
{
	foo(1, 2, 3);
}
