
#include <iostream>
#include <typeinfo>
#include <tuple>

using namespace std;

// primary template
template<typename ... Types>
struct xtuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types> 
struct xtuple<T, Types...> : public xtuple<Types...>
{
	T value;

	xtuple() = default;
	xtuple(const T& a, const Types& ... args) : value(a), xtuple<Types...>(args...) {}

	static constexpr int N = xtuple<Types...>::N + 1;
};

int main()
{
	//xtuple<               >				// primary template
	//xtuple<		  double>				// 3.4 보관
	//xtuple<	char, double>				// 'A' 보관
	xtuple<int, char, double> t3(3, 'A', 3.4);	// 3 보관

	std::cout << t3.value << std::endl;		// 3
	
	std::cout << static_cast<xtuple<char,double>&>(t3).value << std::endl;		// 'A'
	std::cout << static_cast<xtuple<double>&>(t3).value << std::endl;		// 'A'
	// N번째 요소를 구하려면 N번째 기본타입으로 캐스팅한다.
	
}

