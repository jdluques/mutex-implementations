#ifndef LOCK_H
#define LOCK_H

#include "lock_types.h"

void lock_init(lock_type_t type, int thread_count);

void thread_lock(int id);
void thread_unlock(int id);

#endif
