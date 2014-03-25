/*
pre none
post : moves cursor to specified x y pos
*/

#include "../lib/myselect.h"

void move_cursor_to(int x, int y)
{
    tputs(tgoto(gl_env.move, x, y), 1, my_termprint);
}