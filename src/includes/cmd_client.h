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