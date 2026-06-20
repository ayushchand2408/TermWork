#include <stdio.h>
#include <string.h>

void push(char st[], int *top, char v) {
    st[++(*top)] = v; 
}

void display(char st[], int top) {
    if (top == -1) {
        printf("\n");
        return;
    }
    printf("%c", st[top]);
    display(st, top - 1);
}

void reverseString(char str[], int index, int *top, char st[]) {
    if (index == strlen(str)) {
        display(st, *top);
        return;
    }
    push(st, top, str[index]);
    reverseString(str, index + 1, top, st);
}

int main() {
    char str[200];
    int top = -1;
    char st[200];
    
    printf("Enter the value of string: ");
    scanf("%s", str);
    
    reverseString(str, 0, &top, st);
    
    return 0;
}
