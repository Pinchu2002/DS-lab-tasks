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

int search_element(struct node* head, int data){
    int ans = -1;
    struct node* temp = head;
    while(temp != NULL){
        if(temp->data == data){
            ans = 1;
            break;
        }
        temp = temp->next;
    }
    return ans;
}

int main(){

    struct node* head = NULL;
    push(&head, 5);
    push(&head, 2);
    push(&head, 4);
    push(&head, 6);

    printf("Given Linked List: ");
    printlist(head);

    int data;
    printf("\nEnter element you want to search: ");
    scanf("%d",&data);
    if(search_element(head,data) == 1){
        printf("Given Element exist in Linked list");
    }
    else{
        printf("Does not exist");
    }


    return 0;
}

