#include <stdio.h>
#include <string.h>

void push(int st[], int *top, int v)
{
    st[++(*top)] = v;
}

void pop(int st[], int *top)
{
    (*top)--;
}
void display(int st[], int top)
{
    while (top != -1)
    {
        printf("%d ", st[top]);
        top--;
    }
    printf("\n");
}

int main()
{
    int size;
    printf("enter the size of array\n");
    scanf("%d", &size);
    int arr[size];
    int st[size], st1[size];
    int top, top1, n, i = 0, j = size - 1;
    top = top1 = -1;
    printf("enter the no. of the operation you want to perform\n");
    printf("1 to push in stack1\n");
    printf("2 to pop from stack1\n");
    printf("3 to push in stack2\n");
    printf("4 to pop from stack2\n");
    printf("5 to exit\n");
    while (n != 5)
    {
        scanf("%d", &n);
        if (i == j)
        {
            printf("array is full");
            break;
        }
        switch (n)
        {
        case 1:
            scanf("%d", &arr[i]);
            int v = arr[i];
            push(st, &top, v);
            i++;
            break;
        case 2:
            pop(st, &top);
            i--;
            break;
        case 3:
            scanf("%d", &arr[j]);
            v = arr[j];
            push(st1, &top1, v);
            j--;
            break;
        case 4:
            pop(st1, &top1);
            j++;
            break;
        case 5:
            printf("stack1 :- ");
            display(st, top);
            printf("\n stack2 : - ");
            display(st1, top1);
            break;
        default:
            printf("wrong input\nRe-enter\n");
            break;
        }
    }
}