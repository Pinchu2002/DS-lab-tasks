#include<stdio.h>
#include<stdlib.h>

// linked  list structure
struct node{
    int data;
    struct node* next;
};

// reverse linked list

void reverse(struct node** head_ref){
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void push(struct node** head_ref, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

void printlist(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){

    struct node* head = NULL;
    push(&head, 5);
    push(&head, 2);
    push(&head, 4);
    push(&head, 6);

    printf("Before reversing list: ");
    printlist(head);

    reverse(&head);
    printf("\nAfter reversing list: ");
    printlist(head);
    return 0;
}