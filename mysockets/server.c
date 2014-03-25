/*
Defines a server that accepts connections from clients via sockets. Receives messages and prints them
*/

#include "../lib/my_sockets.h"
#define BUFF_SIZE 512

void bye()
{
    my_str("\nServer shut down!\n");
    exit(0);
}

int main(int argc, char **argv)
{
    int sockfd;
    int newsockfd;
    int e;
    int clisize;
    int pid;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    char buffer[BUFF_SIZE];
    char *username;
    char *in;

    signal(SIGINT, bye);

    my_str("-->Welcome to the My_Sockets Server<--\n");

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        my_str("Socket Failed");
        exit(1);
    } else
    {
        my_str("Socket Successful\n");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    memset(&cli_addr, 0, sizeof(cli_addr));

    serv_addr.sin_port = htons(my_atoi(argv[1]));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if((e = bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0)
    {
        my_str("Bind failed\n");
        my_int(errno);
        my_char('\n');
        exit(1);
    } else
    {
        my_str("Bind Successful\n");
    }

    if((e = listen(sockfd, 5)) < 0)
    {
        my_str("Listen failed\n");
        exit(1);
    } else
    {
        my_str("Listen Successful\n");
    }

    while(1)
    {
        clisize = sizeof(cli_addr);
        in = "";
        if((newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clisize)) < 0)
        {
            my_str("Accept failed\n");
            exit(1);
        } else
        {
            my_str("Accept Successful\n");

            pid = fork();
            if(pid < 0)
            {
                my_str("Fork failed\n");
                exit(1);
            }
            else if( pid == 0)
            {
                if((e = read(newsockfd, buffer, BUFF_SIZE -1)) < 0)
                {
                    my_str("Read failed\n");
                    exit(1);
                } else
                {
                    in = my_stripbuffer(buffer);
                    username = my_strdup(buffer);
                    my_str("***");
                    my_str(username);
                    my_str(" has connected.\n");
                }
                while(1)
                {
                    if((e = read(newsockfd, buffer, BUFF_SIZE -1)) < 0)
                    {
                        my_str("Read failed\n");
                        exit(1);
                    } else
                    {
                        in = my_stripbuffer(buffer);
                        if(my_strncmp("/exit", in, 5) == 0)
                        {
                            my_str("***");
                            my_str(username);
                            my_str(" has disconnected.\n");
                            exit(0);
                        } else if(my_strncmp("/me", in, 3) == 0)
                        {
                            my_str("***");
                            my_str(username);
                            my_char(' ');
                            my_str(&(in[4]));
                            my_str("\n");
                        } else if(my_strncmp("/nick", in, 5) == 0)
                        {
                            my_str("***");
                            my_str(username);
                            my_str(" changed their name to ");
                            username = my_strdup(&(in[6]));
                            my_str(username);
                            my_str(".\n");
                        } else
                        {
                            my_str(username);
                            my_str(": ");
                            my_str(in);
                            my_str("\n");
                        }

                    }
                }
            }
        }
    }
}