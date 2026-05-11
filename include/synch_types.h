#ifndef LOCK_TYPES_H
#define LOCK_TYPES_H

typedef enum {
    LOCK_PTHREAD,
    LOCK_DEKKER,
    LOCK_PETERSON,
    LOCK_DIJKSTRA
} synch_type_t;

#endif
