/*
** cmd_client.h for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src/includes
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 23:16:23 2017 Sébastien Jacobin
** Last update Sun May 21 23:16:35 2017 Sébastien Jacobin
*/

#ifndef CMD_CLIENT_H_
  #define CMD_CLIENT_H_

#include "data.h"
#include "help.h"
#include "directory.h"
#include "login.h"

typedef int (*cmd_client)(my_sock *, char **);

typedef struct cmd_s {
  char *name;
  cmd_client fct;
} cmd_t;

cmd_t *init_cmd();
cmd_t new_cmd(char *str, cmd_client fct);
int exec_cmd(my_sock *_sock, char **resp);
int noop_cmd(my_sock *_sock, char **resp);

#endif
