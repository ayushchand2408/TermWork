/* all_programs.c
   Contains 19 programs in separate #ifdef blocks.
   Compile with -DPROGn where n is 1..19 to select which program to compile/run.
   Example: gcc all_programs.c -o prog -DPROG1
   For threaded programs: gcc all_programs.c -o prog -DPROG18 -pthread
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#ifdef PROG1
/* PROG1: Create a child process using fork() */
int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child: PID=%d, PPID=%d\n", getpid(), getppid());
    } else {
        printf("Parent: PID=%d, Child PID=%d\n", getpid(), pid);
    }
    return 0;
}
#endif

#ifdef PROG2
/* PROG2: Print process IDs of parent and child using getpid(), getppid() */
int main() {
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }
    if (pid == 0) {
        /* child */
        printf("Child: PID=%d, Parent PID (from child)=%d\n", getpid(), getppid());
    } else {
        /* parent */
        printf("Parent: PID=%d, Child PID (from parent)=%d\n", getpid(), pid);
    }
    return 0;
}
#endif

#ifdef PROG3
/* PROG3: Create child which lists files using execlp("ls", ...). Parent waits. */
#include <sys/wait.h>
int main() {
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }
    if (pid == 0) {
        printf("Child (PID %d): running 'ls -l'\n", getpid());
        execlp("ls", "ls", "-l", NULL);
        perror("execlp failed");
        exit(1);
    } else {
        int status;
        wait(&status);
        printf("Parent (PID %d): child finished with status %d\n", getpid(), WEXITSTATUS(status));
    }
    return 0;
}
#endif

