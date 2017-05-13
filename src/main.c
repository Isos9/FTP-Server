#include "includes/_socket.h"
#include "includes/_server.h"

int main(int ac, char **av)
{
  if (ac != 2)
    return (0);
  my_sock mySock;

  mySock.port = atoi(av[1]);
  init_sock(&mySock);
  bind_sock(&mySock);
  listen_sock(&mySock);
  init_server(&mySock);
  if (close(mySock.fd) == -1)
  {
    perror("socket file descriptor");
    return (1);
  }
  printf("fd : %d | client_fd : %d\n", mySock.fd, mySock.client_fd);
  return (0);
}