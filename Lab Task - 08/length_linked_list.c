#include<stdio.h>
#include<stdlib.h>

// linked  list structure
struct node{
    int data;
    struct node* next;
};

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

int findLenght(struct node* head){
    int count = 0;
    struct node* current = head;
    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

int main(){

    struct node* head = NULL;
    push(&head, 5);
    push(&head, 2);
    push(&head, 4);
    push(&head, 6);

    printf("Given Linked List: ");
    printlist(head);
    printf("\nLenght of given Linked List : %d",findLenght(head));
    return 0;
}

