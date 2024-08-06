#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void insert(struct Node** root,int data){
    if(*root==NULL){
        *root=createNode(data);
    } else if(data<(*root)->data){
        insert(&(*root)->left,data);
    } else if(data>(*root)->data){
        insert(&(*root)->right,data);
    }
}
void kthSmallestUtil(struct Node* root,int k,int* count,int* result){
    if (root==NULL||*count>=k){
        return;
    }
    kthSmallestUtil(root->left,k,count,result);
    (*count)++;
    if (*count==k){
        *result=root->data;
        return;
    }
    kthSmallestUtil(root->right,k,count,result);
}
int kthSmallest(struct Node* root,int k){
    int count=0;
    int result=0;
    kthSmallestUtil(root,k,&count,&result);
    return result;
}
void kthLargestUtil(struct Node* root,int k,int* count,int* result){
    if(root==NULL||*count>=k){
        return;
    }
    kthLargestUtil(root->right,k,count,result);
    (*count)++;
    if(*count==k){
        *result=root->data;
        return;
    }
    kthLargestUtil(root->left,k,count,result);
}
int kthLargest(struct Node* root,int k){
    int count=0;
    int result=0;
    kthLargestUtil(root,k,&count,&result);
    return result;
}
int main(){
    struct Node* root=NULL;
    int n,k;
    clock_t start,end;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int data=rand()%1000+1;
        printf("The %d element generated is %d\n",i+1,data);
        insert(&root,data);
    }
    printf("Enter the value of k: ");
    scanf("%d",&k);
    start=clock();
    int a=kthSmallest(root,k);
    end=clock();
    //start=clock();
    //int b=kthLargest(root,k);
    //end=clock();
    double total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("The %d smallest element is: %d\n",k,a);
    //printf("The %d largest element is: %d\n",k,b);
    printf("The time taken is %f seconds\n",total);
    return 0;
}
