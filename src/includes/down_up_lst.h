/*
** down_up_lst.h for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src/includes
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 23:17:04 2017 Sébastien Jacobin
** Last update Sun May 21 23:17:10 2017 Sébastien Jacobin
*/

#ifndef DOWN_H_
  #define DOWN_H_

#include "path.h"
#include "reply_codes.h"
#include "get_next_line.h"
#include "_socket.h"

void  download_data(my_sock *_sock, int fd);
void upload_data(my_sock *_sock, int fd);
char **get_curr_list(my_sock *_sock, char **resp);

#endif
