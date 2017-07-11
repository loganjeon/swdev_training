#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
 * Complete the function below.
 */
int getCard(int num)
{
    int i, ret = 0;
    int tmp;
    while(num) {
        tmp = num & (-1 * num);
        num -= tmp;
        ret++;
    }
    return ret;
}
int* cardinalitySort(int nums_size, int* nums, int* res_size) {
    int i, j, o;
    int order[21][100001];
    int orderNum[21];
    for (i = 0; i < 21; i++) {
        orderNum[i] = 0;
        for (j = 0; j < 100001; j++) {
            order[i][j] = 0;
        }
    }

    for (i = 0; i < nums_size; i++) {
        int card = getCard(nums[i]);
        order[card][orderNum[card]++] = nums[i];
    }

    int result_size = 0;

    for (o = 0; o < 21; o++) {
        if (orderNum[o]) {
            if (orderNum[o] == 1) {
                nums[result_size++] = order[o][0];
            } else {
                for (i = 0; i < orderNum[o] - 1; i++)
                {
                    for (j = i + 1; j < orderNum[o]; j++) {
                        if (order[o][i] > order[o][j]) {
                            int tmp = order[o][i];
                            order[o][i] = order[o][j];
                            order[o][j] = tmp;
                        }
                    }
                }

                for (i = 0; i < orderNum[o]; i++) {
                    nums[result_size++] = order[o][i];
                }
            }
        }
    }
    *res_size = result_size;
    return nums;
}


int main() {
    char *output_path = getenv("OUTPUT_PATH");
    FILE *f;
    if (output_path != NULL) {
    	f = fopen(output_path, "w");
    }
    else {
    	f = stdout;
    }

    int res_size;
    int* res;

    int _nums_size = 0;
    int _nums_i;
    scanf("%d\n", &_nums_size);
    int _nums[_nums_size];
    for(_nums_i = 0; _nums_i < _nums_size; _nums_i++) {
        int _nums_item;
        scanf("%d", &_nums_item);

        _nums[_nums_i] = _nums_item;
    }

    res = cardinalitySort(_nums_size, _nums, &res_size);
    int res_i;
    for(res_i=0; res_i < res_size; res_i++) {

        fprintf(f, "%d\n", res[res_i]);

    }
    
    fclose(f);
    return 0;
}
