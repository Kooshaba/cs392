#ifndef _MYSELECT_H_
#define _MYSELECT_H_

#include <sys/ioctl.h>
#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/termios.h>
#include "../lib/my.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <termcap.h>

#define READTIME 1
#define READMIN 3
#ifndef NULL
#define NULL (0)
#endif

#define KU "\E[A"
#define KD "\E[B"
#define KR "\E[C"
#define KL "\E[D"
#define UP "ku"
#define DOWN "kd"
#define LEFT "kl"
#define RIGHT "kr"
#define CLEAR "cl"
#define MOVE "cm"
#define STANDOUT "so"
#define STAND_END "se"
#define UNDERLINE "us"
#define UNDER_END "ue"
#define CURSOROFF "vi"
#define CURSORON "ve"
#define VECAP "\E[?25h"
#define VICAP "\E[?251"
#define ESC "\E["

typedef struct s_elem
{
    char *elem;
    int size;
    int x;
    int y;
    int mode;
} t_elem;

typedef struct s_env
{
    char *left;
    char *right;
    char *up;
    char *down;
    char *esc;
    char *underline;
    char *under_end;
    char *standout;
    char *stand_end;
    char *move;
    char *clear;
    char *cursoroff;
    char *cursoron;
    struct winsize win;
    struct termio line_backup;
    int flag;
    int stdio_backup;
    int nbelems;
    int pos;
    t_elem *elements;
}   t_env;

t_env gl_env;

void init_terminal();



void restore_terminal();

// char *term_get_cap(char*);
// void init_caps();
int my_termprint(int);

void term_clear();

void term_cursoroff();

void term_cursoron();

//char check_character(char *c);
char get_win_size();

void show_elems();

void move_cursor(int, int);

void doselect();
void getout(char);
void setup_elems(int, char**);

void term_move_to_item(int);

void term_underline();

void term_standout();

void term_standend();

void term_underend();

void init_term_caps();
void set_up_caps();

#endif
