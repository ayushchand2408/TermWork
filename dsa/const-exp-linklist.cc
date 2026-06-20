#include<iostream>

using namespace std;

struct node {
    int con;
    int exp;
    struct node *next;
};
typedef struct node node;

void insert(node** head, int v1, int v2) {
    node *temp = (node*)malloc(sizeof(node));
    temp->con = v1;
    temp->exp = v2;
    temp->next = NULL;
    if (*head == NULL) {
        *head = temp;
    } else {
        temp->next = *head;
        *head = temp;
    }
}

void createnode(node** head, int con, int exp) {
    node *temp = (node*)malloc(sizeof(node));
    temp->con = con;
    temp->exp = exp;
    temp->next = *head;
    *head = temp;
}

void add(node *head1, node *head2, node** head3) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->exp > head2->exp) {
            createnode(head3, head1->con, head1->exp);
            head1 = head1->next;
        } else if (head1->exp < head2->exp) {
            createnode(head3, head2->con, head2->exp);
            head2 = head2->next;
        } else {
            createnode(head3, head1->con + head2->con, head1->exp);
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    while (head1 != NULL) {
        createnode(head3, head1->con, head1->exp);
        head1 = head1->next;
    }
    while (head2 != NULL) {
        createnode(head3, head2->con, head2->exp);
        head2 = head2->next;
    }
}

void display(node* head) {
    while (head != NULL) {
        cout << head->con<<"x^" <<  head->exp << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    node* head1 = NULL;
    node* head2 = NULL;
    node* head3 = NULL;
    insert(&head1, 3, 3);
    insert(&head1, 2, 2);
    insert(&head1, 1, 1);
    insert(&head1, -4, 0);
    
    insert(&head2, 2, 2);
    insert(&head2, 3, 1);
    insert(&head2, 1, 0);
    
    

    add(head1, head2, &head3);

    display(head3);

    return 0;
}
