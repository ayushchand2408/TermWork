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

node* reverse(node* current) {
    if (current == NULL || current->next == NULL) {
        return current;
    }
    node* rest = reverse(current->next);
    current->next->next = current;
    current->next = NULL;
    return rest;
}
void display(node* head) {
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
    display(head);
    head = reverse(head);
    printf("Reversed list:");
    display(head);

    return 0;
}
