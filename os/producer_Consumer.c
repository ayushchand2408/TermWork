#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

#define Buffer_size 5

int buffer[Buffer_size] , in = 0 , out= 0;

sem_t mutex , empty , full;

void *producer(void *args){
    for(int i = 0 ; i <10 ; i++){
        int item = rand()%100;
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = item;
        in = (in+1)%Buffer_size;
        printf("producer produced: %d\n" , item);
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
    return NULL;
    
}
void *consumer(void *args){
    for(int i = 0 ; i < 10 ; i++){
        sem_wait(&full);
        sem_wait(&mutex);

        int item = buffer[out];
        out = (out+1)%Buffer_size;
        printf("Consumer Consumed: %d\n" , item);
        sem_post(&mutex);
        sem_post(&empty);
        sleep(2);
    }
    return NULL;
}

int main(){
    pthread_t pt , ct;
    sem_init(&empty,0,Buffer_size);
    sem_init(&full ,0 , 0);
    sem_init(&mutex , 0 ,1);
    pthread_create(&pt,NULL , producer,NULL);
    pthread_create(&ct,NULL,consumer,NULL);
    pthread_join(pt,NULL);
    pthread_join(ct,NULL);

    sem_destroy(&empty);
    sem_destroy(&mutex);
    sem_destroy(&full);
    return 0;
}