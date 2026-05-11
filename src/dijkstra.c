#include "dijkstra.h"

#include <stdio.h>
#include <stdlib.h>

static int n;

static volatile int  order;
static volatile int *interest;

void dijkstra_init(int n_threads)
{
    n = n_threads;

    order = -1;
    interest = calloc(n, sizeof(int));
    
    if (interest == NULL) {
        perror("Fallo en calloc");
        exit(EXIT_FAILURE);
    }
}

int others_are_interested(int id)
{
    for (int i = 0; i < n; i++) {
        if (interest[i] && i != id) return 1;
    }
    return 0;
}

void dijkstra_lock(int id)
{
    interest[id] = 1;

    while (others_are_interested(id)) {
        if (order != id) {
            interest[id] = 0;
            
            while (order != -1);
            
            order = id;
            interest[id] = 1;
        }
    }
}

void dijkstra_unlock(int id)
{
    order = -1;
    interest[id] = 0;
}
