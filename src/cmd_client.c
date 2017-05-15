#include "includes/cmd_client.h"

cmd_t new_cmd(char *str, cmd_client fct)
{
  int i;
  cmd_t res;

  i = 0;
  res.fct = fct;
  res.name = malloc(sizeof(char) * (strlen(str) + 1));
  while (str && str[i])
  {
    res.name[i] = str[i];
    i++;
  }
  res.name[i] = 0;
  return (res);
}

cmd_t *init_cmd()
{
  cmd_t *res;

  res = malloc(sizeof(cmd_t) * 8);
  res[0] = new_cmd("USER", user_cmd);
  res[1] = new_cmd("PASS", passwd_cmd);
  res[2] = new_cmd("SYST", syst_cmd);
  res[3] = new_cmd("FEAT", feat_cmd);
  res[4] = new_cmd("PWD", pwd_cmd);
  res[5] = new_cmd("TYPE", type_cmd);
  res[6] = new_cmd("QUIT", quit_cmd);
  res[7] = new_cmd("", NULL);
  return (res);
}

int exec_cmd(my_sock *_sock, char **resp)
{
  int i;
  cmd_t *res;

  i = 0;
  res = init_cmd();
  while (res[i].fct)
  {
    if (strcmp(resp[0], res[i].name) == 0)
      return (res[i].fct(_sock, resp));
    i++;
  }
  return (0);
}

