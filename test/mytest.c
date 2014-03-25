/* Test file for Assignment 1 */
#include "../lib/my.h"

void test_my_char()
{
    my_char(' ');
    my_char('\n');
    my_char('a');
    my_char('\n');
}

void test_my_str()
{
    my_str("hello");
    my_char('\n');
    my_str(" ");
    my_char('\n');
}


void test_my_int()
{
    my_int(123);
    my_char('\n');
    my_int(-123);
    my_char('\n');
    my_int(0);
    my_char('\n');
    my_int(100);
    my_char('\n');
    my_int(101);
    my_char('\n');
    my_int(((int)(((unsigned int)-1)/2))+1);
    my_char('\n');
}

void test_my_alpha()
{
    my_alpha();
    my_char('\n');
}

void test_my_digits()
{
    my_digits();
    my_char('\n');
}

void test_my_strindex()
{
    my_int(my_strindex("hello", 'l'));
    my_char('\n');
    my_int(my_strindex("hello", 'k'));
    my_char('\n');
   /* my_strindex("hello", NULL);
    my_strindex(NULL, 'l');
    my_strindex(NULL, NULL);
    my_strindex("H", 'l');
    my_strindex(20, 'k');
    my_strindex("hello", 10);
    my_strindex(10, 10); */
}

void test_my_strlen()
{
    my_int(my_strlen("hello"));
    my_char('\n');
    my_int(my_strlen(""));
    my_char('\n');
    my_int(my_strlen(NULL));
    my_char('\n');
}

void test_my_revstr()
{
    my_str("Begin my_revstr \n");
    char str[] = "hey!";
    my_str(str);
    char str1[] = "hello";
    my_revstr(str);
    my_str(str);
    my_char('\n');
    my_revstr(str1);
    my_str(str1);
    my_char('\n');

}

void test_my_strrindex()
{
    my_int(my_strrindex("hello", 'l'));
    my_char('\n');
    my_int(my_strrindex("hello", 'k'));
    my_char('\n');
}


int main(int argc, char **argv)
{
    test_my_char();
    test_my_str();
    test_my_int();
    test_my_alpha();
    test_my_digits();
    test_my_strindex();
    test_my_strlen();
    test_my_revstr();
    my_num_base(123, "01");
    my_char('\n');
    my_num_base(123, "0123456789ABCDEF");
    my_char('\n');
    my_num_base(100, "0123456789");
    my_char('\n');
    test_my_strrindex();
    my_str("-->");
    my_str(my_vect2str(&argv[1]));
    my_str("<--\n");
    my_str("-->");
    my_printvect(&argv[1]);
    my_str("<--\n");
    my_printvect(my_str2vect(my_strdup("hello  world      bro")));
    my_char('\n');
    my_int(my_atoi("100"));
    my_char('\n');
    my_int(my_atoi("-100"));
    my_char('\n');
    my_int(my_atoi(""));
    my_char('\n');
    my_int(my_atoi("\n\n\n"));
    my_char('\n');

    return 0;
}