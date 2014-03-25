/*
pre none
post: initializes all settings for terminal and caps for use in program
*/

#include "../lib/myselect.h"

void init_terminal()
{
    signal(SIGWINCH, show_elems);

    init_term_caps();
    set_up_caps();
}