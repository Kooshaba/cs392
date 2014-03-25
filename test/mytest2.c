/*
Tests for functions in assignment 2 in the my_ library
*/

#include "../lib/my.h"

#ifndef SEP
#define SEP sep();
#endif

#ifndef NL
#define NL nl();
#endif

void sep()
{
    my_str("\n");
    my_str("**********************");
    my_str("\n");
}

void nl()
{
    my_str("\n");
}

int main()
{
    my_str(my_strdup("hello"));
    SEP
    my_str(my_find("hello", 'e'));
    NL
    my_str(my_find("hello", 'k'));
    NL
    my_str(my_find(NULL, 'h'));
    NL
    my_str(my_find("hello", '\0'));
    NL
    my_str(my_find("", 'h'));
    SEP
    my_str(my_rfind("hello", 'l'));
    NL
    my_str(my_rfind("hello", 'k'));
    NL
    my_str(my_rfind(NULL, 'h'));
    NL
    my_str(my_rfind("hello", '\0'));
    NL
    my_str(my_rfind("", 'h'));
    SEP
    my_str(my_strcat(my_strdup("hello"), my_strdup("hey")));
    NL
    my_str(my_strcat(my_strdup("wonderful"), my_strdup("a")));
    NL
    my_str(my_strcat(NULL, my_strdup("hello")));
    NL
    my_str(my_strcat(my_strdup("hello"), NULL));
    NL
    my_str(my_strcat(my_strdup("hello"), my_strdup("")));
    SEP
    my_int(my_strcmp("hello", "hey"));
    NL
    my_int(my_strcmp("hey", "hello"));
    NL
    my_int(my_strcmp("hey", "hey"));
    NL
    my_int(my_strcmp("a", ""));
    NL
    my_int(my_strcmp("", "a"));
    NL
    my_int(my_strcmp(NULL, "a"));
    NL
    my_int(my_strcmp("a", NULL));
    SEP
    my_int(my_strncmp("hello", "hey", 3));
    NL
    my_int(my_strncmp("hello", "hey", -1));
    NL
    my_int(my_strncmp("hey", "hello", 3));
    NL
    my_int(my_strncmp("abcz", "abcd", 3));
    NL
    my_int(my_strncmp("abc", "abcd", 7));
    NL
    my_int(my_strncmp(NULL, "abc", 3));
    NL
    my_int(my_strncmp("abc", NULL, 3));
    NL
    my_int(my_strncmp("hello", "heythere", 0));
    SEP
    my_str(my_strcpy(my_strdup("hello"), my_strdup("hey")));
    NL
    my_str(my_strcpy(my_strdup("hello"), my_strdup("mmhmmm")));
    NL
    my_str(my_strcpy(NULL, my_strdup("hello")));
    NL
    my_str(my_strcpy(my_strdup("hello"), NULL));
    SEP
    my_str(my_strncpy(my_strdup("hello"), my_strdup("ppp"), 3));
    NL
    my_str(my_strncpy(my_strdup("hello"), my_strdup("ppp"), -1));
    NL
    my_str(my_strncpy(my_strdup("hello"), my_strdup("upie"), 4));
    NL
    my_str(my_strncpy(my_strdup("hello"), my_strdup("red"), 10));
    NL
    my_str(my_strncpy(NULL, my_strdup("hello"), 2));
    NL
    my_str(my_strncpy(my_strdup("hello"), NULL, 2));
    SEP
    my_str(my_strdup("hello"));
    NL
    my_str(my_strdup("a"));
    NL
    my_str(my_strdup(NULL));
    NL
    my_str(my_strdup("\0"));
    SEP
    my_str(my_strconcat("hello", "hey"));
    NL
    my_str(my_strconcat("hey", "hello"));
    NL
    my_str(my_strconcat("", "hey"));
    NL
    my_str(my_strconcat("hey", ""));
    NL
    my_str(my_strconcat(NULL, "hello"));
    NL
    my_str(my_strconcat("hello", NULL));
    SEP
    my_str(my_strnconcat("hello", "hey", 3));
    NL
    my_str(my_strnconcat("hello", "hey", 5));
    NL
    my_str(my_strnconcat("", "hey", 2));
    NL
    my_str(my_strnconcat("hey", "", 1));
    NL
    my_str(my_strnconcat("hello", "hey", 0));
    NL
    my_str(my_strnconcat("hello", "hey", -1));
    NL
    my_str(my_strnconcat(NULL, "hey", 3));
    NL
    my_str(my_strnconcat("hey", NULL, 3));
    NL
    my_str(my_strnconcat(NULL, NULL, 3));
    SEP
    my_str(my_stdstrnconcat("hello", "hey", 3));
    NL
    my_str(my_stdstrnconcat("hello", "hey", 5));
    NL
    my_str(my_stdstrnconcat("", "hey", 2));
    NL
    my_str(my_stdstrnconcat("hey", "", 1));
    NL
    my_str(my_stdstrnconcat("hello", "hey", 0));
    NL
    my_str(my_stdstrnconcat(NULL, "hey", 3));
    NL
    my_str(my_stdstrnconcat("hey", NULL, 3));
    NL
    my_str(my_stdstrnconcat(NULL, NULL, 3));
    SEP
}