#include "pthread_lock.h"

#include <pthread.h>

static pthread_mutex_t mutex;

void pthread_lock_init(void)
{
    pthread_mutex_init(&mutex, NULL);
}

void pthread_thread_lock(int id)
{
    (void)id;
    pthread_mutex_lock(&mutex);
}

void pthread_thread_unlock(int id)
{
    (void)id;
    pthread_mutex_unlock(&mutex);
}
