/*
pre none
post : turns cursor on
*/

#include "../lib/myselect.h"

void term_cursoron()
{
    tputs(gl_env.cursoron, 1, my_termprint);
}