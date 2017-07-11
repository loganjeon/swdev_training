
#include <iostream>
using namespace std;

//int print(int a) { std::cout << a << std::endl;}
void print(int a) { std::cout << a << std::endl;}

template<typename ... Types>
void foo( Types ... args )
{
	//print(args...);	// error...
	//print(arts)...;	// error...
	//int dummy[] = { print(args)... };	// { print(1), print(2), print3) };
	//int dummy[] = { 0, print(args)... };	// { print(1), print(2), print3) };
											// { 0 }
	//int dummy[] = { 0, (print(args), 0)... };	// { 0, print(1), print(2), print3) };

	int dummy[] = {0, (cout << args << ", " , 0)... };
}

int main()
{
	foo(1, 2, 3);
	//foo();
}
