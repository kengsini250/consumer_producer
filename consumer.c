#include "consumer.h"


void* consumer_thread(void*param)
{
    while(1)
    {
        pthread_mutex_lock(&C_mutex);
        while(empty())
        {
            pthread_cond_wait(&cv,&C_mutex);
        }

        Task* task = pop();
        printf("pop task\n");
        printf("waiting : %d\n",size());
        pthread_mutex_unlock(&C_mutex);

        printf("func GO\n");
        task->doTask(param);
        free(task);
    }
    return NULL;
}
