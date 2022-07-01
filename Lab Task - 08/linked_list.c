#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void display(struct Node* n){
    while(n!= NULL){
        printf(" %d ",n->data);
        n = n->next;
    }
}

void push(struct Node**head_ref,int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

//void insertAfter(struct Node* prev_node,int new_data){
//    if(prev_node == NULL){
//        printf("enter a valid prev_node");
//        return;
//    }
//    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
//    new_node->data = new_data;
//    new_node->next = prev_node->next;
//    prev_node->next = new_node;
//}

void pop(struct Node**head_ref,int key){
   struct Node* temp = *head_ref,*prev;
   if(temp != NULL && temp->data == key){
       *head_ref = temp->next;
        free(temp);
        return;
   }
   while(temp != NULL && temp->data != key){
       prev = temp;
       temp = temp->next;
   }
   if(temp == NULL){
       printf("Underflow Condition!");
       return;
   }
   prev->next = temp->next;
   free(temp);
}

//void append(struct Node**head_ref,int new_data){
//    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
//    struct Node* last = *head_ref;
//
//    new_node->data = new_data;
//    new_node->next = NULL;
//
//    if(*head_ref == NULL){
//        *head_ref = new_node;
//        return;
//    }
//    while (last->next != NULL){
//        last = last->next;
//    }
//
//    last->next = new_node;
//    return;
//}

void reverse(struct Node** head_ref){
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int findLenght(struct Node* head){
    int count = 0;
    struct Node* current = head;
    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

int main (){
    struct  Node* head = NULL;
    // struct  Node* second = NULL;
    // struct  Node* third = NULL;

    // creating simple linked list 
    // head = (struct Node*)malloc(sizeof(struct Node));
    // second = (struct Node*)malloc(sizeof(struct Node));
    // third = (struct Node*)malloc(sizeof(struct Node));
    
    // head->data = 1;
    // head->next = second;

    // second->data = 2;
    // second->next = third;

    // third->data = 3;
    // third->next = NULL;


    //append(&head,3);
    push(&head,1);
    push(&head,10);
    //append(&head,2);
    //insertAfter(head->next,8);
    push(&head,5);
    push(&head,6);
    //display(head);
    //printf("\n");
    //pop(&head,5);
    display(head);

    reverse(&head);
    display(head);
    return 0;
}