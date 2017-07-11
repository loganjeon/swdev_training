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
int count[26];

int getNum1(char* s) {
    return s[0] - '0';
}

int getNum2(char* s) {
    int retVal = s[0] - '0';
    retVal *= 10;
    retVal += s[1] - '0';
    return retVal;
}

int* frequency(char* s, int* result_size) {
    int i, j, len = strlen(s);
    *result_size = 26;

    for (i = 0; i < 26; i++) {
        count[i] = 0;
    }

    for ( i = 0; i < len; ) {
        char *tmpStr = &s[i];
        int num, cnt = 1;

        if(tmpStr[2] == '#') {
            num = getNum2(tmpStr);
            i += 3;
            if (tmpStr[3] == '(') {
                i++;
                cnt = 0;
                while(s[i] != ')') {
                    cnt *= 10;
                    cnt += getNum1(&s[i]);
                    i++;
                }
            }
        } else {
            num = getNum1(tmpStr);
            i++;
            if (tmpStr[1] == '(') {
                i++;
                cnt = 0;
                while (s[i] != ')') {
                    cnt *= 10;
                    cnt += getNum1(&s[i]);
                    i++;
                }
            }
        }
        count[num-1] += cnt;
    }
    return count;
}

int main() {
    FILE *f = fopen(getenv("OUTPUT_PATH"), "w");
    int res_size;
    int* res;
    char* _s;
    _s = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",_s);

    res = frequency(_s, &res_size);
    int res_i;
    for(res_i=0; res_i < res_size; res_i++) {

        fprintf(f, "%d\n", res[res_i]);

    }


    fclose(f);
    return 0;
}
