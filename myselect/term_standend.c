/*
pre none
post : ends highlighting
*/

#include "../lib/myselect.h"

void term_standend()
{
    tputs(gl_env.stand_end, 1, my_termprint);
}