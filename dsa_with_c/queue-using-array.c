#include<stdio.h>  
void enqueue(int q[],int *front,int *rear,int n,int v){  
    if((*rear)==n-1){  
        printf("queue is full\t");  
    }  
    else{  
        (*rear)++;  
        if(*front==-1){  
            *front=0;  
        }  
        q[(*rear)]=v;  
    }  
}  
int dequeue(int q[],int *front,int *rear){  
    if((*front)>(*rear)){  
        printf("queue is empty\t");  
        return -1;  
    }  
    else{  
        int k=q[(*front)];  
 
 
        (*front)++;  
        if(*front>*rear){  
            *front=*rear=-1;  
        }  
        return k;  
    }  
}  
int size(int q[],int *front,int *rear){  
    int count =0;  
    for(int i=(*front);i<=(*rear);i++){  
        count++;  
    }  
    return count;  
}  
void display(int q[],int *front,int *rear){  
    for(int i=(*front);i<=(*rear);i++){  
        printf("%d\t",q[i]);  
    }  
    printf("\t");  
}  
int main(){  
   int n, choice, value,count=0;  
    printf("Enter the maximum size of the queue : ");  
    scanf("%d", &n);  
    int q[n];  
    int front = -1;  
    int rear= -1;  
 
 
    while(1) {  
        printf("\nChoose an operation:\n");  
        printf("1. enqueue\n");  
        printf("2. dequeue\n");  
        printf("3. Size\n");  
        printf("4. display\n");  
        printf("5. Exit\n");  
        printf("Enter your choice: ");  
        scanf("%d", &choice);  
        switch(choice) {  
            case 1:  
                printf("Enter the value to enqueue: ");  
                scanf("%d", &value);  
                enqueue(q,&front,&rear,n,value);;  
                break;  
            case 2:  
                value = dequeue(q, &front,&rear);  
                printf("Dequeued value: %d\n", value);  
                break;  
            case 3:  
                 count=size(q,&front,&rear);  
                printf("%d",count);  
                break;  
            case 4:  
                display(q,&front,&rear);  
                break;  
            case 5:  
 
 
                return 0;  
            default:  
                printf("Invalid choice\n");  
        }  
    } 
    return 0; 
}