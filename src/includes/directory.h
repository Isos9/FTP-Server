/*
** directory.h for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src/includes
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 23:16:53 2017 Sébastien Jacobin
** Last update Sun May 21 23:16:55 2017 Sébastien Jacobin
*/

#ifndef DIR_H_
  #define DIR_H_

#include <dirent.h>
#include "reply_codes.h"
#include "down_up_lst.h"

int pwd_cmd(my_sock *_sock, char **resp);
int type_cmd(my_sock *_sock, char **resp);
int  list_cmd(my_sock *_sock, char **resp);
int cwd_cmd(my_sock *_sock, char **resp);
int cdup_cmd(my_sock *_sock, char **resp);

#endif
