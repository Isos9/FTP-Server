/*
** cmd_client.c for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 22:15:24 2017 Sébastien Jacobin
** Last update Sun May 21 22:23:35 2017 Sébastien Jacobin
*/

#include "includes/cmd_client.h"

int	noop_cmd(my_sock *_sock, char **resp)
{
  if (resp)
    write_protocole(_sock, 200);
  return (0);
}

cmd_t	new_cmd(char *str, cmd_client fct)
{
  int	i;
  cmd_t	res;

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

cmd_t	*init_cmd()
{
  cmd_t	*res;

  res = malloc(sizeof(cmd_t) * 17);
  res[0] = new_cmd("USER", user_cmd);
  res[1] = new_cmd("PASS", passwd_cmd);
  res[2] = new_cmd("QUIT", quit_cmd);
  res[3] = new_cmd("SYST", syst_cmd);
  res[4] = new_cmd("FEAT", feat_cmd);
  res[5] = new_cmd("PWD", pwd_cmd);
  res[6] = new_cmd("TYPE", type_cmd);
  res[7] = new_cmd("LIST", list_cmd);
  res[8] = new_cmd("CWD", cwd_cmd);
  res[9] = new_cmd("PASV", pasv_cmd);
  res[10] = new_cmd("RETR", retr_cmd);
  res[11] = new_cmd("NOOP", noop_cmd);
  res[12] = new_cmd("HELP", help_cmd);
  res[13] = new_cmd("CDUP", cdup_cmd);
  res[14] = new_cmd("DELE", dele_cmd);
  res[15] = new_cmd("STOR", stor_cmd);
  res[16] = new_cmd("", NULL);
  return (res);
}

int	exec_cmd(my_sock *_sock, char **resp)
{
  int	i;
  cmd_t	*res;

  i = 0;
  res = init_cmd();
  while (res[i].fct)
    {
      if (resp[0] && strcasecmp(resp[0], res[i].name) == 0)
	{
	  if (i > 2 && !_sock->client.logged)
	    {
	      write_protocole_s(_sock, "530 Please login with USER and PASS.\n");
	      return (0);
	    }
	  return (res[i].fct(_sock, resp));
	}
      i++;
    }
  if (_sock->client.logged)
    write_protocole_s(_sock, "500 Bad command\n");
  else
    write_protocole_s(_sock, "530 Please login with USER and PASS.\n");
  return (0);
}
