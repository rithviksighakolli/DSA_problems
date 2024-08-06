#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Merge(int arr[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    int temp[r+1];
    while(i<=m && j<=r) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++; k++;
        } else {
            temp[k] = arr[j];
            j++; k++;
        }
    }
    while(i<=m) {
        temp[k] = arr[i];
        i++; k++;
    }
    while(j<=r) {
        temp[k] = arr[j];
        j++; k++;
    }
    for(int p = l; p <= r; p++) {
        arr[p] = temp[p];
    }
}

void Merge1(int arr[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    int temp[r+1];
    while(i<=m && j<=r) {
        if(arr[i] >= arr[j]) {
            temp[k] = arr[i];
            i++; k++;
        } else {
            temp[k] = arr[j];
            j++; k++;
        }
    }
    while(i<=m) {
        temp[k] = arr[i];
        i++; k++;
    }
    while(j<=r) {
        temp[k] = arr[j];
        j++; k++;
    }
    for(int p = l; p <= r; p++) {
        arr[p] = temp[p];
    }
}
void MergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l)/2;
        MergeSort(arr, l ,m);
        MergeSort(arr, m+1, r);
        Merge(arr, l, m, r);
    }
}

void MergeSort1(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l)/2;
        MergeSort1(arr, m+1, r);
        MergeSort1(arr, l ,m);
        Merge1(arr, l, m, r);
    }
}
int main() {
    clock_t t;
    int n = 10000;
    int a[n];
    for(int i = 0; i < n; i++) {
        a[i] = rand() % 10000+1;
    }
    //MergeSort1(a,0,n);
    t = clock();
    MergeSort(a,0,n);
    t = clock() - t;
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    double time = ((double)t)/CLOCKS_PER_SEC;
    printf("\n%f milliseconds", time*1000);
    return 0;
}