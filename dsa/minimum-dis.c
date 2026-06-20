
#include<stdio.h>
int main(){
 int num;
 printf("enter the no.of elements in an array");
 scanf("%d",&num);
 int arr[num];
 printf("enter the elments in array");
 for(int i= 0; i< num;i++){
    scanf("%d",&arr[i]);
    }
   int a;
   printf("enter the first no.");
   scanf("%d",&a);
   int b;
   printf("enter the second no.");
   scanf("%d",&b);
   int l=0;
   int count =0;
  for(int i=0 ; i< num ; i++)
  {
      if(arr[i]==a||arr[i]==b)
      {
      l=arr[i];
      for(int j=i+1;j<num;j++)
      {
         if( (arr[j]==a||arr[j]==b)&&arr[j]!=l)
         {
            for (int k=i;k<=j;k++)
            {
                 if(arr[k]==arr[j])
                 {
                  count=k-i;
                  break;
                      
                    
               }
            }
         }
      }
      }
   }
   printf("the diff is %d",count);
                      
}