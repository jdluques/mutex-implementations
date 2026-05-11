#include "lock.h"

#include "decker.h"
#include "peterson.h"

static lock_type_t current_lock;

void lock_init(lock_type_t type, int thread_count)
{
    current_lock = type;

    switch (type) {
        case LOCK_PTHREAD:
            break;

        case LOCK_DECKER:
            decker_init();
            break;

        case LOCK_PETERSON:
            peterson_init();
            break;

        case LOCK_DIJKSTRA:
            dijkstra_init(thread_count);
            break;
    }
}

void thread_lock(int id)
{
    switch (current_lock) {
        case LOCK_PTHREAD:
            break;

        case LOCK_DECKER:
            decker_lock(id);
            break;

        case LOCK_PETERSON:
            peterson_lock(id);
            break;

        case LOCK_DIJKSTRA:
            dijkstra_lock(id);
            break;
    }
}

void thread_unlock(int id)
{
    switch (current_lock) {
        case LOCK_PTHREAD:
            break;

        case LOCK_DECKER:
            decker_unlock(id);
            break;

        case LOCK_PETERSON:
            peterson_unlock(id);
            break;

        case LOCK_DIJKSTRA:
            dikstra_unlock(id);
            break;
    }
}
