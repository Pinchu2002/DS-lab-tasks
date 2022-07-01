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

void deleteNode(struct node* head,int key){

    struct node *current = head, *prev;

    // list is empty
    if(current == NULL){
        printf("\nUnderFlow Condition!");
        return;
    }

    // find the required node
  
    while(current->data != key){
        if(current->next == head){
            printf("Given data is not found in the list");
            break;
        }
        prev = current;
        current = current->next;
    }


    // list contains single element
    if(current->next == NULL){
        head = NULL;
        free(current);
        return;
    }

    // if first node
    if(current == head){
        prev = head;
        while(prev->next != head){
            prev = prev->next;
        }

        head = current->next;
        prev->next = head;
        free(current);
    }
    
    else if(current->next == head && current == head){
        prev->next = head;
        free(current);
    }

    else{
        prev->next = current->next;
        free(current);
    }
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