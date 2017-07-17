
/*-----------------------------------------------------------------------------
 * 과제 1. N1 ~ N2 사이의 합을 구하는 Sum을 만드세요
 * 조건 1. 모든 정수 타입에는 동작해야 하지만 실수 일 경우는 컴파일 에러가 나와야 합니다.
 * 조건 2. static_assert() 버전과 enable_if 버전으로 각각 작성해 보세요
 *-----------------------------------------------------------------------------*/

 #include <iostream>
 #include <type_traits>
 #include <algorithm>
 using namespace std;

 // 출제 의도 : 1. enable_if 의 개념과 사용법 익히기
 //			   2. static_assert와 enable_if 의 차이점

 // 확인할 내용 : static_assert 버전과 eanble_if 버전이 각각 실패 할때 나오는 에러 메세지를 비교해 보세요.

 // 1. static_assert 버전
 template<typename T> T Sum1(T a, T b)
 {
   	static_assert(is_integral<T>::value, "error T is not integer type");

   	T s = 0;
   	for (int i = a; i <= b; i++)
   		s += i;
   	return s;
 }

 // 2. enable_if 버전
 // A. 리턴 타입에 적용하는 방식
 template<typename T>  typename enable_if<is_integral<T>::value, T>::type Sum2(T a, T b)
 {
   	T s = 0;
   	for (int i = a; i <= b; i++)
   		s += i;
   	return s;
 }

 // B. 함수 인자에 적용하는 방식 - 생성자등은 리턴 타입이 없으므로 리턴 타입이 없는 경우에는 인자에 적용해도 됩니다.
 template<typename T> T Sum3(T a, typename enable_if<is_integral<T>::value, T>::type  b)
 {
   	T s = 0;
   	for (int i = a; i <= b; i++)
   		s += i;
   	return s;
 }

 int main()
 {
   	int		n1 = 5, n2 = 10;
   	short	s1 = 5, s2 = 10;
   	double	d1 = 3.4, d2 = 1.2;

   	Sum1(n1, n2); // ok
   	Sum1(s1, s2); // ok
   	//Sum1(d1, d2); // error가 나와야 합니다.

 }
