
#include <iostream>
using namespace std;

template<typename ... Types>
void foo(Types ... args)
{

}

template<typename ... Types>
class mytuple
{

};

int main()
{

	mytuple<> t0;
	mytupe<int, char, long> t3;
	
	foo(1);
	foo(3.4);
	foo("aaa");

	foo();
	foo(1, 3.2, "aaa");
}
