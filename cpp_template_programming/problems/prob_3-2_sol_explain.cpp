
/*-----------------------------------------------------------------------------
 *  ���� 3. Ư�� Ŭ�����ȿ� resize ��� �Լ��� �ִ��� �����ϴ� has_resize<> traits��
 *  ����� ������.
 *
 *-----------------------------------------------------------------------------*/

#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

// has_resize�� �����ϴ� �Ǵٸ� ����Դϴ�.

class Test
{
public:
	void resize(int n) {}
};


template<typename T, T value> struct helper {};

int main()
{
	helper<void(Test::*)(int), &Test::resize>  a; // resize�� ������ ������ �ƴմϴ�. resize�� ������ error�Դϴ�.
												   // �� Ư¡�� SFINAE ������ �����ϸ� �˴ϴ�.
}
