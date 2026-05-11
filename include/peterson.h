#ifndef PETERSON_H
#define PETERSON_H

void peterson_init(void);

void peterson_lock(int id);
void peterson_unlock(int id);

#endif
