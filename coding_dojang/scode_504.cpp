
/*-----------------------------------------------------------------------------
 * Coding dojang problem 504.
 * 1~1000에서 각 숫자의 개수 구하기
 *
 * 예로 10 ~ 15 까지의 각 숫자의 개수를 구해보자
 *
 * 10 = 1, 0
 * 11 = 1, 1
 * 12 = 1, 2
 * 13 = 1, 3
 * 14 = 1, 4
 * 15 = 1, 5
 *
 * 그러므로 이 경우의 답은 0:1개, 1:7개, 2:1개, 3:1개, 4:1개, 5:1개 
 *-----------------------------------------------------------------------------*/


#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str_num[1000];
	int result[10] = {0, };

	for (int i = 1; i <= 1000; i++) {
		str_num[i-1] = to_string(i);

		for (int j = 0; j < str_num[i-1].length(); j++) {
			int index = str_num[i-1].at(j) - '0';
			result[index] += 1;
		}
	}

	for (int i = 0; i < 10; i++) {
		std::cout <<result[i]  << std::endl;
	}
}

