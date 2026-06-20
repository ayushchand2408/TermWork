#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} node;
typedef struct queue {
    struct node *front, *rear;
} queue;
queue* initializeQueue() {
    queue *q = (queue*)malloc(sizeof(queue));
    q->rear = q->front = NULL;
    return q;
}
node* create_node(int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->info = value;
    temp->next = NULL;
    return temp;
}
void enqueue(queue *q, int value) {
    node *temp = create_node(value);
    if (!temp) {
        printf("Not sufficient memory");
    } else if (q->front == NULL && q->rear == NULL) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}
int dequeue(queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int value = q->front->info;
        node *temp = q->front;
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
        return value;
    }
}
void display(queue *q) {
    node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}
int size(queue *q) {
    int count = 0;
    node* temp = q->front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int main() {
    queue* q = initializeQueue();
    int choice, data;
    printf("Press:\n1 to enqueue\n2 to dequeue\n3 to calculate size\n4 to exit\n");
    while (1) {
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &data);
                enqueue(q, data);
                display(q);
                break;

            case 2:
                printf("Dequeued value: %d\n", dequeue(q));
                display(q);
                break;

            case 3:
                printf("Size of queue: %d\n", size(q));
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
