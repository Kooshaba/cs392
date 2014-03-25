/*
Pre: Receives a char
Post: Prints a char to terminal
*/

#include "../lib/myselect.h"

int my_termprint(int a)
{
    return write(1, &a, 1);
}