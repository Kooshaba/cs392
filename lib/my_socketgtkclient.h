/*
* Andy Cernera 2013
* I pledge my honor that I have abided by the Stevens Honor System.
* This program creates a client with a user interface using GTK.
*/

#include <gtk/gtk.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include "../lib/my.h"

#ifndef _MY_SOCKETGTKCLIENT_
#define _MY_SOCKETGTKCLIENT_
#endif