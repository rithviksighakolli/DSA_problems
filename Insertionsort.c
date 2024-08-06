#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void InsertionSorta(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int temp = a[i], j = 0;
        for(j = i - 1; j >= 0 && a[j]>temp; j--) {
            a[j+1] = a[j];
        }
        a[j+1] = temp;
    }
}
void InsertionSortd(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int temp = a[i], j = 0;
        for(j = i - 1; j >= 0 && a[j]<temp; j--) {
            a[j+1] = a[j];
        }
        a[j+1] = temp;
    }
}
int main() {
    clock_t t;
    int n = 10000;
    int a[n];
    for(int i = 0; i < n; i++) {
        a[i] = rand() % 1000+1;
    }
    InsertionSorta(a,n);
    t = clock();
    InsertionSorta(a,n);
    t = clock() - t;
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    double time = ((double)t)/CLOCKS_PER_SEC;
    printf("\n%f milliseconds", time*1000);
    return 0;
}
