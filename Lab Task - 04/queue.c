//
// Created by lenovo on 13-05-2022.
//

#include<stdio.h>
#include<stdlib.h>

#define MAX_INT 10

// creating a queue using array
int queue[MAX_INT],front = -1,rear = -1;

void push(int value){
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = value;
        printf("Insertion Success for the first element!\n");
    }
    else if(rear == MAX_INT - 1) printf("Queue is Full!(Overflow Condition)\n");
    else{
        rear++;
        queue[rear] = value;
        printf("Insertion Success!\n");
    }
}

void pop(){
    if(front == -1) printf("Queue is empty!(Underflow Condition)\n");
    else{
        printf("\n Deleted %d\n",queue[front]);
        front++;
    }
}

void display(){
    if(front == -1){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements are: \n");
        for(int i = front; i <= rear; i++){
            printf("%d\n",queue[i]);
        }
    }
}

void peek(){
    printf("Top of Queue : %d\n",rear);
}


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
