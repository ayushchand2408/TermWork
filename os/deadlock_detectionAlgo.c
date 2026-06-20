#include<stdio.h>

int main() {
    int n, m;

    printf("Deadlock Detection: Enter number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }
    printf("Enter number of resources: ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Invalid number of resources.\n");
        return 1;
    }

    int alloc[n][m], max[n][m], need[n][m], avail[m];
    int finish[n];

    printf("Enter Allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter Max matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter Available resources:\n");
    for (int j = 0; j < m; j++) {
        scanf("%d", &avail[j]);
    }

    // 1. Calculate the Need matrix and initialize finish array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
        finish[i] = 0; // 0 for false, 1 for true. All processes start as unfinished.
    }

    int work[m];
    for (int j = 0; j < m; j++) {
        work[j] = avail[j];
    }
    
    // 2. Deadlock Detection Algorithm (Safety Algorithm)
    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                
                if (j == m) { // If all needs can be satisfied
                    for (int k = 0; k < m; k++) {
                        work[k] += alloc[i][k];
                    }
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (found == 0) { // No process could be finished in this iteration
            break;
        }
    }

    // 3. Check for Deadlock
    int deadlock = 0;
    printf("Processes in deadlock: ");
    for (int i = 0; i < n; i++) {
        if (finish[i] == 0) {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if (deadlock) {
        printf("\nDeadlock detected.\n");
    } else {
        printf("None\nNo deadlock detected.\n");
    }

    return 0;
}