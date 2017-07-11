
#include <iostream>

#include <vector>
#include <array>

using namespace std;
	
//template<typename T> static char check( typeof(&T::resize) );
//template<typename T> static short check(...);
	
template<typename T>
struct has_resize
{
	typedef char one;
	typedef long two;

	//template<typename U> static char check( decltype(&U::resize) );
	//template<typename U> static short check(...);
	template<typename U> static char check( decltype(&U::resize) );
	template<typename U> static two check(...);
	
	//static constexpr bool value = ( sizeof(check<T>(0)) == sizeof(short) );	
public:
	enum { value = sizeof(check<T>(0)) == sizeof(char) };
};
	
	
template<typename T> 
void foo(T& c)
{
	std::cout << has_resize<T>::value << std::endl;
	if (has_resize<T>::value)
		std::cout << "T has resize" << std::endl;
	else
		std::cout << "T has not resize" << std::endl;
}

int main()
{
	vector<int> 	v = {1, 2, 3, 4, 5};
	array<int, 10>	ar = {1, 2, 3, 4, 5};

	foo(v);
	foo(ar);
}
