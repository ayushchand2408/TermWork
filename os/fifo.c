#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

void fifo(int frames[] , int pages[] , int n,int req){
    int page_fault=0;

    int j=0;
    for(int i =0 ; i < req ; i++){
        int flag=0;
        for(int k =0 ; k < n ; k++){
            if(frames[k] == pages[i]){
                flag=1;
                break;
            }
        }
        if(flag == 0){
            frames[j] = pages[i];
            page_fault++;
            j = (j+1)%n;
        }
    }
    printf("no of page_fault :- %d", page_fault);

}

void lru(int frames[] , int pages[] , int n,int req){
    int page_fault=0,usage[n];

    for(int i = 0 ; i < req ; i++){
        int flag = 0;
        for(int k = 0 ; k < n ; k++){
            if(frames[k] == pages[i]){
                flag = 1;
                usage[k]+=1;
                break;
            }
        }
        if(flag == 0){
            int max = INT_MAX , idx = -1;
            for(int k = 0;  k < n ; k++){
                if(usage[i] < max || idx == -1){
                    max = usage[i];
                    idx = i;
                }
            }
            frames[idx] = pages[i];
            usage[idx]++;
            page_fault++;
        }
    }
    printf("no of page_fault :- %d", page_fault);
}

int main(){
    int n ,req,pg_no;

    printf("enter the number of frames :- ");
    scanf("%d",&n);

    int frames[n];
    for(int i = 0 ;i  < n ; i++){
        frames[i] =-1;
    }
    printf("enter the numer of request :- ");
    scanf("%d",&req);
    
    int pages[req];
    printf("enter the values of pages :- ");
    for(int i = 0; i  < req ; i++){
        scanf("%d", & pages[i]);
    }
    lru(frames,pages,n,req);
}