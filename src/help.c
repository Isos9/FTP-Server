#include "includes/help.h"

int feat_cmd(my_sock *_sock, char **resp)
{
  if (resp)
  {
    write(_sock->client.fd, "211-TEST\n", 9);
    write(_sock->client.fd, "211 End\n", 8);
  }
  return (0);
}

int help_cmd(my_sock *_sock, char **resp)
{
  if (resp)
  {
    write(_sock->client.fd, "214-Help\n", 9);
    write(_sock->client.fd, "214 End\n", 8);
  }
  return (0);
}