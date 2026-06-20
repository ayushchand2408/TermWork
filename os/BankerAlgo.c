#include<stdio.h>
#include<limits.h>

int main() {
    int n,m;
    printf("Banker: Enter number of processes: "); 
    if (scanf("%d",&n)!=1) return 0;
    printf("Enter number of resources: "); 
    scanf("%d",&m);
    int alloc[n][m], max[n][m], need[n][m], avail[m], work[m], finish[n], safeSeq[n];
    printf("Enter allocation matrix (%d x %d):\n", n, m);
    for (int i=0;i<n;i++){ 
        for (int j=0;j<m;j++){ 
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("Enter max matrix (%d x %d):\n", n, m);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){ 
            scanf("%d",&max[i][j]);
        }
    }

    printf("Enter available (%d): ", m);
    for (int j=0;j<m;j++){ 
        scanf("%d",&avail[j]);
    }
    
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){ 
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    for (int j=0;j<m;j++){
        work[j]=avail[j];
    }

    for (int i=0;i<n;i++) 
        finish[i]=0;
    int count=0;
    while (count<n) {
        int found=0;
        for (int i=0;i<n;i++){
            if (!finish[i]) {
                int j;
                for ( j=0;j<m;j++){
                    if (need[i][j] > work[j]) break;
                }
                if (j==m) {
                    for (int k=0;k<m;k++) 
                        work[k]+=alloc[i][k];
                    safeSeq[count++]=i; finish[i]=1; found=1;
                }
            }
        }
        if (!found) break;
    }
    if (count==n) {
        printf("System is in SAFE state. Safe sequence: ");
        for (int i=0;i<n;i++) 
            printf("P%d ", safeSeq[i]);
        printf("\n");
    } else 
        printf("System NOT in safe state (Deadlock may occur)\n");
    return 0;
}
