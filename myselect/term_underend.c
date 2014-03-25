/*
pre none
post : ends underlining
*/

#include "../lib/myselect.h"

void term_underend()
{
    tputs(gl_env.under_end, 1, my_termprint);
}