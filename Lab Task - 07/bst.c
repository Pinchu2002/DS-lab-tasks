#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *left, *right;
};

// function to create a new BST node
struct node* newNode(int item){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key){
    if(node == NULL)
        return newNode(key);
    
    if(key < node->key)
        node->left = insert(node->left,key);
    else 
        node->right = insert(node->right,key);
    
    return node;
}


// function for inorder
void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\n",root->key);
        inorder(root->right);
    }
}

//function to count non leaf nodes in BST
int countnonleaf(struct node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL)) 
        return 0;
    
    return (1 + countnonleaf(root->left) + countnonleaf(root->right)); 
}

// fucntion to count leafs
int countleaf(struct node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    else 
        return countleaf(root->left) + countleaf(root->right);
}   

// function to find minimum element of BST
int minelementbst(struct node* root){
    struct node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->key;
}

int main(){
    
    struct node* root = NULL;
    root = insert(root,50);
    insert(root,30);
    insert(root,40);
    insert(root,20);
    insert(root,60);
    insert(root,70);
    insert(root,80);
    // root = newNode(50);
    // root->left = newNode(30);
    // root->right = newNode(70);
    // root->left->left = newNode(20);
    // root->right->right = newNode(40);
    // root->right->left = newNode(60);
    // root->right->right = newNode(80);
    printf("Inorder Tranversal of BST: \n");
    inorder(root);
    printf("Number of non-leaf nodes in BST: %d\n", countnonleaf(root));
    printf("Number of leaf nodes in BST: %d\n", countleaf(root));
    printf("Minimum Element of BST: %d\n", minelementbst(root));
    return 0;
}