
/*-----------------------------------------------------------------------------
 *  과제 3. 특정 클래스안에 resize 멤버 함수가 있는지 조사하는 has_resize<> traits를
 *  만들어 보세요.
 *
 *-----------------------------------------------------------------------------*/

#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

// has_resize를 구현하는 또다른 방법입니다.

class Test
{
public:
	void resize(int n) {}
};


template<typename T, T value> struct helper {};

int main()
{
	helper<void(Test::*)(int), &Test::resize>  a; // resize가 있으면 에러가 아닙니다. resize가 없으면 error입니다.
												   // 이 특징과 SFINAE 개념을 결합하면 됩니다.
}
