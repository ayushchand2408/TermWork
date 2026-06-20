#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void createNode(node **head, int data) {
    node *newNode = (node *)malloc(sizeof(node));   

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next   = *head;
    *head = newNode;
}

void insertFront(node **head, int data) {
    createNode(head, data);
}

void insertEnd(node **head, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next   
 = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;   

    }
}

void insertAnywhere(node **head, int pos, int data) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        insertFront(head, data);
        return;
    }

    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    node*temp = *head;
    for (int i = 0; i < pos - 2; i++) {
        if (temp == NULL) {
            printf("Invalid position.\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFront(node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteEnd(node   
 **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    node *temp = *head;
    while (temp->next->next   
 != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;   

}

void deleteAnywhere(node **head, int pos) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        deleteFront(head);
        return;
    }

    node *temp = *head;
    for (int i = 0; i < pos - 2; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position.\n");
            return;
        }
        temp = temp->next;
    }

    node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

int size(node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int isEmpty(node *head) {
    return head == NULL;
}

int findMiddle(node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return -1;
    }

    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

void display(node *head)   
 {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;

    int choice;
    printf("0. Exit\n");
    printf("1. Create linked list\n");
    printf("2. Insert at the beginning\n");
    printf("3. Insert at the end\n");
    printf("4. Insert at a given position\n");
    printf("5. Delete from the beginning\n");
    printf("6. Delete from the end\n");
    printf("7. Delete from a given position\n");
    printf("8. Size of the linked list\n");
    printf("9. Check if the list is empty\n");
    printf("10. Find the middle element\n");
    printf("11. Display the list\n");

    while (choice != 0){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                createNode(&head, data);
                break;
            }
            case 2: {
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                insertFront(&head, data);
                break;
            }
            case 3: {
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            }
            case 4: {
                int pos, data;
                printf("Enter position and data: ");
                scanf("%d %d", &pos, &data);
                insertAnywhere(&head, pos, data);
                break;
            }
            case 5: {
                deleteFront(&head);
                break;
            }
            case 6: {
                deleteEnd(&head);
                break;
            }
            case 7: {
                int pos;
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAnywhere(&head, pos);
                break;
            }
            case 8: {
                printf("Size of the linked list: %d\n", size(head));
                break;
            }
            case 9: {
                if (isEmpty(head)) {
                    printf("List is empty.\n");
                } else {
                    printf("List is not empty.\n");
                }
                break;
            }
            case 10: {
                int middle = findMiddle(head);
                if (middle != -1) {
                    printf("Middle element: %d\n", middle);
                }
                break;
            }
            case 11: {
                display(head);
                break;
            }
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } 

    return 0;
}