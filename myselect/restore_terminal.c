/*
pre none
post : restores terminal to original state
*/

#include "../lib/myselect.h"

void restore_terminal()
{
    ioctl(0, TCSETA, &(gl_env.line_backup));
    dup2(gl_env.stdio_backup, 1);
    term_cursoron();
    term_standend();
    term_underend();
}