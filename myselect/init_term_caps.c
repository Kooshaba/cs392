/*
pre none
post : prepares terminal window for use in the program
*/

#include "../lib/myselect.h"

void init_term_caps()
{
    struct termio line;
    int fd;
    char* term_name;

    ioctl(0, TCGETA, &line);
    gl_env.line_backup = line;
    line.c_lflag &= ~(ECHO|ISIG|ICANON);
    line.c_cc[VTIME] = READTIME;
    line.c_cc[VMIN] = READMIN;
    ioctl(0, TCSETA, &line);

    term_name = ttyname(0);
    fd = open(term_name, O_WRONLY);
    gl_env.stdio_backup = dup(1);
    dup2(fd, 1);
}