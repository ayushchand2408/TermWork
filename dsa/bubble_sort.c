#include<stdio.h>

void swap(int arr[] ,int x , int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y]=temp;
}
void bubble_sort(int arr[]){
    int check;
    for(int i = 0 ; i < 10-1 ; i++){
        check = 0;
        for(int  j = 0 ; j < 10 - i - 1 ; j++){
            if(arr[j] > arr[j + 1])
            {
                swap(arr,j,j+1);
                check = 1;
            }
        }
        if(check == 0){
            break;
        }
    }
}
int main(){
    int arr[10];
    printf("enter the value in array : ");
    for(int i = 0 ; i < 10 ; i++){
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr);
    for(int i = 0 ; i < 10 ; i++){
        printf("%d ",arr[i]);
    }

}