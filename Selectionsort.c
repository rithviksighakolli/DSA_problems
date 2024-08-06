#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void SelectionSorta(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min]) min = j;
        }
        if(min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
void SelectionSortd(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] > arr[min]) min = j;
        }
        if(min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
int main() {
    clock_t t;
    int n = 10000;
    int a[n];
    for(int i = 0; i < n; i++) {
        a[i] = rand() % 1000+1;
    }
    SelectionSorta(a,n);
    t = clock();
    SelectionSorta(a,n);
    t = clock() - t;
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    double time = ((double)t)/CLOCKS_PER_SEC;
    printf("\n%f milliseconds", time*1000);
    return 0;
}
