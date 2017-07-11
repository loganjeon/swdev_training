
#include <iostream>
using namespace std;

template<typename T>
typename enable_if<is_integral<T>::value>::type foo(T a)
{
	std::cout << "by template func : " << a << std::endl;
};

void foo(...)
{
	std::cout << "by varidic func : " << std::endl;
}

int main()
{
	foo(3.4);
	foo(3);
}
