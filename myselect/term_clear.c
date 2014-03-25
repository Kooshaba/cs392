/*pre none
post : clears the terminal window
*/

#include "../lib/myselect.h"

void term_clear()
{
    tputs(gl_env.clear, 1, my_termprint);
}