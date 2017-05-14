#include "includes/_socket.h"
#include "includes/_server.h"

int main(int ac, char **av)
{
  if (ac != 2)
    return (0);
  my_sock mySock;

  mySock.port = atoi(av[1]);
  memset(mySock.client.user, 0, 64);
  memset(mySock.client.passwd, 0, 64);
  memset(mySock.client.buffer, 0, 1024);
  mySock.client.logged = 0;
  init_sock(&mySock);
  bind_sock(&mySock);
  listen_sock(&mySock);
  init_server(&mySock);
  if (close(mySock.fd) == -1)
  {
    perror("socket file descriptor");
    return (1);
  }
  printf("fd : %d | client_fd : %d\n", mySock.fd, mySock.client.fd);
  return (0);
}