#include "includes/help.h"

int feat_cmd(my_sock *_sock, char **resp)
{
  if (resp)
  {
    if (_sock->client.logged)
    {
      write(_sock->client.fd, "211-TEST\n", 9);
      write(_sock->client.fd, "211 End\n", 8);
    }
    else
      write_protocole_s(_sock, "530 Please login with USER and PASS.\n");
  }
  return (0);
}