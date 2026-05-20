#include "config.h"
#include "synch_types.h"

#include <stdio.h>

config_t input_config()
{
    config_t config;

    int synch_type_num;
    do {
        printf("Select synchronization primitive (0: PTHREAD, 1: DEKKER, 2: PETERSON, 3: DIJKSTRA):\n");
        scanf("%d", &synch_type_num);
    } while (0 > synch_type_num || synch_type_num > 3);
    config.synch_type = (synch_type_t)synch_type_num;

    printf("Select amount of iterations:\n");
    scanf("%d", &config.iters);

    if (synch_type_num != 1 && synch_type_num != 2) {
        printf("Select number of threads:\n");
        scanf("%d", &config.n_threads);
    }

    printf("\n");

    return config;
}
