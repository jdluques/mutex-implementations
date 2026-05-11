#include "lock.h"

static lock_type_t current_lock;

void lock_init(lock_type_t type, int thread_count)
{
    current_lock = type;

    switch (type) {
        case LOCK_PTHREAD:
            break;

        case LOCK_DECKER:
            break;

        case LOCK_PETERSON:
            break;

        case LOCK_DIJKSTRA:
            break;
    }
}

void thread_lock(int id)
{
    switch (current_lock) {
        case LOCK_PTHREAD:
            break;

        case LOCK_DECKER:
            break;

        case LOCK_PETERSON:
            break;

        case LOCK_DIJKSTRA:
            break;
    }
}

void thread_unlock(int id)
{
    switch (current_lock) {
        case LOCK_PTHREAD:
            break;

        case LOCK_DECKER:
            break;

        case LOCK_PETERSON:
            break;

        case LOCK_DIJKSTRA:
            break;
    }
}
