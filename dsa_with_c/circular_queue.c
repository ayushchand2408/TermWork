#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front, rear, size;
    int* queue;
} CircularQueue;

CircularQueue* Create(int size) {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->front = q->rear = -1;
    q->size = size;
    q->queue = (int*)malloc(size * sizeof(int));
    return q;
}

void EnQueue(CircularQueue* q, int value) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is Full\n");
        return;
    } else if (q->front == -1) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }
    q->queue[q->rear] = value;
}

int DeQueue(CircularQueue* q) {
    if (q->front == -1) {
        printf("Queue is Empty\n");
        return -1;
    }
    int data = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return data;
}

int IsEmpty(CircularQueue* q) {
    return q->front == -1;
}

int Front(CircularQueue* q) {
    if (IsEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->queue[q->front];
}

int Rear(CircularQueue* q) {
    if (IsEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->queue[q->rear];
}

void DisplayQueue(CircularQueue* q) {
    if (IsEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    int i = q->front;
    while (1) {
        printf("%d ", q->queue[i]);
        if (i == q->rear) break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main() {
    int size, choice, value;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    CircularQueue* q = Create(size);
    printf("\n1. EnQueue\n2. DeQueue\n3. Front\n4. Rear\n5. exit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &value);
                EnQueue(q, value);
                DisplayQueue(q);
                break;
            case 2:
                printf("Dequeued value: %d\n", DeQueue(q));
                break;
            case 3:
                printf("Front value: %d\n", Front(q));
                break;
            case 4:
                printf("Rear value: %d\n", Rear(q));
                break;
            case 5:
                free(q->queue);
                free(q);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

