/*

*/

#include "../lib/myselect.h"

void term_standout()
{
    tputs(gl_env.standout, 1, my_termprint);
}