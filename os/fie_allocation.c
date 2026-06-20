#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

 struct f{
    char name[10];
    int start;
    int length;
    int block[max];
};

int main(){
    int n;
    printf("enter the number of files :- ");
    scanf("%d" , &n);
    struct f file[n];

    //insert all files;
    for(int i = 0 ; i < n ; i++){
        printf("enter %d file name :- " ,i+1);
        scanf("%s",file[i].name);
        printf("enter %d file starting block :- " , i+1);
        scanf("%d",&file[i].start);
        printf("enter no of blocks rewuired :- ");
        scanf("%d",&file[i].length);
        for(int j = 0 ; j < file[i].length ; j++){
            file[i].block[j] = file[i].start + j;
        }
        printf("\n");
    }

    //searh
    char search[10];
    int found=0;
    printf("enter the file name to be search :- ");
    scanf("%s" , search);

    for(int i = 0 ; i  < n ; i++){
        if(strcmp(file[i].name , search) == 0){
            found = 1;
            printf("file name :- %s  starting block :- %d , no_o_blocks :- %d ",file[i].name,file[i].start , file[i].length);
            printf("all blocks :- ");
            for(int j = 0 ;j < file[i].length ; j++){
                printf("%d  " , file[i].block[j]);
            }
            break;
        }
    }
    if(found==0){
        printf("\nnot present in the memory ");
    }
}