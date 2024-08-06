#include <stdio.h>
#include <time.h>
int main() {
    int n;
    printf("Enter the no of elements in an array: ");
    scanf("%d",&n);
    int arr[n];
    int left=0;
    int right=n-1;
    int index=-1;
    int x;
    printf("Enter the element to be searched: ");
    scanf("%d",&x);
    for(int i=0;i<n;i++){
        arr[i]=i;
    }
    clock_t start_t=clock();
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==x){
            index=mid;
            break;
        }
        else if(arr[mid]<x){
            left=mid+1;
        }
        else{
            right=mid-1;
        }      
    }
    if(index !=-1){
        printf("The element is searched at the position %d",index+1);
    }
    clock_t end_t=clock();
    double total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;
    printf("\nTime taken is %f milli seconds",total_t*1000);
    return 0;
}