
/*-----------------------------------------------------------------------------
 * Coding_dojang problem 350.
 * Multiples of 3 and 5
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *-----------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

const static int NUM = 1000

int main()
{
	int result = 0;
	for (int i = 0; i < NUM; i++)
	{
		if (i%3 == 0 || i%5 == 0)
			result += i;
	}

	cout << result << endl;
	return 0;
}
