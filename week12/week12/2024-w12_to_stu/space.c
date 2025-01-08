#include "space.h"

tTypeScore score_buf[N]; //preallocated memory space

void get_score_space(tTypeScore **pp_score)
{
    for (int i = 0; i < N; i++)
    {
        if (score_buf[i].used == 0)
        {
            score_buf[i].used = 1;
            score_buf[i].loc = i;
            score_buf[i].score = (*pp_score)->score;
            *pp_score = &score_buf[i];
            printf("     get_score_space(): giving space numbered %d\n", i);
            return;
        }
    }
}

void return_score_space (int loc)
{
    score_buf[loc].used = 0;
    printf("     return_score_space(): return space numbered %d\n", loc);
    return;
}
