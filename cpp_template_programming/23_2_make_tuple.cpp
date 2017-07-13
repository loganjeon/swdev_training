
#include <iostream>
#include <tuple>

using namespace std;

// primary template
template<typename ... Types>
struct xtuple
{
	static constexpr int N = 0;
};

//template<typename T, typename ... Types> 
//struct xtuple<T, Types...> 
template<typename T, typename ... Types> 
struct xtuple<T, Types...> : public xtuple<Types...>
{
	T value;

	xtuple() = default;
	//xtuple(const T& a) : value(a) {}
	xtuple(const T& a, const Types& ... args) : value(a), xtuple<Types...>(args...) {}

	//static constexpr int N = 0;
	static constexpr int N = xtuple<Types...>::N + 1;
};

int main()
{
	xtuple<>					t0;
//	xtuple<int>					t1;
//	xtuple<int, char>			t2;
//	xtuple<int, char, double>	t3;
	
	//xtuple<int, char, double>	t3(0);
	
	xtuple<int, char, double> t3(3, 'A', 3.4);
}
