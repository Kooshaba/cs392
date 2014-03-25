#Makefile for myminishell
NAME=myminishell
SRC=my_minishell.c
OBJ=$(SRC:.c=.o)
RM=rm -f
LIBPATH=../lib
LIBS=-lmy
# Begin Commands
all:$(OBJ)
	cc -L$(LIBPATH) $(OBJ) $(LIBS) -Wall -pedantic-errors -o $(NAME)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *.core

fclean: clean
	-$(RM) $(LIBPATH)/$(NAME)

re: fclean all