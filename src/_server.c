#include "includes/_server.h"

static int _serverRun = 1;

void  exit_signal()
{
  _serverRun = 0;
  write(1, "exit", 4);
}

int init_server(my_sock *_sock)
{
  pid_t   pid;

  while (_serverRun)
  {
    if (accept_c(_sock) != -1)
    {
      if ((pid = fork()) == -1)
      {
        perror("fork");
        exit(1);
      }
      else
        handle_client(_sock, pid);
    }
    signal(SIGINT, exit_signal);
  }
  return (0);
}

int handle_client(my_sock *_sock, pid_t pid)
{
  if (pid == 0)
  {
    _sock->client_ip = inet_ntoa(_sock->s_in.sin_addr);
    printf("ip : %s\n", _sock->client_ip);
    write(_sock->client_fd, "Hello !\n", 8);
    if (close(_sock->client_fd) == -1)
    {
      perror("socket file descriptor");
      return (1);
    }
    wait(&pid);
  } else
  {
    if (close(_sock->client_fd) == -1)
    {
      perror("socket file descriptor");
      return (1);
    }
  }
  return (0);
}