#ifdef PROG4
/* PROG4: Open a directory and list its contents (opendir, readdir, closedir) */
#include <dirent.h>
int main() {
    DIR *dir = opendir(".");
    if (!dir) { perror("opendir"); return 1; }
    struct dirent *entry;
    printf("Contents of current directory:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}
#endif

#ifdef PROG5
/* PROG5: Show working of execlp() by executing ls */
int main() {
    printf("Before execlp()\n");
    if (execlp("ls", "ls", "-l", NULL) == -1) {
        perror("execlp failed");
        return 1;
    }
    printf("After execlp() -- will not print if execlp succeeds\n");
    return 0;
}
#endif

#ifdef PROG6
/* PROG6: Read input details, write to my_details.txt and friend_details.txt, then print matching lines */
#define MAX_LINE 256
int main() {
    char buf[MAX_LINE];
    FILE *f1 = fopen("my_details.txt", "w");
    if (!f1) { perror("my_details.txt"); return 1; }
    printf("Enter your details (type END on a new line to finish):\n");
    while (fgets(buf, sizeof(buf), stdin)) {
        if (strncmp(buf, "END", 3) == 0) break;
        fputs(buf, f1);
    }
    fclose(f1);

    FILE *f2 = fopen("friend_details.txt", "w");
    if (!f2) { perror("friend_details.txt"); return 1; }
    printf("Enter friend's details (type END on a new line to finish):\n");
    while (fgets(buf, sizeof(buf), stdin)) {
        if (strncmp(buf, "END", 3) == 0) break;
        fputs(buf, f2);
    }
    fclose(f2);

    f1 = fopen("my_details.txt", "r");
    f2 = fopen("friend_details.txt", "r");
    if (!f1 || !f2) { perror("reopen files"); return 1; }

    char line1[MAX_LINE], line2[MAX_LINE];
    printf("Matching lines:\n");
    while (fgets(line1, sizeof(line1), f1) != NULL) {
        rewind(f2);
        while (fgets(line2, sizeof(line2), f2) != NULL) {
            if (strcmp(line1, line2) == 0) {
                printf("%s", line1);
            }
        }
    }
    fclose(f1); fclose(f2);
    return 0;
}
#endif

#ifdef PROG7
/* PROG7: FCFS scheduling (Gantt + avg waiting + avg turnaround) */
typedef struct { int pid, arrival, burst, completion, tat, wt; } P;
int main() {
    int n;
    printf("FCFS: Enter number of processes: ");
    if (scanf("%d", &n)!=1) return 0;
    P p[n];
    for (int i=0;i<n;i++){ p[i].pid=i+1; printf("P%d - arrival burst: ", i+1); scanf("%d %d",&p[i].arrival,&p[i].burst);}
    // sort by arrival
    for (int i=0;i<n-1;i++) for (int j=i+1;j<n;j++)
        if (p[i].arrival > p[j].arrival) { P t=p[i]; p[i]=p[j]; p[j]=t; }
    int time=0; double totalWT=0,totalTAT=0;
    printf("Gantt:\n");
    for (int i=0;i<n;i++){
        if (time < p[i].arrival) time = p[i].arrival;
        printf(" | P%d ", p[i].pid);
        time += p[i].burst;
        p[i].completion = time;
        p[i].tat = p[i].completion - p[i].arrival;
        p[i].wt = p[i].tat - p[i].burst;
        totalWT += p[i].wt; totalTAT += p[i].tat;
    }
    printf(" |\nAvg Waiting Time = %.2f\nAvg Turnaround Time = %.2f\n", totalWT/n, totalTAT/n);
    return 0;
}
#endif

#ifdef PROG8
/* PROG8: SJF Non-Preemptive */
#include <limits.h>
typedef struct { int pid, arrival, burst, completion, tat, wt; int done; } PN;
int main() {
    int n; printf("SJF NP: Enter number of processes: "); if (scanf("%d",&n)!=1) return 0;
    PN p[n];
    for (int i=0;i<n;i++){ p[i].pid=i+1; printf("P%d - arrival burst: ", i+1); scanf("%d %d",&p[i].arrival,&p[i].burst); p[i].done=0;}
    int completed=0,time=0; double totalWT=0,totalTAT=0;
    printf("Gantt:\n");
    while (completed < n) {
        int idx=-1, minb=INT_MAX;
        for (int i=0;i<n;i++) if (!p[i].done && p[i].arrival<=time && p[i].burst<minb) { minb=p[i].burst; idx=i;}
        if (idx==-1) { time++; continue;}
        printf(" | P%d ", p[idx].pid);
        time += p[idx].burst;
        p[idx].completion = time; p[idx].tat = p[idx].completion - p[idx].arrival; p[idx].wt = p[idx].tat - p[idx].burst;
        totalWT += p[idx].wt; totalTAT += p[idx].tat; p[idx].done=1; completed++;
    }
    printf(" |\nAvg WT=%.2f\nAvg TAT=%.2f\n", totalWT/n, totalTAT/n);
    return 0;
}
#endif

#ifdef PROG9
/* PROG9: SJF Preemptive (SRTF) */
#include <limits.h>
typedef struct { int pid, arrival, burst, rem, completion, tat, wt; } PP;
int main() {
    int n; printf("SJF P: Enter number of processes: "); if (scanf("%d",&n)!=1) return 0;
    PP p[n];
    for (int i=0;i<n;i++){ p[i].pid=i+1; printf("P%d - arrival burst: ", i+1); scanf("%d %d",&p[i].arrival,&p[i].burst); p[i].rem=p[i].burst;}
    int completed=0,time=0; double totalWT=0,totalTAT=0; int prev=-1;
    printf("Gantt:\n");
    while (completed < n) {
        int idx=-1, minr=INT_MAX;
        for (int i=0;i<n;i++) if (p[i].rem>0 && p[i].arrival<=time && p[i].rem<minr) { minr=p[i].rem; idx=i;}
        if (idx==-1) { time++; continue; }
        if (prev!=idx) { printf(" | P%d ", p[idx].pid); prev=idx; }
        p[idx].rem--; time++;
        if (p[idx].rem==0) { p[idx].completion=time; p[idx].tat=p[idx].completion-p[idx].arrival; p[idx].wt=p[idx].tat-p[idx].burst; totalWT+=p[idx].wt; totalTAT+=p[idx].tat; completed++; }
    }
    printf(" |\nAvg WT=%.2f\nAvg TAT=%.2f\n", totalWT/n, totalTAT/n);
    return 0;
}
#endif

#ifdef PROG10
/* PROG10: Priority Scheduling (Non-preemptive). Higher number -> higher priority */
#include <limits.h>
typedef struct { int pid, arrival, burst, priority, completion, tat, wt, done; } PR;
int main() {
    int n; printf("Priority NP: Enter number of processes: "); if (scanf("%d",&n)!=1) return 0;
    PR p[n];
    for (int i=0;i<n;i++){ p[i].pid=i+1; printf("P%d - arrival burst priority: ",i+1); scanf("%d %d %d",&p[i].arrival,&p[i].burst,&p[i].priority); p[i].done=0;}
    int completed=0,time=0; double totalWT=0,totalTAT=0;
    printf("Gantt:\n");
    while (completed < n) {
        int idx=-1, maxpr=INT_MIN;
        for (int i=0;i<n;i++) if (!p[i].done && p[i].arrival<=time && p[i].priority>maxpr) { maxpr=p[i].priority; idx=i; }
        if (idx==-1) { time++; continue; }
        printf(" | P%d ", p[idx].pid);
        time += p[idx].burst; p[idx].completion=time; p[idx].tat=p[idx].completion-p[idx].arrival; p[idx].wt=p[idx].tat-p[idx].burst;
        totalWT+=p[idx].wt; totalTAT+=p[idx].tat; p[idx].done=1; completed++;
    }
    printf(" |\nAvg WT=%.2f\nAvg TAT=%.2f\n", totalWT/n, totalTAT/n);
    return 0;
}
#endif

#ifdef PROG11
/* PROG11: Round Robin (quantum = 2) */
typedef struct { int pid, arrival, burst, rem, completion, tat, wt; } RR;
int main() {
    int n, tq=2; printf("Round Robin: Enter number of processes: "); if (scanf("%d",&n)!=1) return 0;
    RR p[n];
    for (int i=0;i<n;i++){ p[i].pid=i+1; printf("P%d - arrival burst: ", i+1); scanf("%d %d",&p[i].arrival,&p[i].burst); p[i].rem=p[i].burst;}
    int completed=0,time=0; double totalWT=0,totalTAT=0;
    printf("Gantt:\n");
    while (completed < n) {
        int executed=0;
        for (int i=0;i<n;i++) {
            if (p[i].rem>0 && p[i].arrival<=time) {
                executed=1;
                printf(" | P%d ", p[i].pid);
                if (p[i].rem<=tq) {
                    time += p[i].rem; p[i].rem=0; p[i].completion=time; p[i].tat=p[i].completion-p[i].arrival; p[i].wt=p[i].tat-p[i].burst; totalWT+=p[i].wt; totalTAT+=p[i].tat; completed++;
                } else {
                    time += tq; p[i].rem -= tq;
                }
            }
        }
        if (!executed) time++;
    }
    printf(" |\nAvg WT=%.2f\nAvg TAT=%.2f\n", totalWT/n, totalTAT/n);
    return 0;
}
#endif

#ifdef PROG12
/* PROG12: Multi-level queue (system higher priority than user). FCFS inside each queue. */
typedef struct { int pid, arrival, burst; char type[16]; int completion, tat, wt; } MQ;
int main() {
    int n; printf("MLQ: Enter number of processes: "); if (scanf("%d",&n)!=1) return 0;
    MQ p[n];
    for (int i=0;i<n;i++){ p[i].pid=i+1; printf("P%d - arrival burst type(system/user): ", i+1); scanf("%d %d %s",&p[i].arrival,&p[i].burst,p[i].type); }
    // separate
    MQ sys[n]; MQ usr[n]; int sc=0, uc=0;
    for (int i=0;i<n;i++) if (strcmp(p[i].type,"system")==0) sys[sc++]=p[i]; else usr[uc++]=p[i];
    // sort by arrival
    for (int i=0;i<sc-1;i++) for (int j=i+1;j<sc;j++) if (sys[i].arrival>sys[j].arrival){ MQ t=sys[i]; sys[i]=sys[j]; sys[j]=t;}
    for (int i=0;i<uc-1;i++) for (int j=i+1;j<uc;j++) if (usr[i].arrival>usr[j].arrival){ MQ t=usr[i]; usr[i]=usr[j]; usr[j]=t;}
    int time=0; double totalWT=0,totalTAT=0;
    printf("Gantt:\n");
    for (int i=0;i<sc;i++) { if (time<sys[i].arrival) time=sys[i].arrival; printf(" | P%d(system) ", sys[i].pid); time += sys[i].burst; sys[i].completion=time; sys[i].tat=sys[i].completion-sys[i].arrival; sys[i].wt=sys[i].tat-sys[i].burst; totalWT+=sys[i].wt; totalTAT+=sys[i].tat; }
    for (int i=0;i<uc;i++) { if (time<usr[i].arrival) time=usr[i].arrival; printf(" | P%d(user) ", usr[i].pid); time += usr[i].burst; usr[i].completion=time; usr[i].tat=usr[i].completion-usr[i].arrival; usr[i].wt=usr[i].tat-usr[i].burst; totalWT+=usr[i].wt; totalTAT+=usr[i].tat; }
    printf(" |\nAvg WT=%.2f\nAvg TAT=%.2f\n", totalWT/n, totalTAT/n);
    return 0;
}
#endif

#ifdef PROG13
/* PROG13: Banker's Algorithm (safety algorithm) */
int main() {
    int n,m;
    printf("Banker: Enter number of processes: "); if (scanf("%d",&n)!=1) return 0;
    printf("Enter number of resources: "); scanf("%d",&m);
    int alloc[n][m], max[n][m], need[n][m], avail[m], work[m], finish[n], safeSeq[n];
    printf("Enter allocation matrix (%d x %d):\n", n, m);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&alloc[i][j]);
    printf("Enter max matrix (%d x %d):\n", n, m);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&max[i][j]);
    printf("Enter available (%d): ", m);
    for (int j=0;j<m;j++) scanf("%d",&avail[j]);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) need[i][j]=max[i][j]-alloc[i][j];
    for (int j=0;j<m;j++) work[j]=avail[j];
    for (int i=0;i<n;i++) finish[i]=0;
    int count=0;
    while (count<n) {
        int found=0;
        for (int i=0;i<n;i++) if (!finish[i]) {
            int j; for (j=0;j<m;j++) if (need[i][j] > work[j]) break;
            if (j==m) {
                for (int k=0;k<m;k++) work[k]+=alloc[i][k];
                safeSeq[count++]=i; finish[i]=1; found=1;
            }
        }
        if (!found) break;
    }
    if (count==n) {
        printf("System is in SAFE state. Safe sequence: ");
        for (int i=0;i<n;i++) printf("P%d ", safeSeq[i]);
        printf("\n");
    } else printf("System NOT in safe state (Deadlock may occur)\n");
    return 0;
}
#endif

