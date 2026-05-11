#include "lock.h"

#include "dekker.h"
#include "peterson.h"
#include "dijkstra.h"

static lock_type_t current_lock;

void lock_init(lock_type_t type, int thread_count)
{
    current_lock = type;

    switch (type) {
        case LOCK_PTHREAD:
            break;

        case LOCK_DEKKER:
            dekker_init();
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

        case LOCK_DEKKER:
            dekker_lock(id);
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

        case LOCK_DEKKER:
            dekker_unlock(id);
            break;

        case LOCK_PETERSON:
            peterson_unlock(id);
            break;

        case LOCK_DIJKSTRA:
            dijkstra_unlock(id);
            break;
    }
}
