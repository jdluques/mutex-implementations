#include "synch.h"
#include "config.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static int counter = 0;

typedef struct {
    int id;
    int iters;
} thread_args;

void *thread_func(void *arg)
{
    thread_args *args = ((thread_args *) arg);
    int id    = args->id;
    int iters = args->iters;

    for (int i = 0; i < iters; i++) {
        thread_lock(id);
        
        counter++;
        printf("Counter incremented by Thread %d to %d\n", id, counter);

        thread_unlock(id);
    } 

    return NULL;
}

int main()
{
    config_t config = input_config();

    pthread_t threads[config.n_threads];
    thread_args args[config.n_threads];

    lock_init(config.synch_type, config.n_threads);

    for (int i = 0; i < config.n_threads; i++) {
        args[i].id =  i;
        args[i].iters = config.iters;
        pthread_create(&threads[i], NULL, thread_func, &args[i]);
    }

    for (int i = 0; i < config.n_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final counter = %d\n", counter);

    return 0;
}
