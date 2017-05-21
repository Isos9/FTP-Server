/*
** pasv.h for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src/includes
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 23:18:09 2017 Sébastien Jacobin
** Last update Sun May 21 23:18:13 2017 Sébastien Jacobin
*/

#ifndef PASV_H_
  #define PASV_H_

#include "_socket.h"

char *get_part(my_sock *_sock, int *i);
char **split_ip(my_sock *_sock);
void  init_pasv_sock(my_sock *_sock, int *port);


#endif
