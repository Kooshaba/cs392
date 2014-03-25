/*
pre none
post: starts underlining
*/

#include "../lib/myselect.h"

void term_underline()
{
    tputs(gl_env.underline, 1, my_termprint);
}