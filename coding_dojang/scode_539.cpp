
/*-----------------------------------------------------------------------------
 *	Coding dojang problem 539.
 *	완전수 구하기
 *
 *  자기 자신을 제외한 모든 양의 약수들의 합이 자기 자신이 되는 자연수를 완전수라고 한다. 예를 들면, 6과 28은 완전수이다. 6=1+2+3 // 1,2,3은 각각 6의 약수 28=1+2+4+7+14 // 1,2,4,7,14는 각각 28의 약수
 *
 *  입력으로 자연수 N을 받고, 출력으로 N 이하의 모든 완전수를 출력하는 코드를 작성하라.
 *-----------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

bool isCompleteNum(int n)
{
	int sum = 0;

	for (int i = 1; i < n; i++) {
			if (n % i == 0)
				sum += i;
	}

	return sum == n ? true : false;	
}

int main()
{
	int max = 0;
	cin >> max;

	for (int i = 1; i <= max; i++)
	{
		if ( isCompleteNum(i) )
		{
			std::cout << "complete number : " << i << std::endl;
		}
	}
	return 0;
}
