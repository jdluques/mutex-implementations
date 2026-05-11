#include "dekker.h"

static volatile int flag[2];
static volatile int turn;

void dekker_init(void)
{
    flag[0] = flag[1] = 0;
    turn = 0;
}

void dekker_lock(int id)
{
    int other = 1 - id;

    flag[id] = 1;

    while (flag[other]) {
        if (turn == other) {
            flag[id] = 0;
            
            while (turn == other);
            
            flag[id] = 1;
        }
    }
}
 
void dekker_unlock(int id)
{
    turn = 1 - id;
    flag[id] = 0;
}
