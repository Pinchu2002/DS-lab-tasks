#include<stdio.h>
#include<stdlib.h>
#define MAX_INT 10

// queue 
int cnt = 0;
int queue[MAX_INT], front = -1, rear = -1;

// queue insertion
void push_queue(int value){
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = value;
    }
    else if(rear == MAX_INT - 1) printf("Queue is Full!\n");
    else{
        rear++;
        queue[rear] = value;
    }
}

// queue display
void display(){
    if(front == -1){
        printf("None\n");
    }
    else{
        for(int i = front; i <= rear; i++){
            printf("%d\n",queue[i]);
        }
    }
}

// sorting queue
// function to swap()
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to bubblesort()
void bubblesort(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

// linked list of Student
struct Student{
    int marks;
    int rollno;
    struct Student* next;
};

// insertion in linked list
void insert_ll(struct Student**head_ref, int marks, int rollno){
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    newNode->marks = marks;
    newNode->rollno = rollno;
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}


void search_fail_stu(struct Student *head){
    struct Student* current = head;
    while(current !=  NULL){
        if(current->marks < 40){
            push_queue(current->rollno);
            cnt++;
        }
        current = current->next;
    }
}

// main function
int main(){
    struct Student* head = NULL;
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    int marks[n];
    int rollno[n];
    printf("\nEnter rollno & DS marks for each student: \n");
    for(int i = 0; i < n; i++){
        scanf("%d %d",&rollno[i],&marks[i]);
    }

    printf("\nGiven rollno & marks are: \n");
    for(int i = 0; i < n; i++){
        printf("%d %d\n",rollno[i],marks[i]);
    }

    for(int i = 0; i < n; i++){
        insert_ll(&head,marks[i],rollno[i]);
    }
    search_fail_stu(head);
    printf("\nRollno of Students who have scored less than 40 marks are: \n");
    bubblesort(queue,cnt);
    display();
    return 0;
}