#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node{
    int val;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->val=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Node* insert(struct Node* root,int data){
    if(root == NULL){
        return createNode(data);
    }
    else if(data<root->val){
        root->left=insert(root->left,data);
    }
    else if(data>root->val){
        root->right=insert(root->right,data);
    }
    return root;
}
int kthSmallest(struct Node* root,int k){
    struct Node* stack[10000];
    int top=-1;
    struct Node* current=root;
    while(current!=NULL||top>=0){
        while(current!=NULL){
            stack[++top]=current;
            current=current->left;
        }
        current=stack[top--];
        k--;
        if(k==0){
            return current->val;
        }
        current=current->right;
    }
    return -1;
}
void reverseInorder(struct Node* root,int k,int* count,int* result){
    if(root==NULL||*count>=k){
        return;
    }
    reverseInorder(root->right,k,count,result);
    (*count)++;
    if(*count==k){
        *result=root->val;
        return;
    }
    reverseInorder(root->left,k,count,result);
}
int kthLargest(struct Node* root,int k){
    int count=0;
    int result=0;
    reverseInorder(root,k,&count,&result);
    return result;
}
int main(){
    struct Node* root=NULL;
    int n,k;
    clock_t start,end;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int data;
        data=rand()%1000+1;
        printf("The %d element generated is %d\n",i+1,data);
        root=insert(root,data);
    }
    printf("Enter the value of k: ");
    scanf("%d",&k);
    start=clock();
    inta=kthSmallest(root,k);
    end=clock();
    //start=clock();
    //intb=kthLargest(root,k);
    //end=clock();
    double total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("The %d smallest element is: %d\n",k,a);
    //printf("The %d largest element is: %d\n",k,b);
    printf("The time taken is %f milliseconds",total*1000);
    return 0;
}
