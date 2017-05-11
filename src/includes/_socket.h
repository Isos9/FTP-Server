#ifndef MY_SOCKET_H_
  #define MY_SOCKET_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct my_sock_s {
  int    fd;
  int    port;
  int     client_fd;
  char   *client_ip;
  struct sockaddr_in s_in;
} my_sock;

void  init_sock(my_sock *_sock);
void  bind_sock(my_sock *_sock);
void  listen_sock(my_sock *_sock);
void  accept_c(my_sock *_sock);

#endif