#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void BubbleSorta(int arr[], int n) {
    int flag = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}
void BubbleSortd(int arr[], int n) {
    int flag = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}
int main() {
    clock_t t;
    int n;
    printf("Enter the no of elements in an array: ");
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++) {
        a[i] = rand() % 10000+1;// random function to get random values in the range 10000
    }
    BubbleSorta(a,n);
    t = clock();
    BubbleSorta(a,n);
    t = clock() - t;
    printf("The sorted array is: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    double time = ((double)t)/CLOCKS_PER_SEC;
    printf("\n%f milliseconds", time*1000);
    return 0;
}
