/*
pre none
post: turns cursor off
*/

#include "../lib/myselect.h"

void term_cursoroff()
{
    tputs(gl_env.cursoroff, 1, my_termprint);
}