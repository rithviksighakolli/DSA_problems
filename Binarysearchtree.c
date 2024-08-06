#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insert(struct Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if (data<(*root)->data) {
        insert(&(*root)->left, data);
    } else if (data>(*root)->data) {
        insert(&(*root)->right, data);
    }
}
int findSmallest(struct Node *root) {
    if(root->left==NULL){
        return root->data;
    }
    return findSmallest(root->left);
}
int findLargest(struct Node *root) {
    if(root->right==NULL){
        return root->data;
    }
    return findLargest(root->right);
}
int main() {
    struct Node* root = NULL;
    int n, data;
    clock_t start,end;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    for(int i=0; i<n;i++) {
        printf("\n Enter element %d : ",i+1 );
        scanf("%d",&data);
        insert(&root, data);
    }
    start=clock();
    int a=findSmallest(root);
    end=clock();
    //start=clock();
    int b=findLargest(root);
    //end=clock();
    double total= (double)(end-start)/CLOCKS_PER_SEC;
    printf("The smallest number in the tree is: %d\n",a);
    //printf("The largest number in the tree is: %d\n",b);
    printf("The time taken is %f milliseconds",total*1000);
}