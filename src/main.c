#include "includes/_socket.h"

int main(int ac, char **av)
{
  if (ac != 2)
    return (0);
  my_sock mySock;

  mySock.port = atoi(av[1]);
  init_sock(&mySock);
  bind_sock(&mySock);
  listen_sock(&mySock);
  accept_c(&mySock);
  printf("ip : %s\n", mySock.client_ip);
  if (close(mySock.fd) == -1)
  {
    perror("socket file descriptor");
    return (1);
  }
  return (0);
}