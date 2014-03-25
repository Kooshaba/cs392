/*
* Andy Cernera 2013
* I pledge my honor that I have abided by the Stevens Honor System
* Client: Sends strings through signals to the server
*/

#include "../lib/my_signals.h"

char gl_ack = 0;

void ack()
{
    gl_ack = 1;
}

void omg()
{
    my_str("\nConnection to Server Timeout\n");
    exit(0);
}

void sendpid(int spid, pid_t send)
{
    int t;
    pid_t c;
    int i;

    t = 0;
    c = (1 << ((8 * sizeof(pid_t)) - 1));

    /*
    my_str("--SENDING-->");
    my_int(send);
    my_str("<--\n");

    my_str("--MAXVALUE-->");
    my_int(c);
    my_str("<--\n");

    my_str("--SIZEOF(PID_T)-->");
    my_int(sizeof(pid_t));
    my_str("<--\n");
    */


    for(i = 0; i < (8 * sizeof(pid_t)); i ++)
    {
        t = send & c;
        if(!t)
        {
            /*
            my_str("---->");
            my_str("Sent Zero");
            my_str("<--\n");
            */
            kill(spid, SIGUSR1);
        }
        else
        {
            /*
            my_str("---->");
            my_str("Sent One");
            my_str("<--\n");
            */
            kill(spid, SIGUSR2);
        }
        send = send << 1;
        usleep(5000);
    }
}

void sendstring(int spid, char* send)
{
    char t;
    char c;
    char i;

    c = 0x80;

    my_str("--STRING-->");
    my_str(send);
    my_str("<--\n");
    while(!gl_ack)
    {
        i = 0;
        while(i < 8 && !gl_ack)
        {
            t = *send & c;
            if(!t && !gl_ack)
            {
                /*
                my_str("---->");
                my_str("Sent Zero");
                my_str("<--\n");
                */
                kill(spid, SIGUSR1);
            }

            else if(t && !gl_ack)
            {
                /*
                my_str("---->");
                my_str("Sent One");
                my_str("<--\n");
                */
                kill(spid, SIGUSR2);
            }

            *send = *send << 1;
            usleep(5000);
            i++;
        }
        send ++;
    }

}

int main(int argc, char** argv)
{
    int serpid;

    serpid = 0;
    if(argc >= 3)
    {
        if((serpid = atoi(argv[1])) > 0)
        {
            my_str("--CLIPID-->");
            my_int(getpid());
            my_str("<--\n");

            signal(SIGUSR1, ack);
            signal(SIGALRM, omg);
            sendpid(serpid, getpid());
            if(!gl_ack)
            {
                alarm(5);
                pause();
            }
            alarm(0);
            gl_ack = 0;

            my_str("--SENDING STRING-->");
            my_str("<--\n");

            sendstring(serpid, my_vect2str(&argv[2]));
            gl_ack = 0;

            my_str("--FINISHED SENDING STRING-->");
            my_str("<--\n");
        }
    }

    return 0;
}