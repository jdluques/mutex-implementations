#ifndef LOCK_H
#define LOCK_H

#include "synch_types.h"

void lock_init(synch_type_t type, int thread_count);

void thread_lock(int id);
void thread_unlock(int id);

#endif
