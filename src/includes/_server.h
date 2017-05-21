/*
** _server.h for  in /home/isos/Workspace/Epitech/PSU_2016_myftp/src/includes
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 23:18:50 2017 Sébastien Jacobin
** Last update Sun May 21 23:19:01 2017 Sébastien Jacobin
*/

#ifndef MY_SERVER_H_
  #define MY_SERVER_H_

#include <signal.h>
#include <sys/wait.h>
#include "_socket.h"

int  init_server(my_sock *_sock);
int  handle_new_client(my_sock *_sock, pid_t pid);
int handle_client(my_sock *_sock);
void get_server_ip(my_sock *_sock);


#endif
