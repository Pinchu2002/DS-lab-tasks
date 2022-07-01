//
// Created by lenovo on 13-05-2022.
//

#include<stdio.h>
#include<stdlib.h>

#define MAX_INT 10

// creating a Stack using array
int stack[MAX_INT],top = -1;

void push(int value){
    if(top == MAX_INT - 1) printf("Stack is Full!(Overflow Condition)\n");
    else{
        top++;
        stack[top] = value;
        printf("Insertion Success!\n");
    }
}

void pop(){
    if(top == -1) printf("Stack is empty!(Underflow Condition)\n");
    else{
        printf("\n Deleted %d\n",stack[top]);
        top--;
    }
}

void display(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements are: \n");
        for(int i = 0; i <= top;i++){
            printf("%d\n",stack[i]);
        }
    }
}

void peek(){
    printf("Top of stack : %d\n",top);
}


int main(){
    int choice,value;
    //clrscr();
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
