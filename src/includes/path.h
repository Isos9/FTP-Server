/*
** path.h for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src/includes
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 23:18:22 2017 Sébastien Jacobin
** Last update Sun May 21 23:18:24 2017 Sébastien Jacobin
*/

#ifndef PATH_H_
 #define PATH_H_

#include <limits.h>
#include "reply_codes.h"
#include "_socket.h"

char *gen_real_path(my_sock *_sock, char *path);
void  init_path(my_sock *_sock, char *path);
char  *check_path(my_sock *_sock, char *path);
char *check_path_up(my_sock *_sock, char *path);
char *cut_path(char *path, int len);

#endif
