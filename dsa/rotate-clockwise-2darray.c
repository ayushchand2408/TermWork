//Given a matrix of size n X n containing positive integers, write an algorithm and a program to
//rotate the elements of matrix in clockwise direction.
#include <stdio.h>
void rotateClockwise(int n, int matrix[][n])
{
    if (n <= 1)
        return;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    while (top < bottom && left < right)
    {
        int prev = matrix[top + 1][left];
        for (int i = left; i <= right; i++)
        {
            int curr = matrix[top][i];
            matrix[top][i] = prev;
            prev = curr;
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            int curr = matrix[i][right];
            matrix[i][right] = prev;
            prev = curr;
        }
        right--;
        for (int i = right; i >= left; i--)
        {
            int curr = matrix[bottom][i];
            matrix[bottom][i] = prev;
            prev = curr;
        }
        bottom--;
        for (int i = bottom; i >= top; i--)
        {
            int curr = matrix[i][left];
            matrix[i][left] = prev;
            prev = curr;
        }
        left++;
    }
}

void printMatrix(int n, int matrix[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n][n];
    printf("Enter the elements of array: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    rotateClockwise(n, arr);
    printf("Matrix after rotating clockwise: \n");
    printMatrix(n, arr);

    return 0;
}