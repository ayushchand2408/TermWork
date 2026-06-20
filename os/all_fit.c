#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void best_fit(int m , int p , int b[] , int pr[]){
    for(int i = 0 ; i < p ; i++){
        int idx = -1, max = INT_MAX;
        for(int j = 0 ;j  < m ; j++){
            if(b[j] > pr[i] && (idx == -1 || b[j] - pr[i] < max)){
                idx = j;
                max = b[j] - pr[i];
            }
        }
        if(idx !=-1){
            printf("process %d -> block %d (before %d -> After %d \n) " , i+1,idx+1 , b[idx] , b[idx] - pr[i]);
            b[idx] = b[idx] - pr[i];
        }else{
            printf("process %d can be allocated \n" , i+1);
        }
    }
}
void first_fit(int m , int p , int b[] , int pr[]){
    for(int i = 0 ; i < p ; i++){
        int j;
        for( j = 0 ;j < m ; j++){
            if(b[j] > pr[i]){
                printf("process %d -> block %d (before %d -> After %d )\n " , i+1,j+1 , b[j] , b[j] - pr[i]);
                b[j] = b[j] - pr[i];
                break;
            }
        }
        if(j==m){
            printf("process %d can't be allocated \n" , i+1);
        }
    }
}

void worst_fit(int m , int p , int b[] , int pr[]){
    for(int i = 0 ; i < p ; i++){
        int idx = -1, min = INT_MIN;
        for(int j = 0 ;j  < m ; j++){
            if(b[j] > pr[i] && (idx == -1 || b[j] - pr[i] > min)){
                idx = j;
                min = b[j] - pr[i];
            }
        }
        if(idx !=-1){
            printf("process %d -> block %d (before %d -> After %d \n) " , i+1,idx+1 , b[idx] , b[idx] - pr[i]);
            b[idx] = b[idx] - pr[i];
        }else{
            printf("process %d can be allocated \n" , i+1);
        }
    }
}
int main(){
    int m;
    printf("enter the number of memory bolck :- ");
    scanf("%d" , &m);

    printf("enter sizes of %d blocks :- ",m);
    int block_size[m];
    for(int i = 0; i < m ; i++){
        scanf("%d" ,&block_size[i]);
    }

    int p;
    printf("enter the no of processes :- ");
    scanf("%d" , &p);
    int processes[p];
    printf("enter the value of all processes :- ");
    for(int i = 0 ; i < p ; i++){
        scanf("%d" , &processes[i]);
    }
    worst_fit(m,p,block_size,processes);
}