
/*-----------------------------------------------------------------------------
 * 과제 4. printf() 함수의 전통적인 문제점은 인자의 개수를 잘못 보내도 에러(컴파일
 * 또는 실행시)가 나오지 않는 다는 점입니다. 가변 인자 함수 템플릿을 사용해서
 * printf()의 문제를 해결해 보세요
 *
 * 단, “%f”등은 처리하지 말고, “%d” 처리 할 수 있으면 됩니다. 
 *-----------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

// 과제 4.
// 출제 의도 : 가변인자 템플릿을 활용


// 아래 코드는 C++ 창시자인 stroustrup 의 홈페이지에 있는 코드입니다.

// 아래 링크를 참고 하세요..
// http://www.stroustrup.com/C++11FAQ.html#variadic-templates


void cpp_print(const char* s)
{
	while (s && *s) {
		if (*s == '%' && *++s != '%')
			throw runtime_error("invalid format: missing arguments");
		std::cout << *s++;
	}
}

template<typename T, typename... Args>
void cpp_print(const char* s, T value, Args... args)
{
	while (s && *s) {
		if (*s == '%' && *++s != '%') {
			std::cout << value;
			return cpp_print(++s, args...);
		}
		std::cout << *s++;
	}
	throw std::runtime_error("extra arguments provided to printf");
}

int main()
{
	try
	{
		//cpp_print("%d");

		cpp_print("%d\n", 1, 2, 3);

		//cpp_print("%d\n", 1);
	}
	catch (...)
	{
		cout << "exception.." << endl;
	}
}
