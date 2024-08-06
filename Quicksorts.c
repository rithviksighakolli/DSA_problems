#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int arr[],int s,int e){
    int pivot=arr[s];
    int pindex=e;
    for(int i=e;i>s;i--){
        if(arr[i]>=pivot){
            int temp=arr[i];
            arr[i]=arr[pindex];
            arr[pindex]=temp;
            pindex--;
        }
    }
    int temp=arr[s];
    arr[s]=arr[pindex];
    arr[pindex]=temp;
    return pindex;
}
void QuickSort(int arr[],int s,int e){
    if(s<e){
        int p=partition(arr,s,e);
        QuickSort(arr,s,p-1);
        QuickSort(arr,p+1,e);
    }
}
int main() {
    clock_t t;
    int n = 10000;
    int a[n];
    for(int i = 0; i < n; i++) {
        a[i] = rand() % 10000+1;
    }
    t = clock();
    QuickSort(a,0,n);
    t = clock() - t;
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    double time = ((double)t)/CLOCKS_PER_SEC;
    printf("\n%f milliseconds", time*1000);
    return 0;
}