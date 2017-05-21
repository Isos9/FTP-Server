/*
** login.h for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src/includes
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 23:17:41 2017 Sébastien Jacobin
** Last update Sun May 21 23:17:44 2017 Sébastien Jacobin
*/

#ifndef LOGIN_H_
  #define LOGIN_H_

#include <sys/utsname.h>
#include "_socket.h"
#include "reply_codes.h"

int user_cmd(my_sock *_sock, char **resp);
int passwd_cmd(my_sock *_sock, char **resp);
int  quit_cmd(my_sock *_sock, char **resp);
int syst_cmd(my_sock *_sock, char **resp);

#endif
