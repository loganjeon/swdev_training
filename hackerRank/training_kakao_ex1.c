
/*-----------------------------------------------------------------------------
 * 	calculate minimum movement between first number and other number.	
 * 	ex)
 * 	input : 2
 * 			1234
 * 			2345
 * 			2
 * 			2134
 * 			1234
 * 	output : 6 
 *
 *-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int myabs(int a, int b)
{
	if(a < b)
		return b - a;
	else
		return a - b;
}

int minimumMoves(int a_size, int* a, int m_size, int* m) 
{
	int ret = 0;

	for (int i = 0; i < a_size; i++) {
		int ta = a[i];
		int tb = m[i];

		while (ta) {
			int digitA = ta % 10;
			int digitB = tb % 10;
			ret += myabs(digitA, digitB);
			ta /= 10;
			tb /= 10;
		}
	}
	return ret;
}

int main()
{
	int res;
	
	int _a_size = 0;
	scanf("%d\n", &_a_size);
	int _a[_a_size];

	for (int i = 0; i < _a_size; i++) {
		int _a_item;
		scanf("%d", &_a_item);

		_a[i] = _a_item;
	}

	int _m_size = 0;
	scanf("%d\n", &_m_size);
	int _m[_m_size];

	for (int i = 0; i < _m_size; i++) {
		int _m_item;
		scanf("%d", &_m_item);

		_m[i] = _m_item;
	}

	res = minimumMoves(_a_size, _a, _m_size, _m);
	printf("%d\n", res);

	return 0;
}



