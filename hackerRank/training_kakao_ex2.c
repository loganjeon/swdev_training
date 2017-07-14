
#include <stdio.h>
#include <string.h>


// count 1s in binary number
int getCard(int num)
{
	int ret = 0;
	int tmp;

	while (num) {
		tmp = num & (-1 * num);
		num -= tmp;
		ret++;
	}

	return ret;
}

int* cardinalitySort(int nums_size, int* nums, int* res_size)
{
	int order[21][10001];
	int orderNum[21];
	int result_size = 0;

	for (int i = 0; i < 21; i++) {
		orderNum[i] = 0;
		for (int j = 0; j < 10001; j++) {
			order[i][j] = 0;
		}
	}
	
	// set counter sort table
	for (int i = 0; i < nums_size; i++) {
		int card = getCard(nums[i]);
		order[card][orderNum[card]++] = nums[i];
	}


	// sort
	for (int o = 0; o < 21; o++) {
		if (orderNum[o]) {
			if(orderNum[o] == 1) {
				nums[result_size++] = order[o][0];
			} else {
				// sort each row of counter sort table
				for (int i = 0; i < orderNum[o] - 1; i++) {
					for (int j = i + 1; j < orderNum[o]; j++) {
						if (order[o][i] > order[o][j]) {
							int tmp = order[o][i];
							order[o][i] = order[o][j];
							order[o][j] = tmp;
						}
					}
				}

				for (int i = 0; i < orderNum[o]; i++) {
					nums[result_size++] = order[o][i];
				}
			}
		}
	}
	*res_size = result_size;
	return nums;
}

int main()
{
	int res_size;
	int* res;
	
	int _nums_size = 0;
	scanf("%d\n", &_nums_size);
	int _nums[_nums_size];

	for ( int i = 0; i < _nums_size; i++) {
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
