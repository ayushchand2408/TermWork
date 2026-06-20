#include<stdio.h>

typedef struct { int pid, arrival, burst, rem, completion, tat, wt; } RR;
int main() {
    int n, tq=2; 
    printf("Round Robin: Enter number of processes: "); 
    if (scanf("%d",&n)!=1) return 0;
    RR p[n];
    for (int i=0;i<n;i++)
    { 
        p[i].pid=i+1; 
        printf("P%d - arrival burst: ", i+1); 
        scanf("%d %d",&p[i].arrival,&p[i].burst); 
        p[i].rem=p[i].burst;
    }
    int completed=0,time=0; double totalWT=0,totalTAT=0;
    printf("Gantt:\n");
    while (completed < n) {
        int executed=0;
        for (int i=0;i<n;i++) {
            if (p[i].rem>0 && p[i].arrival<=time) {
                executed=1;
                printf(" | P%d ", p[i].pid);
                if (p[i].rem<=tq) {
                    time += p[i].rem; 
                    p[i].rem=0; 
                    p[i].completion=time; 
                    p[i].tat=p[i].completion-p[i].arrival; 
                    p[i].wt=p[i].tat-p[i].burst; 
                    totalWT+=p[i].wt; 
                    totalTAT+=p[i].tat; 
                    completed++;
                } else {
                    time += tq; 
                    p[i].rem -= tq;
                }
            }
        }
        if (!executed) time++;
    }
    printf(" |\nAvg WT=%.2f\nAvg TAT=%.2f\n", totalWT/n, totalTAT/n);
    return 0;
}