#ifdef PROG14
/* PROG14: Deadlock detection algorithm */
int main() {
    int n,m;
    printf("Deadlock Detection: Enter number of processes: "); if (scanf("%d",&n)!=1) return 0;
    printf("Enter number of resources: "); scanf("%d",&m);
    int alloc[n][m], req[n][m], avail[m], work[m], finish[n];
    printf("Enter Allocation matrix:\n"); for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&alloc[i][j]);
    printf("Enter Request matrix:\n"); for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&req[i][j]);
    printf("Enter Available: "); for (int j=0;j<m;j++) scanf("%d",&avail[j]);
    for (int j=0;j<m;j++) work[j]=avail[j];
    for (int i=0;i<n;i++) {
        int allocated=0; for (int j=0;j<m;j++) if (alloc[i][j]!=0) { allocated=1; break; }
        finish[i] = !allocated;
    }
    int changed=1;
    while (changed) {
        changed=0;
        for (int i=0;i<n;i++) if (!finish[i]) {
            int j; for (j=0;j<m;j++) if (req[i][j] > work[j]) break;
            if (j==m) { for (int k=0;k<m;k++) work[k]+=alloc[i][k]; finish[i]=1; changed=1; }
        }
    }
    int dead=0; printf("Processes in deadlock: ");
    for (int i=0;i<n;i++) if (!finish[i]) { printf("P%d ", i); dead=1; }
    if (!dead) printf("None\n"); else printf("\nDeadlock detected\n");
    return 0;
}
#endif

