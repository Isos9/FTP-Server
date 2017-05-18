#include "includes/cmd_client.h"

int noop_cmd(my_sock *_sock, char **resp)
{
  if (resp)
    write_protocole(_sock, 200);
  return (0);
}

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

  res = malloc(sizeof(cmd_t) * 14);
  res[0] = new_cmd("USER", user_cmd);
  res[1] = new_cmd("PASS", passwd_cmd);
  res[2] = new_cmd("SYST", syst_cmd);
  res[3] = new_cmd("FEAT", feat_cmd);
  res[4] = new_cmd("PWD", pwd_cmd);
  res[5] = new_cmd("TYPE", type_cmd);
  res[6] = new_cmd("LIST", list_cmd);
  res[7] = new_cmd("CWD", cwd_cmd);
  res[8] = new_cmd("PASV", pasv_cmd);
  res[9] = new_cmd("RETR", retr_cmd);
  res[10] = new_cmd("NOOP", noop_cmd);
  res[11] = new_cmd("HELP", help_cmd);
  res[12] = new_cmd("QUIT", quit_cmd);
  res[13] = new_cmd("", NULL);
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
    if (resp[0] && strcmp(resp[0], res[i].name) == 0)
      return (res[i].fct(_sock, resp));
    i++;
  }
  write_protocole_s(_sock, "500 Bad command\n");
  return (0);
}

