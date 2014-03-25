/*
pre : have elems put in global env
post : moves cursor to specified item x
*/

#include "../lib/myselect.h"

void term_move_to_item(int x)
{
    tputs(tgoto(gl_env.move, gl_env.elements[x].x, gl_env.elements[x].y), 1, my_termprint);
}