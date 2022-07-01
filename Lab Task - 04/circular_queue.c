//
// Created by lenovo on 13-05-2022.
//
    
#include<stdio.h>
#include<stdlib.h>

#define size 10

// creating a Circular queue using array
int queue[size],front = -1,rear = -1;

void push(int value){
    if((front == 0 && rear == size-1)){
        printf("Queue is Full!(Overflow Condition)\n");
    }
    else if(front == -1){
        front = 0;
        rear = 0;
        queue[rear] = value;
        printf("Insertion Success for the first element!\n");
    }
    else if(rear == size - 1 && front != 0) {
        rear = 0;
        queue[rear] = value;
        printf("Insertion Success!\n");
    }
    else{
        rear++;
        queue[rear] = value;
        printf("Insertion Success!\n");
    }
}

void pop(){
    if(front == -1) printf("Queue is empty!(Underflow Condition)\n");
    int data = queue[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else if(front == size-1){
        front = 0;
    }
    else{
        printf("\n Deleted %d\n",data);
        front++;
    }
}

void display(){
    if(front == -1){
        printf("Queue is empty\n");
    }
    printf("Elements of circular queue are: \n");
    if(rear >= front){
        for(int i = front; i <= rear; i++){
            printf("%d\n",queue[i]);
        }
    }
    else{
        for(int i = front; i < size; i++){
            printf("%d\n",queue[i]);
        }
        for(int i = 0; i <= rear; i++){
            printf("%d\n",queue[i]);
        }
       
    }
}

void peek(){
    printf("Top of Queue : %d\n",rear);
}

// void front_pos(){
//     printf("Front of queue: %d\n",front);
// }

int main(){
    int choice,value;
    while(1){
        printf("_______MENU_______");
        printf(("\n1. Push\n"));
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be insert: ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:    
                exit(0);
            default:
                printf("!!Plz Enter Valid Choice(1/2/3/4)!!\n");
        }
    }
    return 0;
}
