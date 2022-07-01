#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};

struct node* minValue(struct node* node){
    struct node* l = node;
    while(l->left != NULL){
        l = l->left;
    }
    return l;
}


struct node* InOrderSuccessor(struct node* root, struct node* n){
    if(n->right != NULL){
        return minValue(n->right);
    }
    struct node* p = n->parent;
    while(p != NULL && n == p->right){
        n = p;
        p = p->parent;
    }
    return p;
}

struct node* newNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
    return newnode;
}

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

int main(){
    struct node *root = NULL;
    struct node *temp, *succ;
    root = Insert(root,20);
    root = Insert(root,8);
    root = Insert(root,22);
    root = Insert(root,4);
    root = Insert(root,12);
    root = Insert(root,10);
    root = Insert(root,14);

    temp = root->left->right->right;
    succ = InOrderSuccessor(root,temp);
    if(succ != NULL){
        printf("Inorder Successor of %d is %d",temp->data,succ->data);
    }
    else{
        printf("Inorder Successor doesn't exist");
    }
    return 0;
}