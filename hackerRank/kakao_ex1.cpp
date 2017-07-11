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
int minimumMoves(int a_size, int* a, int m_size, int* m) {

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

    int res;

    int _a_size = 0;
    int _a_i;
    scanf("%d\n", &_a_size);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++) {
        int _a_item;
        scanf("%d", &_a_item);

        _a[_a_i] = _a_item;
    }


    int _m_size = 0;
    int _m_i;
    scanf("%d\n", &_m_size);
    int _m[_m_size];
    for(_m_i = 0; _m_i < _m_size; _m_i++) {
        int _m_item;
        scanf("%d", &_m_item);

        _m[_m_i] = _m_item;
    }

    res = minimumMoves(_a_size, _a, _m_size, _m);
    fprintf(f, "%d\n", res);

    fclose(f);
    return 0;
}
