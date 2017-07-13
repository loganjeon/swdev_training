
#include <iostream>
#include <typeinfo>

using namespace std;

int f(int a, double b) { return 0; }
void f2() {}
int f3(int a, double b, char c, short s, unsigned int ui) { return 0; }

template<int N, typename T>
struct argument
{
	//typedef T type;
	typedef void type;
};

// N == 0 을 위한 부분 특수화
template<typename R, typename A1, typename ... Types>
struct argument<0, R(A1, Types...)>
{
	typedef A1 type;
};

// N != 0 을 위한 부분 특수화
template<int N, typename R, typename A1, typename ... Types>
struct argument<N, R(A1, Types...)>
{
	typedef typename argument<N-1, R(Types...)>::type type;
};

template<typename T>
void foo(T& a)
{
	//typename argument<0, T>::type n;
	//typename argument<1, T>::type n;
	//typename argument<0, T>::type n;
	//typename argument<0, T>::type* n;
	typename argument<4, T>::type n;
	
	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	//foo(f);
	//foo(f2);
	foo(f3);
}
