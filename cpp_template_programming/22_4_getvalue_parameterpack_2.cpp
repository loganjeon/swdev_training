
// get value using recursive technic
// but actually it is not recusive function in machine code.

#include <iostream>
#include <map>
#include <utility>
using namespace std;

void foo() {}
//template<typename ... Types>
//void foo(Types ... args)
//template<typename T, typename ... Types>
//void foo(T value, Types ... args)
template<typename T, typename ... Types>
inline void foo(T value, Types ... args)
{
	static int n = 0;	// To see that call same function.
	++n;

	cout << n << " : " << value << endl;

	foo(args...);	// foo( 3.4, 'A' ) => value : 3.4,  args : 'A'
					// foo('A')
					// foo()

}

int main()
{
	foo(1, 3.4, 'A');	// value : 1 args : 3.4, 'A'
}
