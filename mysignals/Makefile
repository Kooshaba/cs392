#Makefile for mysignals
NAME=mysignals
CLISRC=client.c
SERSRC=server.c
CLIOBJ=$(CLISRC:.c=.o)
SEROBJ=$(SERSRC:.c=.o)
RM=rm -f
LIBPATH=../lib
LIBS=-lmy
# Begin Commands
client:$(CLIOBJ)
	cc -L$(LIBPATH) $(CLIOBJ) $(LIBS) -o client
server:$(SEROBJ)
	cc -L$(LIBPATH) $(SEROBJ) $(LIBS) -o server
all:client server
clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *.core

fclean: clean
	-$(RM) $(LIBPATH)/$(NAME)

re: fclean all

debug: fclean $(SEROBJ) $(CLIOBJ)
	cc -L$(LIBPATH) $(CLIOBJ) $(LIBS) -g -o client
	cc -L$(LIBPATH) $(SEROBJ) $(LIBS) -g -o server