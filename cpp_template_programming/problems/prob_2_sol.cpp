
/*-----------------------------------------------------------------------------
 *  과제 2. 인자로 전달된 컨테이너가 가진 모든 요소의 평균을 구하는 average()를 만
 *  드세요
 *  배열과 STL 컨테이너 모두에 대해서 동작해야 합니다
 *-----------------------------------------------------------------------------*/

 #include <iostream>
 #include <type_traits>
 #include <vector>
 using namespace std;

 // 출제의 의도는 is_array<T>(), true_type, false_type 의 사용법을 위해 출제한 문제입니다.


 // 컨테이너 버전
 template<typename T> double average_imp(const T& c, false_type)
 {
   	cout << "컨테이너" << endl;
   	double s = 0;
   	typename T::const_iterator p = begin(c);

   	while (p != end(c))
   	{
   		s += *p;
   		++p;
   	}
   	return s / c.size();
 }

 // 배열 버전
 template<typename T> double average_imp(const T& c, true_type)
 {
   	cout << "배열" << endl;
   	double s = 0;
   	int sz = extent<T>::value;

   	for (int i = 0; i < sz; i++)
   		s += c[i];

   	return s / sz;
 }

 template<typename T> double average(const T& c)
 {
 	 return average_imp(c, is_array<T>());
 }

 int main()
 {
 	  int x[10]{ 1,2,3,4,5,6,7,8,9,10 };
   	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };


   	cout << average(x) << endl;
   	cout << average(v) << endl;
 }