#ifdef PROG15
/* PROG15: IPC using pipe (child writes, parent reads) */
int main() {
    int fd[2];
    if (pipe(fd) == -1) { perror("pipe"); return 1; }
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }
    if (pid == 0) {
        close(fd[0]);
        char *msg = "Hello Parent, this is Child via pipe";
        write(fd[1], msg, strlen(msg)+1);
        close(fd[1]);
        return 0;
    } else {
        close(fd[1]);
        char buf[200];
        read(fd[0], buf, sizeof(buf));
        printf("Parent received: %s\n", buf);
        close(fd[0]);
    }
    return 0;
}
#endif

#ifdef PROG16
/* PROG16: IPC using System V Message Queue (child sends, parent receives) */
#include <sys/ipc.h>
#include <sys/msg.h>
struct msgbuf { long mtype; char mtext[200]; };
int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }
    if (pid == 0) {
        struct msgbuf msg; msg.mtype = 1; strcpy(msg.mtext, "Hello Parent, message queue here!");
        msgsnd(msgid, &msg, sizeof(msg.mtext), 0);
        return 0;
    } else {
        struct msgbuf rcv;
        msgrcv(msgid, &rcv, sizeof(rcv.mtext), 1, 0);
        printf("Parent got: %s\n", rcv.mtext);
        msgctl(msgid, IPC_RMID, NULL);
    }
    return 0;
}
#endif

