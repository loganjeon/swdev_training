
#include <iostream>

using namespace std;

template<bool, typename T, typename U>
struct IfThenElse
{
	typedef T type;
};

template<typename T, typename U>
struct IfThenElse<false, T, U>
{
	typedef U type;
};
#if 0
int main()
{
	IfThenElse<true, int, double>::type n1;
	IfThenElse<false, int, double>::type n1;
}
#endif

template<int N>
struct Bit
{
	//using data_type = unsigned int;
	using data_type = typename IfThenElse< N <= 8, char, unsigned int>::type; 

	data_type data;
};

int main()
{
	Bit<8> b1;
	Bit<32>	b2;

	cout << sizeof(b1) << endl;
	cout << sizeof(b2) << endl;
}


