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


// function for inorder traversal
void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\n",root->key);
        inorder(root->right);
    }
}

// function for preorder traversal
void preorder(struct node* root){
    if(root != NULL){
        printf("%d\n",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// function for postorder traversal
void postorder(struct node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\n",root->key);
    }
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
    printf("\n");
    printf("Preorder Tranversal of BST: \n");
    preorder(root);
    printf("\n");
    printf("Postorder Tranversal of BST: \n");
    postorder(root);

    return 0;
}