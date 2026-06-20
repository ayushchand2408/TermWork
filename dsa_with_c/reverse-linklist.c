#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node node;
node *head = NULL;

void create_node(int v[], int n) {
    node *newnode, *temp;
    for (int i = 0; i < n; i++) {
        newnode = (node*)malloc(sizeof(node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        newnode->info = v[i];
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void reverse() {
    node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void display() {
    node *temp = head;
    printf("\nLinked list elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int v[] = {10, 20, 30, 40, 50}; 
    int n = sizeof(v) / sizeof(v[0]);

    create_node(v, n);
    printf("Original list:");
    display();
    reverse();
    printf("Reversed list:");
    display();

    return 0;
}
