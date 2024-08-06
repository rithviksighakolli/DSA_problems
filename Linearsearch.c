#include <stdio.h>
#include <time.h>
int main()
{
    int x;int n;
    printf("Enter the no of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    clock_t start_t,end_t;
    double total_t=0.0;
    printf("Enter the element to be searched: ");
    scanf("%d",&x);
    for(int i=0;i<n;i++)
    {
        arr[i]=i;
    }
    start_t=clock();
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            printf("Element searched at %d",i+1);
        }
    }
    end_t=clock();
    total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;
    total_t*=1000;
    printf("\nTime taken is %f milli seconds",total_t);
    return 0;
}