#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
    int ind;
};
typedef struct node node;

void enqueue(node **front, node **rear, int v) {
    node *temp = (node*)malloc(sizeof(node));
    temp->info = v;
    temp->next = NULL;
    temp->ind = (*rear == NULL) ? 0 : (*rear)->ind + 1;

    if (*front == NULL) {
        *front = temp;
        *rear = temp;
    } else {
        (*rear)->next = temp;
        *rear = temp;
    }
}

node* dequeue(node *front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return NULL;
    } else {
        node *temp = front;
        front = front->next;
        temp->next = NULL;
        printf("Element dequeued: %d\n", temp->info);
        free(temp);
        return front;
    }
}

void display(node *front) {
    while (front != NULL) {
        printf("%d ", front->info);
        front = front->next;
    }
    printf("\n");
}

void enqueueInBetween(node **front, node **rear, int v, int i) {
    node *temp = (node*)malloc(sizeof(node));
    temp->info = v;
    temp->next = NULL;
    temp->ind = i;

    if (*front == NULL) {
        printf("List is empty\n");
        free(temp);
        return;
    }

    node *temp1 = *front;
    node *temp2 = NULL;

    while (temp1 != NULL && temp1->ind < i) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if (temp2 == NULL) {
        temp->next = *front;
        *front = temp;
    } else {
        temp2->next = temp;
        temp->next = temp1;
    }
    if (temp1 == NULL) {
        *rear = temp;
    }
    while (temp != NULL) {
        if(temp2 == NULL)
        {
            temp->ind=0;
        }else{
            temp->ind=temp2->ind + 1;
        }
        temp2 = temp;
        temp = temp->next;
    }
}
int main() {
    node *front = NULL;
    node *rear = NULL;
    int val, i;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);
    enqueue(&front, &rear, 50);
    display(front);

    printf("Enter the number you want to enqueue: ");
    scanf("%d", &val);
    printf("Enter the index number in which you want to add: ");
    scanf("%d", &i);

    enqueueInBetween(&front, &rear, val, i);
    display(front);

    return 0;
}
