/*
Pre: Receives a vector in the form of command line arguments
Post: Creates three processes and pipes information from the grandparent to the child and prints as it completes each task
*/

#include "../lib/my_pipes.h"

#define BUFF_SIZE 512

int main(int argc, char** argv)
{
	char buffer[BUFF_SIZE];
	int fd;
	int n;
	int pipe1[2];
	int pipe2[2];
	char *s = my_vect2str(&argv[1]);
	pipe(pipe1);

	if((fd = fork()) < 0)
	{
		my_str("AHHHHHHHHHHHH~");
		exit(0);
	}

	if(fd > 0)
	{
	   my_str("-->");
		my_str("I am Grandpa Sending>");
		my_str(s);
		my_str("< to the parent");
		my_str("<--\n");

		close(pipe1[0]);
		write(pipe1[1], s, BUFF_SIZE-1);
		wait();
	} else {
		close(pipe1[1]);
		n = read(pipe1[0], buffer, BUFF_SIZE -1);

		my_str("-->");
		my_str("I am Parent Receiving>");
		my_str(buffer);
		my_str("< from the Grandpa");
		my_str("<--\n");

		my_str("-->");
		my_str("I am Parent Sending>");
		my_str(buffer);
		my_str("< to the child");
		my_str("<--\n");

		pipe(pipe2);
		if((fd = fork()) < 0)
		{
			my_str("AHHHHHHHHHHHH~");
			exit(0);
		}

		if(fd > 0)
		{
			close(pipe2[0]);
			write(pipe2[1], buffer, BUFF_SIZE - 1);
			wait();
		} else {
			close(pipe2[1]);
			n = read(pipe2[0], buffer, BUFF_SIZE - 1);
			my_str("-->");
			my_str("I am Child Receiving>");
			my_str(buffer);
			my_str("< from parent");
			my_str("<--\n");
			exit(0);
		}
	}

	return 0;
}