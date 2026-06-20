#include <stdio.h>
#include <stdlib.h>

typedef struct Dequeue {
    int front;
    int rear;
    int size;
    int *array;
} Dequeue;

Dequeue* create_queue(int size) {
    Dequeue* q = (Dequeue*)malloc(sizeof(Dequeue));
    q->front = -1;
    q->rear = -1;
    q->size = size;
    q->array = (int*)malloc(size * sizeof(int));
    return q;
}

void enqueueAtLast(Dequeue *q, int val) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    q->array[++(q->rear)] = val;
    if (q->front == -1) {
        q->front = 0;
    }
}

void enqueueAtfirst(Dequeue *q, int val) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    if(q->front > 0)
    {
        q->array[--(q->front)] = val;
        return;
    }
    if (q->front == -1) {
        q->front = 0;
        q->rear = 0;
        q->array[q->front] = val;
    } else {
        for (int i = q->rear; i >= q->front; i--) {
            q->array[i + 1] = q->array[i];
        }
        q->array[q->front] = val;
        q->rear++;
    }
}

void deleteFront(Dequeue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
}

void deleteEnd(Dequeue *q) {
    if (q->rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->rear--;
    }
}

void display(Dequeue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}

int main() {
    int size = 10; // Define the size of the queue
    Dequeue *q = create_queue(size);
    int key = 0, val;

    printf("Press\n1 to insert at front\n2 to insert at end\n3 to delete from front\n4 to delete from end\n5 to exit\n");

    while (key != 5) {
        scanf("%d", &key);
        switch (key) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                enqueueAtfirst(q, val);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                enqueueAtLast(q, val);
                break;
            case 3:
                deleteFront(q);
                break;
            case 4:
                deleteEnd(q);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
        display(q);
    }
    return 0;
}
