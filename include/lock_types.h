#ifndef LOCK_TYPES_H
#define LOCK_TYPES_H

typedef enum {
    LOCK_PTHREAD,
    LOCK_DECKER,
    LOCK_PETERSON,
    LOCK_DIJKSTRA
} lock_type_t;

#endif
