#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node node;
node *head = NULL;

// Function to create a doubly circular linked list with predefined data
void create_node(int data[], int n) {
    node *newnode, *temp;
    for (int i = 0; i < n; i++) {
        newnode = (node*)malloc(sizeof(node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        newnode->data = data[i];
        if (head == NULL) {
            head = newnode;
            head->next = head;
            head->prev = head;
        } else {
            temp = head->prev;
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = head;
            head->prev = newnode;
        }
    }
}

// Function to display the doubly circular linked list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    printf("\nLinked list elements: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

int main() {
    int data[] = {10, 20, 30, 40, 50};  // Predefined data
    int n = sizeof(data) / sizeof(data[0]);

    create_node(data, n);
    printf("Doubly Circular Linked List:");
    display();

    return 0;
}
