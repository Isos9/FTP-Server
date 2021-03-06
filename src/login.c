/*
** login.c for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 22:17:44 2017 Sébastien Jacobin
** Last update Sun May 21 22:19:14 2017 Sébastien Jacobin
*/

#include "includes/login.h"

int	user_cmd(my_sock *_sock, char **resp)
{
  if (resp)
    {
      if (!_sock->client.logged)
	{
	  strcpy(_sock->client.user, resp[1]);
	  write_protocole(_sock, 331);
	}
      else
	write_protocole_s(_sock, "530 User already logged\n");
    }
  return (0);
}

int	passwd_cmd(my_sock *_sock, char **resp)
{
  if (resp)
    {
      if (!_sock->client.logged)
	{
	  if (strcasecmp(_sock->client.user, "anonymous") == 0)
	    {
	      if (!resp[1] || (strlen(resp[1]) == 0))
		{
		  _sock->client.logged = 1;
		  write_protocole(_sock, 230);
		}
	    }
	  else
	    write_protocole_s(_sock,"530 Bad login\n");
	}
      else
	write_protocole_s(_sock, "530 User already logged\n");
    }
  return (0);
}

int	syst_cmd(my_sock *_sock, char **resp)
{
  char *msg;
  struct utsname *buf;

  if (resp)
    {
      buf = malloc(sizeof(struct utsname));
      uname(buf);
      msg = malloc(sizeof(char) * (strlen(buf->sysname) + 2));
      sprintf(msg, "215 %s\n", buf->sysname);
      write_protocole_s(_sock, msg);
    }
  return (0);
}

int	quit_cmd(my_sock *_sock, char **resp)
{
  (void)resp;
  write_protocole(_sock, 221);
  return (-1);
}
