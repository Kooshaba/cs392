/*
Defines a client that can connect to a server via sockets. Sends messages to server to be printed.
*/

#include "../lib/my_sockets.h"
#define BUFF_SIZE 512

int sockfd;

void bye()
{
    int e;
    if((e = write(sockfd, "/exit", 6)) < 0)
    {
        my_str("Something bad happened.\n");
        exit(0);
    }
    else
    {

    }
    my_str("\nLeft the server.\n");
    close(sockfd);
    exit(0);
}

int main(int argc, char **argv)
{
    int e;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFF_SIZE];
    char *in;

    signal(SIGINT, bye);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        my_str("Socket Failed");
        exit(1);
    } else
    {
        my_str("Socket Successful\n");
    }

    server = (struct hostent*)gethostbyname(argv[1]);

    serv_addr.sin_port = htons(my_atoi(argv[2]));
    serv_addr.sin_family = AF_INET;
    memcpy(&(serv_addr.sin_addr.s_addr), (server->h_addr), server->h_length);

    if((e = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0)
    {
        my_str("Connect Failed");
        exit(1);
    } else
    {
        my_str("Please input your username:\n");
        while(1)
        {
            my_str("-->");
            if((e = read(1, buffer, BUFF_SIZE-1)) < 0)
            {
                my_str("Read Failed.\n");
                exit(0);
            }
            else
            {
                in = my_stripbuffer(buffer);
                if((e = write(sockfd, in, e)) < 0)
                {
                    my_str("Write Failed.\n");
                    exit(0);
                }
                else
                {
                    if(my_strcmp(in, "/exit") == 0)
                    {
                        close(sockfd);
                        exit(0);
                    }

                }
            }
        }
    }
}