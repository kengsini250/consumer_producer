#include "task.h"

int count = 0;

pthread_mutex_t Q_mutex,C_mutex;
pthread_cond_t cv;
TaskQueue *head = NULL;

void InitDoTask(Task* t,void(*func)(void*))
{
    t->doTask = func;
}


void initTaskQueue(void)
{
    pthread_mutex_init(&Q_mutex,0);
    pthread_mutex_init(&C_mutex,0);
    pthread_cond_init(&cv,0);

}

void push(Task*task)
{
    pthread_mutex_lock(&Q_mutex);

    TaskQueue*node = (TaskQueue*)malloc(sizeof(TaskQueue));
    node->task = task;
    node->next = NULL;

    if(head == NULL){
        head = node;
    }else{

        TaskQueue *pos = head;
        while (pos->next != NULL)
        {
            pos = pos->next;
        }

        pos->next = node;
    }

    count++;
    pthread_mutex_unlock(&Q_mutex);
}

Task* pop(void)
{
    pthread_mutex_lock(&Q_mutex);

    TaskQueue*first =head;
    Task*out=first->task;
    if(first->next == NULL){

    }
    else{
        head = head->next;
        free(first);
    }

    count--;

    pthread_mutex_unlock(&Q_mutex);
    return out;
}

void destoryTaskQueue(void)
{



    pthread_mutex_destroy(&Q_mutex);
    pthread_mutex_destroy(&C_mutex);
    pthread_cond_destroy(&cv);
}

int empty(void)
{
    pthread_mutex_lock(&Q_mutex);
    if(count==0)
    {
        pthread_mutex_unlock(&Q_mutex);
        return 1;
    }
    else{
        pthread_mutex_unlock(&Q_mutex);
        return 0;
    } 
}

int size(void)
{return count;}
