#Makefile for Termcaps Assignment
NAME=myselect
SRC=check_character.c doselect.c get_win_size.c getout.c init_caps.c init_terminal.c movedown.c moveleft.c moveright.c moveup.c my_termprint.c refreshin.c refreshout.c restore_terminal.c setup_elems.c show_elems.c term_clear.c term_get_cap.c term_move_to_item.c term_standend.c term_standout.c term_underend.c term_underline.c term_ve.c term_vi.c main.c term_cursoroff.c term_cursoron.c set_up_caps.c init_term_caps.c

OBJ=$(SRC:.c=.o)
RM=rm -f
LIBPATH=../lib
LIBS=-lmy -ltermcap
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