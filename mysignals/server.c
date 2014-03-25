/*
* Andy Cernera 2013
* I pledge my honor that I have abided by the Stevens Honor System
* Server: Receives strings sent by clients through signals and prints them to * the screen
*/

#include "../lib/my_signals.h"

typedef struct g
{
    char done;
    pid_t clipid;
} gl_env;

gl_env env;

void bye()
{
    my_str("\nBye!\n");
    exit(0);
}

void getclipid(int sig)
{
    static pid_t pid = 0;

    pid = pid << 1;
    if(sig == SIGUSR2)
    {
        my_str("--ONE RECEIVED-->");
        my_str("<--\n");
        pid |= 1;
    }
    else
    {
        my_str("--ZERO RECEIVED-->");
        my_str("<--\n");
    }

    env.clipid = pid;
}

void getchar(int sig)
{
    static char c = 0;
    static char count = 0;

    if(count >= 8)
    {
        if(c == '\0')
        {
            env.done = 1;
            c = 0;
            count = 0;
            my_char('\n');
            kill(env.clipid, SIGUSR1);
        }
        else
        {
            my_char(c);
            c = 0;
            count = 0;
        }
    }

    count++;
    c = c << 1;

    if(sig == SIGUSR2)
        c |= 1;

}

int main(int argc, char** argv)
{
    int i;

    my_str("-->");
    my_int(getpid());
    my_str("<--\n");

    env.done = 0;
    signal(SIGINT, bye);

    while(1)
    {
        signal(SIGUSR1, getclipid);
        signal(SIGUSR2, getclipid);

        for(i = 0; i < (8 * sizeof(pid_t)); i++)
            pause();

        kill(env.clipid, SIGUSR1);

        my_str("--CLIPID-->");
        my_int(env.clipid);
        my_str("<--\n");

        signal(SIGUSR1, getchar);
        signal(SIGUSR2, getchar);

        while(!env.done)
        {
            pause();
        }

        env.clipid = 0;
        env.done = 0;

        /*
        for(i = 0; i < 32; i++)
        {
            getclipid(SIGUSR1);
        }
        */
    }

    return 0;
}