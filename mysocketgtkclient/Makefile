#Makefile for mypipes
NAME=mygtk
SRC=my_gtkclient.c
OBJ=$(SRC:.c=.o)
RM=rm -f
LIBPATH=../lib
LIBS=-lmy

# Begin Commands

all:
	cc -L$(LIBPATH) $(SRC) $(LIBS) -o $(NAME) `pkg-config --cflags --libs gtk+-2.0`

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *.core

fclean: clean
	-$(RM) $(LIBPATH)/$(NAME)

re: fclean all
