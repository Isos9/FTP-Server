#include "includes/data.h"

int pasv_cmd(my_sock *_sock, char **resp)
{
  int port;
  char *msg;
  char **ips;

  if (resp)
  {
    if (_sock->client.logged)
    {
      msg = malloc(sizeof(char) * 128);
      init_pasv_sock(_sock, &port);
      printf("port : %d\n", port);
      ips = split_ip(_sock);
      sprintf(msg, "227 Entering Passive Mode (%s,%s,%s,%s,%d,%d).\n", ips[0], ips[1], ips[2], ips[3],
              port/256, port%256);
      _sock->pasv_mode = 1;
      write_protocole_s(_sock, msg);
    }
    else
      write_protocole_s(_sock, "530 Please login with USER and PASS.\n");
  }
  return (0);
}