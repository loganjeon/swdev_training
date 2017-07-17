int sequentialSearch(int list[], int n, int key)
{
	for(int i=0; i<n; i++)
		if(list[i] == key)
			return i;

	return -1;
}


int findMaxValue( int a[], int len)
{
	int maxVal = a[0];
	for(int i = 0; i < len; i++)
	{
		if( maxVal < a[i] )
			maxVal = a[i];
	}
	return 0;
}

#include <cstdio>
void main()
{
	int arr[10] = {3, 24, 82, 12, 34, 7 ,53, 17, 26, 51};
	int maxVal = findMaxValue( arr, 10 );
	printf( "배열의 최댓값 = %d\n", maxVal );
}
