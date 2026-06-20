#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node node;

void insertAtHead(node **head, int v) {
    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    if (*head == NULL) {
        n->next = n;
        *head = n;
        return;
    }
    node *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = n;
    n->next = *head;
    *head = n;
}
void insertAtbt(node **head, int v, int d) {
    node *temp = (node *)malloc(sizeof(node));
    temp->info = v;
    node *current = *head;
    while (current->info != d) {
        current = current->next;
        if (current == *head) {
            printf("Node with value %d not found.\n", d);
            free(temp);
            return;
        }
    }
    temp->next = current->next;
    current->next = temp;
}

void insertAtTail(node **head, int v) {
    if (*head == NULL) {
        insertAtHead(head, v);
        return;
    }
    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    node *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = n;
    n->next = *head;
}

void display(node *head) {
    if (head == NULL) return;
    node *temp = head;
    do {
        printf("%d ", temp->info);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    node *head = NULL;
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);
    insertAtTail(&head, 50);

    display(head);
    int num,data;
    printf("enter the number you want to add:-");
    scanf("%d",&num);

    printf("enter the number after that you wanr to add value");
    scanf("%d",&data);

    insertAtbt(&head,num,data);
    display(head);


    return 0;
}
