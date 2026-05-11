#include "peterson.h"

static volatile int flag[2];
static volatile int turn;

void peterson_init(void)
{
    flag[0] = flag[1] = 0;
    turn = 0;
}

void peterson_lock(int id)
{
    int other = 1 - id;

    flag[id] = 1;
    turn = other;

    while (flag[other] && turn == other);
}

void peterson_unlock(int id)
{
    flag[id] = 0;
}
