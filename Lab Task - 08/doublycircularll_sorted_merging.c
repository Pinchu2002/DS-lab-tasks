#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;
} Node;

void add(Node **tail, int x) {
    Node* new = malloc(sizeof(Node));
    new->data = x;
    new->prev = *tail;
    new->next = NULL;
    if (*tail != NULL) {
        (*tail)->next = new;
    }
    *tail = new;//if linked list is
}

void makeNonCircular(Node *head) {
    head->prev->next = NULL;
    head->prev = NULL;
}

void makeCircular(Node *head, Node *tail) {
    tail->next = head;
    head->prev = tail;
}

Node* getList() {
    int n;
    printf("Enter size of list: ");
    scanf("%d", &n);
    Node* head = NULL;
    Node* tail = NULL;
    printf("Enter elements of the list:\n");
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        add(&tail, x);
        if (i == 0) {
            head = tail;
        }
    }
    makeCircular(head, tail);
    return head;
}


Node* mergeLists(Node *l1, Node *l2) {
    Node *head = NULL, *tail = NULL, *h1 = l1, *h2 = l2, *t1 = l1->prev, *t2 = l2->prev;
    makeNonCircular(l1);
    makeNonCircular(l2);
    while (l1 != NULL || l2 != NULL) {
        if (l2 == NULL || (l1 != NULL && l1->data < l2->data)) {
            add(&tail, l1->data);
            if (tail->prev == NULL) {
                head = tail;
            }
            l1 = l1->next;
        } else {
            add(&tail, l2->data);
            if (tail->prev == NULL) {
                head = tail;
            }
            l2 = l2->next;
        }
    }
    makeCircular(h1, t1);
    makeCircular(h2, t2);
    makeCircular(head, tail);
    return head;
}

void freeList(Node *head) {
    makeNonCircular(head);
    while(head != NULL) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

void printList(Node *head) {
    Node *tail = head->prev;
    makeNonCircular(head);
    Node *node = head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    makeCircular(head, tail);
}

int main() {
    printf("For list 1:\n");
    Node *l1 = getList();
    printf("For list 2:\n");
    Node *l2 = getList();
    Node *l3 = mergeLists(l1, l2);
    printf("The merged list is: ");
    printList(l3);
    freeList(l1);
    freeList(l2);
    freeList(l3);
}