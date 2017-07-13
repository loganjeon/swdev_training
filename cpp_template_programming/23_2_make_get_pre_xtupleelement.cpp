
#include <iostream>
#include <typeinfo>
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

// primary template
template<int N, typename T>
struct xtuple_element_type
{
	typedef T type;
	typedef T tupleType;
};

// N == 0
//template<int N, typename T, typename ... Types>
template<typename T, typename ... Types>
struct xtuple_element_type<0, xtuple<T, Types...>>
{
	typedef T type;			// 0번째 요소타입
	typedef xtuple<T, Types...> tupleType;	// 0번째 요소를 보관하는 타입.
};

// N != 0
template<int N, typename T, typename ... Types>
struct xtuple_element_type<N, xtuple<T, Types...>>
{
	typedef typename xtuple_element_type<N-1, xtuple<Types...>>::type type;			
	typedef typename xtuple_element_type<N-1, xtuple<Types...>>::tupleType tupleType;
};

int main()
{
	typedef xtuple<int, char, double> mytuple;

//	xtuple_element_type<0, mytuple>::type		n;	
//	xtuple_element_type<0, mytuple>::tupleType	tp;	
//	xtuple_element_type<0, mytuple>::type		n;	
//	xtuple_element_type<0, mytuple>::tupleType	tp;	
	xtuple_element_type<2, mytuple>::type		n;	
	xtuple_element_type<2, mytuple>::tupleType	tp;	

	std::cout << typeid(n).name() << std::endl;
	std::cout << typeid(tp).name() << std::endl;
}
