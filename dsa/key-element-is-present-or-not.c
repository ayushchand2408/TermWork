// Given a matrix of size n X n, where every row and every column is sorted in increasing order.
// Write an algorithm and a program to find whether the given key element is present in the matrix
// or not. (Linear time complexity)*/
#include<stdio.h>
int main(){
  int n;
  printf("Enter the size of matrix:");
  scanf("%d",&n);
  int arr[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&arr[i][j]);
    }
  }
  int flag=0;
  int key;
  printf("Enter the key you want to search : ");
  scanf("%d",&key);
  int i=0;
  int j=n-1;
  while(i<n && j>=0){
    if(arr[i][j]==key){
      flag=1;
      break;
    }
    else if(arr[i][j]<key){
      i++;
    }
    else if(arr[i][j]>key){
      j--;
    }
    else continue;
  }
  if(flag==1)
   printf("present");
  else 
   printf("Not present");
  return 0;
}