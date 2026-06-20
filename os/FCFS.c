#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <limits.h>

typedef struct { int pid, arrival, burst, completion, tat, wt; } P;
int main() {
    int n;
    printf("FCFS: Enter number of processes: ");
    if (scanf("%d", &n)!=1) return 0;
    P p[n];
    for (int i=0;i<n;i++)
    { 
        p[i].pid=i+1; 
        printf("P%d - arrival burst: ", i+1); 
        scanf("%d %d",&p[i].arrival,&p[i].burst);
    }
    // sort by arrival
    for (int i=0;i<n-1;i++) 
        for (int j=i+1;j<n;j++)
            if (p[i].arrival > p[j].arrival) 
            { 
                P t=p[i]; 
                p[i]=p[j]; 
                p[j]=t; 
            }

    int time=0; 
    double totalWT=0,totalTAT=0;
    printf("Gantt:\n");
    for (int i=0;i<n;i++){
        if (time < p[i].arrival) 
            time = p[i].arrival;
        printf(" | P%d ", p[i].pid);
        time += p[i].burst;
        p[i].completion = time;
        p[i].tat = p[i].completion - p[i].arrival;
        p[i].wt = p[i].tat - p[i].burst;
        totalWT += p[i].wt; 
        totalTAT += p[i].tat;
    }
    printf(" |\nAvg Waiting Time = %.2f\nAvg Turnaround Time = %.2f\n", totalWT/n, totalTAT/n);
    return 0;
}