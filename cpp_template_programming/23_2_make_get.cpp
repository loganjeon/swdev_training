
#include <iostream>
#include <typeinfo>
#include <tuple>

using namespace std;


/*-----------------------------------------------------------------------------
 *  xtuple
 *-----------------------------------------------------------------------------*/
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


/*-----------------------------------------------------------------------------
 *  xtuple_element_type 
 *-----------------------------------------------------------------------------*/
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


/*-----------------------------------------------------------------------------
 *  xget Function.
 *-----------------------------------------------------------------------------*/
//template<int N, typename T>
//튜플 T의 N번째 요소의 타입&
//xget(T& tp)
//{
//	return static_cast<tp의 N번째 기본타입&>(tp).value;
//}
template<int N, typename T>
typename xtuple_element_type<N, T>::type& xget(T& tp)
{
	return static_cast<typename xtuple_element_type<N, T>::tupleType&>(tp).value;
}

int main()
{
	xtuple<int, char, double> t3(3, 'A', 3.4);	
	
	double d = xget<2>(t3);

	cout << d << endl;
	
	cout << xget<1>(t3) << endl; 	// 'A'
	cout << xget<0>(t3) << endl;		// 3
}



