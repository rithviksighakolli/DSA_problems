#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};
int height(struct Node* node){
    if(node==NULL)
        return 0;
    return node->height;
}
int max(int a,int b){
    if(a>b){
        return a;
    }
    else if(b>a){
        return b;
    }
}
struct Node* newnode(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
}
struct Node* rightrotate(struct Node* y){
    struct Node* x=y->left;
    struct Node* t=x->right;
    x->right=y;
    y->left=t;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}
