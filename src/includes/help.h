/*
** help.h for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src/includes
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 23:17:25 2017 Sébastien Jacobin
** Last update Sun May 21 23:17:33 2017 Sébastien Jacobin
*/

#ifndef HELP_H_
  #define HELP_H_

#include "reply_codes.h"
#include "_socket.h"

int feat_cmd(my_sock *_sock, char **resp);
int help_cmd(my_sock *_sock, char **resp);

#endif
