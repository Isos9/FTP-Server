#include "includes/login.h"

int user_cmd(my_sock *_sock, char **resp)
{
  if (resp)
  {
    if (strcmp(resp[1], "Anonymous") == 0)
    {
      strcpy(_sock->client.user, resp[1]);
      strcpy(_sock->client.passwd, resp[1]);
      _sock->client.logged = 1;
      write_protocole(_sock, 230);
    }
    else
    {
      strcpy(_sock->client.user, resp[1]);
      write_protocole(_sock, 331);
    }
  }
  return (0);
}

int passwd_cmd(my_sock *_sock, char **resp)
{
  if (resp)
  {
    if (strlen(_sock->client.user) > 0)
    {
      strcpy(_sock->client.passwd, resp[1]);
      _sock->client.logged = 1;
      write_protocole(_sock, 230);
    }
    else
      write_protocole(_sock, 332);
  }
  return (0);
}

int  quit_cmd(my_sock *_sock, char **resp)
{
  (void)resp;
  write_protocole(_sock, 221);
  return (-1);
}