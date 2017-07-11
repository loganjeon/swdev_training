
#include <iostream>
using namespace std;


// 메타 함수 : 컴파일 시간에 사용되는 함수
// c++ Template Meta Programming

template<int N>
struct Factorial
{
	enum { value = N * Factorial<N-1>::value };
};

template<int N>
struct Factorial<1>
{
	enum { value = 1 };
};

int main()
{
	int n = Factorial<5>::value;	// int n = 120;

	std::cout << n << std::endl;
}
