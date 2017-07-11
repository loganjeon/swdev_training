
#include <iostream>
#include <map>
#include <utility>
using namespace std;

template<typename ... Types>
void foo(Types ... args)
{
	//int x[] = { args... }; // args... {1, 2, 3}
	// int x[] = { 0, args... }; // args... {1, 2, 3}
	//initializer_list<int> x = { args... };

//	for (auto n : x)
//		std::cout << n << std::endl;

	tuple<Types...> t(args...);

//	for( int i = 0; i < sizeof...(args); i++)
	cout << get<0>(t) << endl;
	cout << get<1>(t) << endl;
	cout << get<2>(t) << endl;

}

int main()
{
	//foo(1, 2, 3);
	//foo();
	foo(1, 3.4, 'A');
}
