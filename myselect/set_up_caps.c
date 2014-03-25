/*
Pre: none
post: sets up all caps for use in everything else
*/

#include "../lib/myselect.h"

void set_up_caps()
{
    char bp[2048];
    char* termname;

    termname = getenv("TERM");
    tgetent(bp, termname);

    //all globals, except up down left right esc
    gl_env.underline = tgetstr(UNDERLINE, NULL);
    gl_env.under_end = tgetstr(UNDER_END, NULL);
    gl_env.standout = tgetstr(STANDOUT, NULL);
    gl_env.stand_end = tgetstr(STAND_END, NULL);
    gl_env.clear = tgetstr(CLEAR, NULL);
    gl_env.move = tgetstr(MOVE, NULL);

    gl_env.cursoron = 0;
    gl_env.cursoroff = 0;
    gl_env.cursoron = tgetstr(CURSORON, NULL);
    gl_env.cursoroff = tgetstr(CURSOROFF, NULL);

    if(gl_env.cursoron)
        gl_env.cursoron = tgetstr(VICAP, NULL);
    if(gl_env.cursoroff)
        gl_env.cursoroff = tgetstr(VECAP, NULL);
}