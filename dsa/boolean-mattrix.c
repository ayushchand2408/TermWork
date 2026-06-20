// Given a boolean matrix (contains only 0 and 1) of size m X n where each row is sorted, write an
// algorithm and a program to find which row has maximum number of 1's. (Linear time
// complexity)*/

#include<stdio.h>
int main(){
  int m,n;
  printf("Enter the size of the array :");
  scanf("%d %d",&m,&n);
  int arr[m][n];
  printf("Enter the elements of the array : ");
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&arr[i][j]);
    }
  }
  int i=0,temp;
  int j=n-1;
  int max=-1;
  
  while(i<n && j>=0){
    if(arr[i][j]==0)      
     i++;
    
    else{
      max=i;
      j--;
    }
  }


  if(max == -1) 
    printf("no row have 1 in the matrix.");
  else  
  printf("row : %d",max);
  return 0;
}