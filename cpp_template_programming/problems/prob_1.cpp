
#include <iostream>
#include <type_traits>

using namespace std;

double Sum(double a, double b)
{
	std::cout << "only possible to integer" << std::endl;
}

#if 0  // version of static_assert()

template<typename T>
void Sum(T a, T b)
{
	static_assert( is_integral<T>::value, "T is not integral" );
	
	int nDiff = b - a;
	int result = 0;
	
	for (int i = 0; i < nDiff+1; i++)
	{
		result += a+i;
	}

	std::cout << result << std::endl;
}

#else	// version of enable_if

template<typename T>
typename enable_if<is_integral<T>::value>::type Sum(T a, T b)
{
	int nDiff = b - a;
	int result = 0;
	
	for (int i = 0; i < nDiff+1; i++)
	{
		result += a+i;
	}

	std::cout << result << std::endl;
}

#endif

int main()
{
	int 	n1 = 5, n2 = 10;
	short	s1 = 5, s2 = 10;
	double 	d1 = 3.4, d2 = 1.2;

	Sum(n1, n2);
	Sum(s1, s2);
	Sum(d1, d2);
	
}



