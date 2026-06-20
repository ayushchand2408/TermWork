#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char st[], int *top, char v) {
    st[++(*top)] = v; 
}

void display(char st[], int top) {
    while (top != -1) {
        printf("%c", st[top]);
        top--;
    }
    printf("\n");
}

int main() {
    char str[200];
    int top = -1;
    char st[200];
    printf("enter the value of string\n");
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0; i < n ; i++) {
        char v = str[i];
        push(st, &top, v);
    }
    display(st, top);

    return 0;
}
