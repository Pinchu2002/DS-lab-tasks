#include<stdio.h>
#include<stdlib.h>

// struct for BST
struct node{
    int data;
    struct node* left;
    struct node*  right;
    struct node* parent;
};

// max function
int max(int a, int b){
    if(a > b) return a;
    return b;
}

// function to calculate height of BST
int findHeight(struct node* root){
    if(root == NULL){
        return -1;
    }
    return (max(findHeight(root->left),findHeight(root->right)) + 1);
}

// creating new node
struct node* newNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
    return newnode;
}

// Insertion of new node in BST
struct node* Insert(struct node* node, int data){
    if(node == NULL){
        return newNode(data);
    }
    else{
        struct node* temp;
        if(data <= node->data){
            temp = Insert(node->left,data);
            node->left = temp;
            temp->parent = node;
        }
        else{
            temp = Insert(node->right,data);
            node->right = temp;
            temp->parent = node;
        }

        return node;
    }
}

// main function
int main(){
    struct node *root = NULL;
    root = Insert(root,20);
    root = Insert(root,8);
    root = Insert(root,22);
    root = Insert(root,4);
    root = Insert(root,12);
    root = Insert(root,10);
    root = Insert(root,14);
    root = Insert(root,17);
    printf("\nHeight of BST is %d",findHeight(root));
}