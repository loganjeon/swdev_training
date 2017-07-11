
/*-----------------------------------------------------------------------------
 *  Coding_dojang problem 408.
 *  다음 입사문제 중에서
 *
 *  1차원의 점들이 주어졌을 때, 그 중 가장 거리가 짧은 것의 쌍을 출력하는 함수를 작성하시오. (단 점들의 배열은 모두 정렬되어있다고 가정한다.)
 *
 *  예를들어 S={1, 3, 4, 8, 13, 17, 20} 이 주어졌다면, 결과값은 (3, 4)가 될 것이다.
 *-----------------------------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321

bool check_min_dist(int& pIdx1, int& pIdx2, const vector<int>& v, const int n)
{
	int min_dist = INF;
	
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (min_dist > abs(v[i] - v[j])) {
				pIdx1 = i;
				pIdx2 = j;
				min_dist = abs(v[i] - v[j]);
			}
		}
	}
	
	return 1;
}


int main()
{
	int n;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num ;
		v.push_back(num);
	}

	int idx1, idx2 = INF;
	
	if ( check_min_dist(idx1, idx2, v,  n) == 0)
		cout << "check error" << endl;

	cout << v[idx1] << ", " << v[idx2] << endl;
	
	return 0;
}
