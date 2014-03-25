/*
Runs a custom shell to run commands through. Does not take any arguments and runs until stopped. Quits on exit command.
*/

#include "../lib/my_minishell.h"

#define BUFF_SIZE 512

int main(int argc, char **argv)
{
    int n;
    int fd;
    int i;
    char **vect;
    char buffer[BUFF_SIZE];
    char *san;

    while(1)
    {
        my_str("[--MyMiniShell--]$ ");
        if((n = read(1, buffer, BUFF_SIZE-1)) < 0)
        {
            my_str("Something bad happened.\n");
            exit(0);
        }
        else
        {
            san = my_stripbuffer(buffer);
            vect = my_str2vect(san);

            if(my_strcmp(vect[0], "cd") == 0)
            {
                if((n = chdir(vect[1])) < 0)
                {
                    my_str("Execution of cd failed.\n");
                }
            }
            else if(my_strcmp(vect[0], "exit") == 0)
            {
                my_str("Goodbye!\n");
                exit(0);
            }
            else
            {
                if((fd = fork()) < 0)
                {
                    my_str("Fork Fail");
                    exit(0);
                }
                if(fd > 0)
                {
                    wait();
                }
                else
                {
                    if((n = execvp(vect[0], vect)) < 0)
                    {
                        my_str("Execution of ");
                        my_str(vect[0]);
                        my_str(" failed.\n");
                        exit(0);
                    }
                }
            }
        }
    }
}