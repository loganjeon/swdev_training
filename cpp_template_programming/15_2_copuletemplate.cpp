
#include <iostream>
using namespace std;

template<typename T>
void printN(const T& c)
{
	std::cout << T::N << std::endl;
}

template<typename T, typename U>
struct couple
{
	T v1;
	U v2;
	static constexpr int N = 2;
};

template<typename A, typename B, typename C>
struct couple<A, couple<B, C>>
{
	A v1;
	couple<B,C> v2;
	static constexpr int N = couple<B,C>::N + 1;
};

template<typename A, typename B, typename C>
struct couple<couple<A,B>, C>
{
	couple<A,B> v1;
	C 			v2;
	static constexpr int N = couple<A,B>::N + 1;
};

template<typename A, typename B, typename C, typename D>
struct couple<couple<A,B>, couple<C,D>>
{
	couple<A,B> v1;
	couple<C,D> v2;
	static constexpr int N = couple<A,B>::N + couple<C,D>::N;
};

#if 0
int main()
{
	couple<int, double> c2;
	couple<int, couple<int, int>> c3;
	couple<int, couple<int, couple<int, int>>> c4;
	printN(c2);
	printN(c3);
	printN(c4);
}
#else
#if 0
int main()
{
	couple<couple<int, int>, int> c3;
	printN(c3);
}
#else
int main()
{
	couple<couple<int,int>, couple<int,int>> c4;
	printN(c4);
}
#endif
#endif
