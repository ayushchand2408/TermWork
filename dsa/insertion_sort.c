#include<stdio.h>

void insertion_sort(int arr[]){
    int i , key , j;
    for(int i = 1 ; i < 10 ; i++){
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[10];
    printf("enter the value in array : ");
    for(int i = 0 ; i < 10 ; i++){
        scanf("%d",&arr[i]);
    }
    insertion_sort(arr);
    for(int i = 0 ; i < 10 ; i++){
        printf("%d ",arr[i]);
    }

}