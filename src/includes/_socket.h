/*
** _socket.h for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src/includes
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 23:19:12 2017 Sébastien Jacobin
** Last update Sun May 21 23:19:15 2017 Sébastien Jacobin
*/

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

typedef struct client_s {
  int fd;
  char *ip;
  int  logged;
  char user[64];
  char passwd[64];
  char buffer[1024];
} client_t;

typedef struct my_sock_s {
  int    fd;
  int    d_fd;
  int    pasv_mode;
  int    port;
  client_t client;
  char    *dir_name;
  char    *serv_ip;
  struct sockaddr_in s_in;
  struct sockaddr_in s_in_pasv;
} my_sock;

void  init_sock(my_sock *_sock);
void  bind_sock(my_sock *_sock);
void  listen_sock(my_sock *_sock);
int  accept_c(my_sock *_sock);

#endif
