#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void push(struct node**head_ref,int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
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

void frontbacksplit(struct node* source, struct node** front_ref, struct node** back_ref){
    int len = findLenght(source);
    if(len < 2){
        *front_ref =source;
        *back_ref = NULL;
        return;
    }
    struct node* current = source;
    int mid = (len-1)/2;
    for(int i = 0; i < mid; i++){
        current = current->next;
    }
    *front_ref = source;
    *back_ref = current->next;
    current->next = NULL;
}   

struct node* SortedMerge(struct node* a,struct node* b){
    struct node* result = NULL;
    if(a == NULL){
        return b;
    }
    else if(b == NULL){
        return a;
    }
    if(a->data <= b->data){
        result = a;
        result->next = SortedMerge(a->next,b);
    }
    else{
        result = b;
        result->next = SortedMerge(a,b->next);
    }
    return result;
}

void MergeSort(struct node** head_ref){
    struct node* head = *head_ref;
    struct node* a = NULL;
    struct node* b = NULL;
    if(head == NULL || head->next == NULL){
        return;
    }
    frontbacksplit(head,&a,&b);
    MergeSort(&a);
    MergeSort(&b);

    *head_ref = SortedMerge(a,b);
}

void printList(struct node* head)
{
    struct node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("NULL");
}

int main(void){
    struct node* head = NULL;

    // linked list data - 4 2 5 6 1 
    push(&head,4);
    push(&head,2);
    push(&head,5);
    push(&head,6);
    push(&head,1);

    // Merge sort on linked list
    MergeSort(&head);
    printf("Sorted Linked List: ");
    printList(head);
    return 0;
}