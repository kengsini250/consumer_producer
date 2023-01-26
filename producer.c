#include "producer.h"

void func(void*param)
{
//     printf("func working ! id:%d\n",(int)param);
    printf("func working ! \n");
    sleep(2);
}

void* producer_thread(void*prarm)
{
    int id = 0;
    Task*task=NULL;
    while(1)
    {
        task = (Task*)malloc(sizeof(Task));

        InitDoTask(task,func);

        pthread_mutex_lock(&C_mutex);
        push(task);
        printf("push task ! ID:%d\n",id);
        printf("waiting : %d\n",size());
        pthread_mutex_unlock(&C_mutex);
        id++;
        pthread_cond_signal(&cv);
    }
    sleep(4);
}
