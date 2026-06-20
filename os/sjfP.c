#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
typedef struct { int pid, arrival, burst, rem, completion, tat, wt; } PP;
int main() {
    int n; 
    printf("SJF P: Enter number of processes: "); 
    if (scanf("%d",&n)!=1) return 0;
    PP p[n];
    for (int i=0;i<n;i++)
    { 
        p[i].pid=i+1; 
        printf("P%d - arrival burst: ", i+1); 
        scanf("%d %d",&p[i].arrival,&p[i].burst); 
        p[i].rem=p[i].burst;
    }
    int completed=0,time=0; 
    double totalWT=0,totalTAT=0; int prev=-1;
    printf("Gantt:\n");
    while (completed < n) {
        int idx=-1, minr=INT_MAX;
        for (int i=0;i<n;i++) 
            if (p[i].rem>0 && p[i].arrival<=time && p[i].rem<minr) 
            { 
                minr=p[i].rem; 
                idx=i;
            }
        if (idx==-1) { 
            time++; 
            continue; 
        }
        if (prev!=idx) 
        { 
            printf(" | P%d ", p[idx].pid); 
            prev=idx; 
        }
        p[idx].rem--; 
        time++;
        if (p[idx].rem==0) 
        { 
            p[idx].completion=time; 
            p[idx].tat=p[idx].completion-p[idx].arrival; 
            p[idx].wt=p[idx].tat-p[idx].burst; 
            totalWT+=p[idx].wt; 
            totalTAT+=p[idx].tat; 
            completed++; 
        }
    }
    printf(" |\nAvg WT=%.2f\nAvg TAT=%.2f\n", totalWT/n, totalTAT/n);
    return 0;
}