#ifdef PROG17
/* PROG17: IPC using System V Shared Memory (child writes, parent reads) */
#include <sys/ipc.h>
#include <sys/shm.h>
int main() {
    key_t key = ftok("shmfile",65);
    int shmid = shmget(key, 1024, 0666|IPC_CREAT);
    char *str = (char*) shmat(shmid, (void*)0, 0);
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }
    if (pid == 0) {
        strcpy(str, "Hello Parent, this is Child via shared memory");
        shmdt(str);
        return 0;
    } else {
        sleep(1); // give child time
        printf("Parent read: %s\n", str);
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL);
    }
    return 0;
}
#endif

#ifdef PROG18
/* PROG18: Producer-Consumer using POSIX semaphores + pthreads (threads version) */
#include <pthread.h>
#include <semaphore.h>
#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE], in=0, out=0;
sem_t empty, full, mutex;
void *producer(void *arg) {
    for (int i=0;i<10;i++) {
        int item = rand()%100;
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in]=item; 
        in=(in+1)%BUFFER_SIZE;
        printf("Producer produced: %d\n", item);
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
    return NULL;
}
void *consumer(void *arg) {
    for (int i=0;i<10;i++) {
        sem_wait(&full);
        sem_wait(&mutex);
        int item = buffer[out]; out=(out+1)%BUFFER_SIZE;
        printf("Consumer consumed: %d\n", item);
        sem_post(&mutex);
        sem_post(&empty);
        sleep(2);
    }
    return NULL;
}
int main() {
    pthread_t pt, ct;
    sem_init(&empty,0,BUFFER_SIZE); 
    sem_init(&full,0,0); 
    sem_init(&mutex,0,1);
    pthread_create(&pt,NULL,producer,NULL);
    pthread_create(&ct,NULL,consumer,NULL);
    pthread_join(pt,NULL); 
    pthread_join(ct,NULL);
    sem_destroy(&empty); 
    sem_destroy(&full); 
    sem_destroy(&mutex);
    return 0;
}
#endif

#ifdef PROG19
/* PROG19: Dining Philosophers using semaphores + pthreads (avoid simple deadlock by ordering) */
#include <pthread.h>
#include <semaphore.h>
#define NPH 5
sem_t chop[NPH];
void *philosopher(void *arg) {
    int id = *(int*)arg;
    while (1) {
        printf("Philosopher %d thinking\n", id);
        sleep(rand()%3 + 1);
        if (id == NPH-1) { // last picks right then left to avoid circular wait
            sem_wait(&chop[(id+1)%NPH]); sem_wait(&chop[id]);
        } else {
            sem_wait(&chop[id]); sem_wait(&chop[(id+1)%NPH]);
        }
        printf("Philosopher %d eating\n", id);
        sleep(rand()%2 + 1);
        sem_post(&chop[id]); sem_post(&chop[(id+1)%NPH]);
        printf("Philosopher %d done eating\n", id);
    }
    return NULL;
}
int main() {
    pthread_t tid[NPH]; int ids[NPH];
    for (int i=0;i<NPH;i++) 
    sem_init(&chop[i],0,1), ids[i]=i;
    for (int i=0;i<NPH;i++) pthread_create(&tid[i],NULL,philosopher,&ids[i]);
    for (int i=0;i<NPH;i++) pthread_join(tid[i],NULL);
    return 0;
}
#endif

/* If no PROGn chosen, show help */
#ifndef PROG1 && !defined(PROG2) && !defined(PROG3) && !defined(PROG4) && !defined(PROG5) && !defined(PROG6) && !defined(PROG7) && !defined(PROG8) && !defined(PROG9) && !defined(PROG10) && !defined(PROG11) && !defined(PROG12) && !defined(PROG13) && !defined(PROG14) && !defined(PROG15) && !defined(PROG16) && !defined(PROG17) && !defined(PROG18) && !defined(PROG19)
int main() {
    printf("Please compile with -DPROGn where n is 1..19 to select a program.\n");
    return 0;
}
#endif
