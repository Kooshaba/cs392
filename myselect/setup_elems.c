/*
    pre receive args from command line
    post : put command lines args into global env as elements
*/

#include "../lib/myselect.h"

void setup_elems(int c, char** v)
{
    int i;

    gl_env.elements = xmalloc(c*sizeof(t_elem));
    gl_env.nbelems = c;
    gl_env.pos = 0;

    for(i = 0; i < c; i++)
    {
        gl_env.elements[i].elem = v[i];
        gl_env.elements[i].size = my_strlen(v[i]);
        gl_env.elements[i].x = 0;
        gl_env.elements[i].y = 0;
        gl_env.elements[i].mode = 0;
    }
}