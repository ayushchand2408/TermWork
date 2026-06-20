#include<stdio.h>

void merge(int arr[],int low,int mid,int high){
    int i = low;
    int j = mid +1;
    int k = low;
    int  temp[high-low+1];
    while(i <= mid&& j <= high){
        if(arr[i] <= arr[j]){
            temp[k - low] = arr[i++];
        }
        else{
            temp[k - low]= arr[j++];
        }
        k++;
    }
    while (i <= mid) 
    { 
        temp[k - low] = arr[i++]; 
        k++; 
    } 
    while (j <= high) 
    { 
        temp[k - low] = arr[j++]; 
        k++; 
    } 
    for (int l = low; l <= high; l++) 
    { 
        arr[l] = temp[l - low]; 
    }
        
}
void merge_sort(int arr[],int low , int high){
    if(low<high){
        int mid = (low + high ) /2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){
    int arr[10];
    printf("enter the value in array : ");
    for(int i = 0 ; i < 10 ; i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,9);
    for(int i = 0 ; i < 10 ; i++){
        printf("%d ",arr[i]);
    }

}