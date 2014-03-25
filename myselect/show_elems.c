/*
pre : have elems put in global env and intialized terminal
post : clears terminal and displays all arguments given to the program in list form
*/

#include "../lib/myselect.h"

void show_elems()
{
    int i;
    int rows;
    int cols;
    int x;
    int y;
    int maxlength;

// gl_env.win.ws_col
// gl_env.win.ws.row

    x = 0;
    y = 0;
    maxlength =0;

    term_clear();
    get_win_size();

    rows = gl_env.win.ws_row;
    cols = gl_env.win.ws_col;

    for(i = 0; i < gl_env.nbelems; i++)
    {
        if(my_strlen(gl_env.elements[i].elem) > maxlength)
            maxlength = my_strlen(gl_env.elements[i].elem);
        gl_env.elements[i].y = y;
        gl_env.elements[i].x = x;

        if(y > gl_env.win.ws_row  - 1)
        {
            y = 0;
            x += maxlength + 1;
        }

        else
            y++;
    }
    if(y!=0)x+=maxlength;

    if(x > cols)
    {
        term_clear();
        my_str("Shit's crazy yo. FIX IT.\n");
        my_str("Shit's crazy yo. FIX IT.\n");
        my_str("Shit's crazy yo. FIX IT.\n");
        my_str("Shit's crazy yo. FIX IT.\n");
        my_str("Shit's crazy yo. FIX IT.\n");
        my_str("Shit's crazy yo. FIX IT.\n");
        my_str("Shit's crazy yo. FIX IT.\n");
        my_str("Shit's crazy yo. FIX IT.\n");
        my_str("Shit's crazy yo. FIX IT.\n");
        my_str("Shit's crazy yo. FIX IT.\n");
        my_str("Shit's crazy yo. FIX IT.\n");
        my_str("Shit's crazy yo. FIX IT.\n");
        my_str("Shit's crazy yo. FIX IT.\n");
        my_str("Shit's crazy yo. FIX IT.\n");
        my_str("Shit's crazy yo. FIX IT.\n");
    }
    else
    {
        for(i = 0; i < gl_env.nbelems; i++)
        {
            term_move_to_item(i);
            if(gl_env.elements[i].mode == 1)
                term_standout();
            if(gl_env.elements[i].mode == 0)
                term_standend();
            if(i == gl_env.pos)
                term_underline();
            my_str(gl_env.elements[i].elem);
            term_underend();
            term_standend();
        }
    }
}