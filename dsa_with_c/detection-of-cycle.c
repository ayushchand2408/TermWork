#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;
node *head = NULL;

void create_node(int data[], int n) {
    node *newnode, *temp;
    for (int i = 0; i < n; i++) {
        newnode = (node*)malloc(sizeof(node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        newnode->data = data[i];
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

void create_cycle() {
    if (head == NULL) return;
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head->next; 
}

int detect_cycle() {
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    int data[] = {10, 20, 30, 40, 50};
    int n = sizeof(data) / sizeof(data[0]);

    create_node(data, n);
    create_cycle(); 

    if (detect_cycle()) {
        printf("Cycle detected in the linked list.\n");
    } else {
        printf("No cycle detected in the linked list.\n");
    }

    return 0;
}
