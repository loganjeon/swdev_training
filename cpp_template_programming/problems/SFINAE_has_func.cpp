
#include <iostream>
#include <vector>
#include <array>
#include <typeinfo>
#include <type_traits>

using namespace std;

template<typename T>
struct Hello
{
	T helloworld() { return 0; }
};

template<typename T>
struct Generic {};

#if 0
template<typename T>
class has_helloworld
{
	typedef char one;
	typedef long two;

	//template<typename U> static one test( decltype(&U::helloworld) );
	template<typename U> static one test( decltype(&U::helloworld));
	template<typename U> static two test(...);

public:
	enum { value = sizeof(test<T>(0)) == sizeof(char) };
};

int main()
{
	std::cout << has_helloworld<Hello>::value << std::endl;
	std::cout << has_helloworld<Generic>::value << std::endl;

	return 0;
}
#else

template<typename T>
class has_helloworld
{
	typedef char one;
	typedef long two;

	template<typename U> static one test( decltype(&U::helloworld) );
	//template<typename U> static one test( decltype(std::declval<U>().resize()) );
	template<typename U> static two test(...);

public:
	enum { value = sizeof(test<T>(0)) == sizeof(char) };
};

int main()
{
	vector<int>		v = {1, 2, 3, 4, 5};
	array<int, 10>	ar = {1, 2, 3, 4, 5};

	std::cout << has_helloworld<Hello<int>>::value << std::endl;
	std::cout << has_helloworld<Generic<int>>::value << std::endl;
	//std::cout << has_helloworld<decltype(v)>::value << std::endl;
	//std::cout << has_helloworld<decltype(ar)>::value << std::endl;
	std::cout << typeid(Hello<int>).name() << std::endl;
	std::cout << typeid(Generic<int>).name() << std::endl;
	//std::cout << typeid(v).name() << std::endl;
	//std::cout << typeid(ar).name() << std::endl;

	return 0;
}
#endif
