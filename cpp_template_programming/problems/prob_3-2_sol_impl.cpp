
/*-----------------------------------------------------------------------------
 *  과제 3. 특정 클래스안에 resize 멤버 함수가 있는지 조사하는 has_resize<> traits를
 *  만들어 보세요.
 *
 *-----------------------------------------------------------------------------*/

#include <iostream>
#include <type_traits>
#include <vector>
#include <array>
using namespace std;


template<typename T> struct has_resize
{
private:
	template<typename U, U> struct helper {};
	
	typedef char YES;
	typedef short NO;
	template<typename U> static YES check( helper<void(U::*)(unsigned long long), &U::resize>* p);	// for g++
	template<typename U> static YES check(helper<void(U::*)(unsigned int), &U::resize>* p);			// for vc
	template<typename U> static NO  check(...);
public:

	enum { value = (sizeof(check<T>(0)) == sizeof(YES)) };
};


int main()
{
	cout << has_resize<vector<int>>::value << endl;   // 1
	cout << has_resize<array<int, 10>>::value << endl;// 0
}
