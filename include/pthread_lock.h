#ifndef PTHREAD_LOCK_H
#define PTHREAD_LOCK_H

void pthread_lock_init(void);

void pthread_thread_lock(int id);
void pthread_thread_unlock(int id);

#endif
