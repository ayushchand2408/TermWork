#include<stdio.h>
int main(){
  int m;
  printf("enter the size  of array");
  scanf("%d",&m);

  int str[m];
  printf("enter the elements in array");

  for (int i=0;i<m;i++){
    scanf("%d",&str[i]);
  }
  int n;
  printf("enter the index of an array");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    str[m]=str[0];
    for(int j=0;j<=m;j++)
    {
      str[j]=str[j+1];
    }
  }
   for (int i=0;i<m;i++)
  {
    printf("%d ",str[i]);
  }
   
      return 0;
}
