#include "lock.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static int counter = 0;

typedef struct {
    int id;
    int iters;
} thread_args;

void *thread_func(void *arg) {
    thread_args *args = ((thread_args *) arg);
    int id    = args->id;
    int iters = args->iters;

    thread_lock(id);

    for (int i = 0; i < iters; i++) {
        counter++;
        printf("Counter incremented by Thread %d to %d", id, counter);
    }

    thread_unlock(id);

    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc < 4) {
        fprintf(stderr, "Must provide N_THREADS, ITERS and SYNC_TYPE");
        return 1;
    } 

    int N_THREADS = atoi(argv[1]);
    int ITERS     = atoi(argv[2]);
    lock_type_t SYNC_TYPE = atoi(argv[3]);

    if (SYNC_TYPE < 0 || 3 < SYNC_TYPE) {
        fprintf(stderr, "Invalid SYNC_TYPE (0: PTHREAD, 1: DEKKER, 2: PETERSON, 3: DIJKSTRA)");
        return 1;
    }
    if ((SYNC_TYPE == 1 || SYNC_TYPE == 2) && N_THREADS != 2) {
        fprintf(stderr, "For Dekker's and Peterson's algorithms N_THREADS must be 2");
    }

    pthread_t threads[N_THREADS];
    int ids[N_THREADS];

    lock_init(SYNC_TYPE, N_THREADS);

    for (int i = 0; i < N_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &ids[i]);
    }

    for (int i = 0; i < N_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final counter = %d\n", counter);

    return 0;
}
