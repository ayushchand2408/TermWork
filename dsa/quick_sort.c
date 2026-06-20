#include<stdio.h>

void swap(int arr[] ,int x , int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y]=temp;
}

int partition(int arr[],int low,int high){
    int i = low-1 , pivot = arr[high];

    for(int j = low ; j < high ; j++){
        if(arr[j] <  pivot){
            i++ ;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,high);
    return i+1;
}

void quick_sort(int arr[],int low,int high){
    if(low<high){
        int pivot = partition(arr,low,high);
        quick_sort(arr,low,pivot-1);
        quick_sort(arr,pivot+1,high);
    }
}
int main(){
    int arr[10];
    printf("enter the value in array : ");
    for(int i = 0 ; i < 10 ; i++){
        scanf("%d",&arr[i]);
    }
    quick_sort(arr,0,9);
    for(int i = 0 ; i < 10 ; i++){
        printf("%d ",arr[i]);
    }

}