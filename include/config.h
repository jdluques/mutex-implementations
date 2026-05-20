#ifndef CONFIG_H
#define CONFIG_H

#include "synch_types.h"

typedef struct {
    int n_threads;
    int iters;
    synch_type_t synch_type;
} config_t;

config_t input_config(void);

#endif
