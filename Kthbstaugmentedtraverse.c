#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node{
    int val;
    int size;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->val=val;
    newNode->size=1;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Node* insert(struct Node* root,int val){
    if(root==NULL){
        return createNode(val);
    }
    if(val<root->val){
        root->left=insert(root->left,val);
    }
    else if(val>root->val){
        root->right=insert(root->right,val);
    }
    root->size++;
    return root;
}
int kthSmallest(struct Node* root,int k){
    if(root==NULL||k<=0||k>root->size){
        return -1;
    }
    int leftSize=(root->left!=NULL)?root->left->size:0;
    if(k<=leftSize){
        return kthSmallest(root->left,k);
    }
    else if(k==leftSize+1){
        return root->val;
    }
    else{
        return kthSmallest(root->right,k-leftSize-1);
    }
}
int kthLargest(struct Node* root,int k){
    if(root==NULL||k<=0||k>root->size){
        return -1;
    }
    int rightSize=(root->right!=NULL)?root->right->size:0;
    if(k<=rightSize){
        return kthLargest(root->right,k);
    }
    else if(k==rightSize+1){
        return root->val;
    }
    else{
        return kthLargest(root->left,k-rightSize-1);
    }
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
    //start=clock();
    //int a=kthSmallest(root,k);
    //end=clock();
    start=clock();
    int b=kthLargest(root,k);
    end=clock();
    double total=(double)(end-start)/CLOCKS_PER_SEC;
    //printf("The %d smallest element is %d\n",k,a);
    printf("The %d largest element is %d\n",k,b);
    printf("The time taken is %f milliseconds",total*1000);
    return 0;
}