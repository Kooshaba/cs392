/*
pre: none
post: grabs window size and puts it in global environment
*/

#include "../lib/myselect.h"

char get_win_size()
{
    ioctl(0, TIOCGWINSZ, &(gl_env.win));

    return 1;
}