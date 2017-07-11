
#include <iostream>
#include <type_traits>
#include <typeinfo>
using namespace std;

int main()
{
	typedef conditional<true, int, double>::type TYPE1;
	typedef conditional<false, int, double>::type TYPE2;
	typedef conditional<sizeof(int) >= sizeof(double), int, double>::type TYPE3;

	std::cout << typeid(TYPE1).name() << std::endl;
	std::cout << typeid(TYPE2).name() << std::endl;
	std::cout << typeid(TYPE3).name() << std::endl;
}
