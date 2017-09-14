
#include <stdio.h>
#include <string.h>

int getCard(int num)
{
	int tmp;
	int ret = 0;

	while(num) {
		tmp = num & (-1 * num);
		num -= tmp;
		ret++;
	}
	return ret;
}

int* cardinalitySort(int nums_size, int* nums, int* res_size)
{
	int order[21][100001];
//	int order[21][10001];
	int orderNum[21];

	for (int i = 0; i < 21; i++) {
		orderNum[i] = 0;
		for ( int j = 0; j < 100001; j++) {
//		for ( int j = 0; j < 10001; j++) {
			order[i][j] = 0;
		}
	}

	for (int i = 0; i < nums_size; i++) {
		int card = getCard(nums[i]);
		printf("%d\n", card);
	}
}

int main()
{
	int res_size = 0;
	int* res;

	int _nums_size = 0;
	scanf("%d\n", &_nums_size);
	int _nums[_nums_size];

	for (int i = 0;  i < _nums_size; i++) {
		int _nums_item;
		scanf("%d", &_nums_item);
		_nums[i] = _nums_item;
	}

	res = cardinalitySort(_nums_size, _nums, &res_size);
	
	for (int i = 0; i < res_size; i++) {
		printf("%d\n", res[i]);
	}
	return 0;
}
