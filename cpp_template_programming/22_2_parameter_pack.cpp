
#include <iostream>
using namespace std;

void goo( int n, double d, const char* s)
{
	std::cout << n << ", " << d << ", " << s << std::endl;
}
	
template<typename ... Types>
void foo(Types ... args)
{
	std::cout << sizeof...(args) << std::endl;
	std::cout << sizeof...(Types) << std::endl;

	goo( args... );

}

int main()
{
	foo(1, 3.4, "abc");
}
