#include <stdio.h>

int push(int st[],int top,int n,int v){
    if(top >= n-1){
        printf("stack is full");
        return top ;
    }
    else{
        top++;
        st[top]=v;
        return top;
    }
}
void display(int st[],int top){
    for(int i = 0 ; i <= top ; i++ ){
       printf("%d ", st[i]);
    }
   printf("\n");
}


int pop(int st[],int top){
    if(top == -1){
      printf("stack is empty");
    }
    else{
        top--;
    }
    return top;
}
int main(){
    int arr[100];
    int top = -1,value;
    int n = 1;
    int v,i=0;
    printf("press \n 1 tp push \n 2 to pop \n 3 to calculate size \n 4 to exit\n");
    while(i!=n){
        scanf("%d" ,&v);
        switch(v){
            case 1:
            scanf("%d",&value);
            top = push(arr,top,sizeof(arr)/sizeof(arr[0]),value);
            display(arr,top);
            break;

            case 2:
            top = pop(arr,top);
            display(arr,top);
            break;

            case 3:
            printf("stack size :- %d",top+1);
            printf("\n");
            break;

            case 4:
            i = n;
            break;
        }
    }
}