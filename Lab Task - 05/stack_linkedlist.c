#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int data;
    struct Stack* top;
};

void push(struct Stack**head_ref,int new_data){
    struct Stack* new_node = (struct Stack*)malloc(sizeof(struct Stack));
    if(new_node == NULL){
        printf("Not able to push the element\n");
    }
    else{
        new_node->data = new_data;
        new_node->top = *head_ref;
        *head_ref = new_node;
        printf("Item successfully Pushed!\n");
    }
}

void display(struct Stack* n){
    if(n == NULL){
        printf("Stack is Empty!\n");
    }
    else{
        while(n!= NULL){
            printf(" %d",n->data);
            n = n->top;
        }
    }
}

void pop(struct Stack**head_ref){
    if(*head_ref == NULL){
        printf("Underflow Condition!\n");
    }
    else{
        struct Stack* temp = *head_ref;
        *head_ref = temp->top;
        free(temp); 
        printf("Item successfully Popped!\n");
    }
}

int main(){
    struct Stack* head = NULL;
    push(&head,2);
    push(&head,5);
    push(&head,7);
    push(&head,10);
    display(head);
    printf("\n");
    pop(&head);
    display(head);
    return 0;
}