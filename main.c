#include "producer.h"
#include "consumer.h"
#include <errno.h>

int main()
{
    initTaskQueue();

    pthread_t consumerThread[5];
    for(int i=0;i<5;i++){
        pthread_create(&consumerThread[i],NULL,consumer_thread,NULL);
    }

    pthread_t producerThread;   
    pthread_create(&producerThread,NULL,producer_thread,NULL);

    int err = pthread_join(producerThread,NULL);//?
    printf("err:%d\n",err);

    for(int i=0;i<5;i++){
        pthread_join(consumerThread[i],NULL);
    }

    destoryTaskQueue();
}
