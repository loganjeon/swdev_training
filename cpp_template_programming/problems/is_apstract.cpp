
#include <iostream>

using namespace std;

#if 0
//void foo(void* p) { 
void foo() { 
	std::cout << "void" << std::endl;
}

void foo(...) {
	std::cout << "..." << std::endl;
}

struct Shape{
	virtual void Draw() = 0;
};

//void check(Shape(*p)[1])
template<typename T>
void check( T(*p)[1] )
{
	std::cout << "*" << std::endl;
}

template<typename T>
void check(...)
{
	std::cout << "..." << std::endl;
}

int main()
{
	//foo(0);
	//Shape s;
	//Shape* p1;
	//Shape (*p2)[];
	check<Shape>(0);
}

//short foo(int a) { std::cout << "int" << std::endl; return 0; }
//char foo(double a) { std::cout << "double" << std::endl; return 0; }
short foo(int a);
char foo(double a);
int foo();

int main()
{
	std::cout << sizeof( foo(1) ) << std::endl;
	std::cout << sizeof( foo(3.4) ) << std::endl;
	std::cout << sizeof( foo() ) << std::endl;
}


#else
struct Shape
{
	virtual void Draw() = 0;
	//void Draw() {};
};

//template<typename T> static char check(T(*p)[1]);
//template<typename T> static short check(...);

template<typename T>
struct xis_abstract
{
	//static char check( T(*p)[1] );
	//static short check(...);
	//enum { value = (sizeof(check<T>(0) == sizeof(short))) };
	
	template<typename U> static char check(U(*p)[1]);
	template<typename U> static short check(...);
	static constexpr bool value = ( sizeof(check<T>(0)) == sizeof(short) );	
};

int main()
{
	std::cout << xis_abstract<Shape>::value << std::endl;
}

#endif
