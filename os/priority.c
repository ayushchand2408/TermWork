#include<stdio.h>
#include<limits.h>
typedef struct { int pid, arrival, burst, priority, completion, tat, wt, done; } PR;
int main() {
    int n; 
    printf("Priority NP: Enter number of processes: "); 
    if (scanf("%d",&n)!=1) return 0;
    PR p[n];
    for (int i=0;i<n;i++)
    { 
        p[i].pid=i+1; 
        printf("P%d - arrival burst priority: ",i+1); 
        scanf("%d %d %d",&p[i].arrival,&p[i].burst,&p[i].priority); 
        p[i].done=0;
    }
    int completed=0,time=0; 
    double totalWT=0,totalTAT=0;
    printf("Gantt:\n");
    while (completed < n) {
        int idx=-1, maxpr=INT_MIN;
        for (int i=0;i<n;i++) 
            if (!p[i].done && p[i].arrival<=time && p[i].priority>maxpr) 
            { 
                maxpr=p[i].priority; 
                idx=i; 
            }
        if (idx==-1) 
        { 
            time++; 
            continue; 
        }
        printf(" | P%d ", p[idx].pid);
        time += p[idx].burst; 
        p[idx].completion=time; 
        p[idx].tat=p[idx].completion-p[idx].arrival; 
        p[idx].wt=p[idx].tat-p[idx].burst;
        totalWT+=p[idx].wt; 
        totalTAT+=p[idx].tat; 
        p[idx].done=1; 
        completed++;
    }
    printf(" |\nAvg WT=%.2f\nAvg TAT=%.2f\n", totalWT/n, totalTAT/n);
    return 0;
}