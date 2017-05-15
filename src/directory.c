#include "includes/directory.h"

int pwd_cmd(my_sock *_sock, char **resp)
{
  if (resp)
  {
    if (_sock->client.logged)
    {
      write(_sock->client.fd, "257 \"/\"", 8);
      //TODO: PWD command
    }
    else
      write_protocole_s(_sock, "530 Please login with USER and PASS.\n");
  }
  return (0);
}

int type_cmd(my_sock *_sock, char **resp)
{
  if (resp)
  {
    if (_sock->client.logged)
      write(_sock->client.fd, "200 Switching to Binary mode.\n", 30);
    else
      write_protocole_s(_sock, "530 Please login with USER and PASS.\n");
  }
  return (0);
}