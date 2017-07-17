
/*-----------------------------------------------------------------------------
 *  ���� 3. Ư�� Ŭ�����ȿ� resize ��� �Լ��� �ִ��� �����ϴ� has_resize<> traits��
 *  ����� ������.
 *
 *-----------------------------------------------------------------------------*/

#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

// ���� �ǵ� SFINAE �� ������ �����ϰ�.. Ư�� ����� �ִ����� �����ϴ� ����� ���� ���̵��..

// �ٽ� : Ư�� ��� �Լ��� �����ϸ� ������ ������ �ʰ�, �������� ������ ������ ������ �ϴ� �ڵ带 ã�ƾ� �Ѵ�.

// ��� 1. resize() �Լ��� ���� Ÿ�Կ� �����͸� ���� Ÿ���� ����ؼ� ���ڸ� �޴� ���


// �Ʒ� Test���� resize�� �ּ� ó���ϰ� ������ ������
class Test
{
public:
//	Test(int n) {}
	void resize(int n) {}
};

template<typename T> void foo(typename  add_pointer<decltype( T().resize(0))>::type    p)	// ���ڵ��� �������� T�� ����Ʈ �����ڰ� ���� ��� �Դϴ�. Test(int) �������� �ּ��� ������ ������..
{															// �ذ�å�� main �Լ� �Ʒ��� �ּ����� �Ǿ��ִ� �ڵ��Դϴ�.
	cout << "resize �� �ֽ��ϴ�." << endl;
}

template<typename T> void foo(...)
{
	cout << "resize�� �����ϴ�." << endl;
}

int main()
{
	foo<Test>(0);
}

/*
template<typename T> void foo(typename  add_pointer<decltype(declval<T>().resize(0))>::type p)	// �� �ڵ�� T�� ����Ʈ �����ڰ� ��� �˴ϴ�.
{															
	cout << "resize �� �ֽ��ϴ�." << endl;
}
*/
