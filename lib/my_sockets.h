/*
* Andy Cernera 2013
* I pledge my honor that I have abided by the Stevens Honor System
* This program creates a client and server architecture. The client connects to the server using sockets and sends messages to the server. Multiple conncetions from clients are accepted simultaneously.
*/

#include "../lib/my.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>

#ifndef _MY_SOCKETS_
#define _MY_SOCKETS_

#endif