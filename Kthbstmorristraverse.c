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
    if(root==NULL){
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
    int count=0;
    int result=-1;
    struct Node* current=root;
    while(current!=NULL){
        if(current->left==NULL){
            count++;
            if(count == k){
                result=current->val;
                break;
            }
            current=current->right;
        }
        else{
            struct Node* predecessor=current->left;
            while(predecessor->right!=NULL&&predecessor->right!=current){
                predecessor=predecessor->right;
            }
            if(predecessor->right==NULL){
                predecessor->right=current;
                current=current->left;
            }
            else{
                predecessor->right=NULL;
                count++;
                if(count==k){
                    result=current->val;
                    break;
                }
                current=current->right;
            }
        }
    }
    return result;
}
int kthLargest(struct Node* root,int k){
    int count=0;
    int result=-1;
    struct Node* current=root;
    while(current!=NULL){
        if(current->right==NULL){
            count++;
            if(count==k){
                result=current->val;
                break;
            }
            current=current->left;
        }
        else{
            struct Node* successor=current->right;
            while(successor->left!=NULL&&successor->left!=current){
                successor=successor->left;
            }
            if(successor->left==NULL){
                successor->left=current;
                current=current->right;
            }
            else{
                successor->left=NULL;
                count++;
                if(count==k){
                    result=current->val;
                    break;
                }
                current=current->left;
            }
        }
    }
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
