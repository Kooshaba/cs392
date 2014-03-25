/*
Main method for myselect
Pre: Receives a list of files as command line arguments
Post: Returns a a list of selected files from the list into the terminal output
*/

#include "../lib/myselect.h"

#define BUFF_SIZE 8

int main(int argc, char **argv)
{
    int i;
    char buffer[BUFF_SIZE];
    char stop = 0;
    int n;

    if(argc > 1)
    {

    init_terminal();
    setup_elems(argc-1, &argv[1]);
    term_clear();

    show_elems();
        while(stop==0)
        {
            if((n = read(0, buffer, BUFF_SIZE-1)) < 0)
            {
                my_str("Something bad happened.\n");
                restore_terminal();
                exit(1);
            }
            else
            {
                if(my_strncmp(buffer, ESC,2) == 0 && n<3)
                {
                    term_clear();
                    restore_terminal();
                    stop = 1;
                }
                else if(my_strncmp(buffer, "\n",1) == 0)
                {
                    stop = 2;
                    restore_terminal();
                }
                else if(my_strncmp(buffer, KD,3) == 0)
                {
                    if((gl_env.pos + 1) > gl_env.nbelems - 1)
                    {
                        gl_env.pos = 0;
                    }
                    else
                    {
                        gl_env.pos++;
                    }
                    show_elems();
                }
                else if(my_strncmp(buffer, KU,3) == 0)
                {
                    if((gl_env.pos - 1) < 0)
                    {
                        gl_env.pos = gl_env.nbelems - 1;
                    }
                    else
                    {
                        gl_env.pos--;
                    }
                    show_elems();
                }
                else if(my_strncmp(buffer, KR,3) == 0)
                {
                    gl_env.pos += gl_env.win.ws_row + 1;
                    if(gl_env.pos >= gl_env.nbelems)
                        gl_env.pos = gl_env.nbelems -1;
                    show_elems();
                }
                else if(my_strncmp(buffer, KL,3) == 0)
                {
                    gl_env.pos -= gl_env.win.ws_row +1;
                    if(gl_env.pos < 0)
                        gl_env.pos = 0;
                    show_elems();
                }
                else if(my_strncmp(buffer, " ",1) == 0)
                {
                    if(gl_env.elements[gl_env.pos].mode == 1)
                        gl_env.elements[gl_env.pos].mode = 0;
                    else
                        gl_env.elements[gl_env.pos].mode = 1;

                    if((gl_env.pos + 1) > gl_env.nbelems - 1)
                    {
                        gl_env.pos = 0;
                    }
                    else
                    {
                        gl_env.pos++;
                    }

                    show_elems();
                }
            }
            if(stop == 2)
            {
                term_clear();
                for(i = 0; i < gl_env.nbelems; i++)
                {
                    if(gl_env.elements[i].mode == 1)
                    {
                        my_str(gl_env.elements[i].elem);
                        my_str(" ");
                    }
                }
            }
        }
    }
    else
    {
        my_str("Use 1 or more parameters.");
    }
    restore_terminal();
    return 0;
}