/*
Pre: Receives char
Post: Prints it
*/

#include "../lib/my.h"

void my_char(char c)
{
    write(1, &c, 1);
}