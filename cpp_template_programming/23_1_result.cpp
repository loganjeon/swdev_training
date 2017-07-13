
#include <iostream>
#include <typeinfo>

using namespace std;

int f(int a, double b) { return 0; }

// primary template
template<typename T>
struct result
{
	typedef T type;
};

template<typename R, typename ... Types>
struct result<R(Types...)>
{
	typedef R type;
};

template<typename T> 	// T : int(int, double)
void foo(T& a)
{
	typename result<T>::type n;	// int

	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	foo(f);
	//int n = 0;
	//foo(n);
}
