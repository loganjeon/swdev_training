
/*-----------------------------------------------------------------------------
 * ���� 4. printf() �Լ��� �������� �������� ������ ������ �߸� ������ ����(������
 * �Ǵ� �����)�� ������ �ʴ� �ٴ� ���Դϴ�. ���� ���� �Լ� ���ø��� ����ؼ�
 * printf()�� ������ �ذ��� ������
 *
 * ��, ��%f������ ó������ ����, ��%d�� ó�� �� �� ������ �˴ϴ�. 
 *-----------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

// ���� 4.
// ���� �ǵ� : �������� ���ø��� Ȱ��


// �Ʒ� �ڵ�� C++ â������ stroustrup �� Ȩ�������� �ִ� �ڵ��Դϴ�.

// �Ʒ� ��ũ�� ���� �ϼ���..
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
