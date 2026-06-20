#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


#include <limits.h>
typedef struct { int pid, arrival, burst, completion, tat, wt; int done; } PN;
int main() {
    int n; printf("SJF NP: Enter number of processes: "); if (scanf("%d",&n)!=1) return 0;
    PN p[n];
    for (int i=0;i<n;i++)
    { 
        p[i].pid=i+1; 
        printf("P%d - arrival burst: ", i+1); 
        scanf("%d %d",&p[i].arrival,&p[i].burst); 
        p[i].done=0;
    }
    int completed=0,time=0; double totalWT=0,totalTAT=0;
    printf("Gantt:\n");
    while (completed < n) {
        int idx=-1, minb=INT_MAX;
        for (int i=0;i<n;i++) 
        if (!p[i].done && p[i].arrival<=time && p[i].burst<minb) 
        { 
            minb=p[i].burst; 
            idx=i;
        }
        if (idx==-1) 
        { 
            time++; 
            continue;
        }
        printf(" | P%d ", p[idx].pid);
        time += p[idx].burst;
        p[idx].completion = time; 
        p[idx].tat = p[idx].completion - p[idx].arrival; 
        p[idx].wt = p[idx].tat - p[idx].burst;
        totalWT += p[idx].wt; 
        totalTAT += p[idx].tat; 
        p[idx].done=1; completed++;
    }
    for(int i =0 ; i < n ; i++){
        printf("\nTAT Process %d : %d  WT Process %d : %d\n " , i , p[i].tat , i , p[i].wt);
        
    }
    printf(" |\nAvg WT=%.2f\nAvg TAT=%.2f\n", totalWT/n, totalTAT/n);
    return 0;
}