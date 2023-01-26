#ifndef __TASK_H__
#define __TASK_H__

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

extern pthread_mutex_t Q_mutex,C_mutex;
extern pthread_cond_t cv;

typedef struct{
    int id;
    void (*doTask)(void*);
}Task;

void InitDoTask(Task*,void(*func)(void*));

typedef struct _TQ
{
    Task* task;
    struct _TQ *next;
}TaskQueue;


void initTaskQueue(void);
void push(Task*);
Task* pop(void);
void destoryTaskQueue(void);
int empty(void);
int size(void);

#endif
