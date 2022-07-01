#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void push(struct node** head_ref, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = *head_ref;
    if(*head_ref != NULL){
        struct node* temp = *head_ref;
        while(temp->next != *head_ref){
            temp = temp->next;
        }
        temp->next = ptr;
    }
    else{
        ptr->next = ptr;
    }
    *head_ref = ptr;
}

void printList(struct node* head)
{
    struct node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
 
    printf("\n");
}

struct node* circular(struct node* head){
    struct node* start = head;
    while(start->next != NULL){
        start = start->next;
    }
    start->next = head;
    return start;
}

struct node* noncircular(struct node* head){
    struct node* start = head;
    while(start->next != head){
        start = start->next;
    }
    start->next = NULL;
    return start;
}

void deleteNode(struct node* head,int key){

    struct node *current = head, *prev;
    noncircular(current);
    if(current == NULL){
        circular(current);
        return;
    }
    if(current->next->data == key){
        struct node* temp = current->next;
        current->next = current->next->next;
        free(temp);   
        circular(current);
        return;
    }
    circular(current);
    deleteNode(head->next,key);
    
}

int main(){
    struct node* head = NULL;
    push(&head,5);
    push(&head,2);
    push(&head,3);
    push(&head,6);
    push(&head,7);

    printf("Circular Linked List : ");
    printList(head);
    int d;
    printf("Enter the element you want to delete from given circular linked list: ");
    scanf("%d", &d);

    deleteNode(head,d);

    printf("List After Deletion: ");
    printList(head);

    return 0;
}