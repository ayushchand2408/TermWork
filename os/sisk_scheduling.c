#include<stdio.h>
#include<stdlib.h>


int main(){
    int d;
    printf("enter the no of disk request :- ");
    scanf("%d",&d);
    int seq[d];
    for(int i = 0 ; i < d ;i++){
        scanf("%d",&seq[i]);
    }
    int max;
    printf("enter maximum size of disk :- ");
    scanf("%d" ,&max);
    int head,seek=0;
    printf("enter the initial state :- ");
    scanf("%d",&head);

    // //fcfs
    // for(int i = 0 ; i < d ; i++){
    //     seek += abs(head - seq[i]);
    //     head = seq[i];
    // }
    // printf("total seek time :- %d" , seek);


    //SCAN
    int direction;
    printf("enter the directione (0 for left or 1 for right ) :- ");
    scanf("%d",&direction);
    int right[d],r=0,left[d],l=0;

    for(int i = 0 ; i < d ; i++){
        if(seq[i] > head){
            right[r++]=seq[i];
        }else{
            left[l++] = seq[i];
        }
    }

    for(int i = 0; i  < r-1 ; i++){
        for(int j = 0 ; j < r-i-1 ; j++){
            if(right[j+1] < right[j]){
                int temp = right[j];
                right[j] = right[j+1];
                right[j+1] = temp;
            }
        }
    }
    for(int i = 0; i  < l-1 ; i++){
        for(int j = 0 ; j < l-i-1 ; j++){
            if(left[j+1] < left[j]){
                int temp = left[j];
                left[j] = left[j+1];
                left[j+1] = temp;
            }
        }
    }
    // if(direction == 1){
    //     for(int i = 0 ; i < r ; i++){
    //         seek+=abs(head-right[i]);
    //         printf("%d ",right[i]);
    //         head = right[i];
    //     }
    //     seek += abs(head - (max-1));
    //     head = max-1;
    //     for(int i = l-1 ; i >= 0;  i-- ){
    //         seek+=abs(head-left[i]);
    //         printf("%d " , left[i]);
    //         head = left[i];
    //     }
    // }else{
    //     for(int i = l-1 ; i >=0 ; i--){
    //         seek+=abs(head-left[i]);
    //         printf("%d ",left[i]);
    //         head = left[i];
    //     }
    //     seek +=abs(head-0);
    //     head=0;
    //     for(int i = 0 ; i < r ; i++ ){
    //         seek += abs(head-right[i]);
    //         printf("%d ",right[i]);
    //         head = right[i];
    //     }
    // }
    
    //CSCAN
    if(direction == 1){
        for(int i = 0 ; i < r ; i++){
            seek+=abs(head-right[i]);
            printf("%d ",right[i]);
            head = right[i];
        }
        seek += abs(head - (max-1));
        head = max-1;
        seek+=abs(head-0);
        head=0;
        for(int i = 0 ; i < l;  i++ ){
            seek+=abs(head-left[i]);
            printf("%d " , left[i]);
            head = left[i];
        }
    }else{
        for(int i = l-1 ; i >=0 ; i--){
            seek+=abs(head-left[i]);
            printf("%d ",left[i]);
            head = left[i];
        }
        seek +=abs(head-0);
        head=0;
        seek+=abs(max-1);
        head = max-1;
        for(int i = r-1 ; i >=0 ; i-- ){
            seek += abs(head-right[i]);
            printf("%d ",right[i]);
            head = right[i];
        }
    }
    printf("\n Total seek time :- %d " , seek);

}