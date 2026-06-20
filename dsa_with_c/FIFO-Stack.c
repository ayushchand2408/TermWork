#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void push(node** top, int data) {
    node* temp = (node*)malloc(sizeof(node));
    if (!temp) {
        printf("Heap Overflow\n");
        exit(1);
    }
    temp->data = data;
    temp->next = *top;
    *top = temp;
}

int pop(node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    node* temp = *top;
    *top = (*top)->next;
    int data = temp->data;
    free(temp);
    return data;
}

void printQueueFromStack(node* top) {
    node* auxStack = NULL;

    while (top != NULL) {
        push(&auxStack, pop(&top));
    }

    while (auxStack != NULL) {
        printf("%d ", pop(&auxStack));
    }
    printf("\n");
}

int main() {
    node* top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    
    printf("Elements in FIFO order: ");
    printQueueFromStack(top);

    return 0;
}
