#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int* a, int* b){
    int temp= *a;
    *a=*b;
    *b=temp;
}
void heap(int arr[], int n, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n&&arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        heap(arr,n,largest);
    }
}
void heapsort(int arr[], int n){
    for(int i=n/2-1;i>=0;i--){
        heap(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heap(arr,i,0);
    }
}
int main(){
    int n;
    printf("Enter the no of elements in the array: ");
    scanf("%d",&n);
    int arr[n+1];
    clock_t start,end;
    for(int i=0;i<n;i++){
        arr[i]=rand(1000+1);
        printf("The %d element generated is %d\n",i+1,arr[i]);
    }
    heapsort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    
}