
#include <iostream>
using namespace std;

struct Null {};

template<typename T, typename U>
struct couple
{
	T v1;
	U v2;
	static constexpr int N = 2;
};

template<typename P1,
	     typename P2>
class xtuple<P1, P2, Null, NUll, Null> : public couple <P1,P2>
{
};

template<typename P1,
	     typename P2,
	     typename p3 = Null,
	     typename p4 = Null,
	     typename p5 = Null>
class xtuple : public couple <P1, xtuple<P2, p3, p4, p5, Null>
{
};

int main()
{
	//								 	 couple<double, int>
	//						   couple<s, xtuple<d, i, N, N, N>>
	//			  couple,char, xtuple<s, d, i, N, N>>
	//couple<int, xtuple<char, short, double, int, Null>>
	xtuple<int, char, short, double, int> t4;

	xtuple<int, char, short> t3;	// 2~5를 보관...
}
