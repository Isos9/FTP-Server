/*
** data.h for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src/includes
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 23:16:44 2017 Sébastien Jacobin
** Last update Sun May 21 23:16:46 2017 Sébastien Jacobin
*/

#ifndef DATA_H_
  #define DATA_H_

#include "get_next_line.h"
#include "down_up_lst.h"
#include "pasv.h"
#include "reply_codes.h"
#include "_socket.h"
#include "path.h"

int pasv_cmd(my_sock *_sock, char **resp);
int retr_cmd(my_sock *_sock, char **resp);
int stor_cmd(my_sock *_sock, char **resp);
int dele_cmd(my_sock *_sock, char **resp);

#endif
