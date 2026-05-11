#ifndef DEKKER_H
#define DEKKER_H

void dekker_init(void);

void dekker_lock(int id);
void dekker_unlock(int id);

#endif
