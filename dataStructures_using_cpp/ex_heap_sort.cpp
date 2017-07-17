
#include <time.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_NUM 1000

int a[MAX_NUM];

void heapBuild(int i, int n){
    int p = i;
    int c = p*2 + 1;
    while(c<n){
        if(c+1 < n && a[c] < a[c+1])
            c++;

        if(a[p] < a[c]){
            int tmp = a[p];
            a[p] = a[c];
            a[c] = tmp;
        }
        p = c;
        c = p*2 +1;
    }
}
void heapSort(int n){
    int i;
    for(i=n/2-1 ; i>= 0 ; i--){
        heapBuild(i, n);
    }
    for(i=n-1 ; i> 0 ; i--){
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        heapBuild(0, i);
    }
}
int main(){
    int i;
    clock_t start, end;
    srand(3);
    for(i=0 ; i<MAX_NUM ; i++){
        a[i] = rand() % 10000;
    }
    start = clock();
    heapSort(MAX_NUM);
    end = clock();
    int flag = 0;
    for(i=1 ; i<MAX_NUM ; i++){
        int tmp = a[i] - a[i-1];
        if(tmp < 0)
        flag++;
    }

    cout << "right: " << flag << endl;
    cout << "time: " << (end-start) << endl;
    return 0;
}
