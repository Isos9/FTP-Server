#include "includes/str_to_wordtab.h"
#include "includes/cmd_client.h"
#include "includes/_server.h"

static int _serverRun = 1;

void  exit_signal()
{
  _serverRun = 0;
  write(1, "exit", 4);
}

int init_server(my_sock *_sock)
{
  pid_t   ppid;
  pid_t   pid;

  pid = -2;
  ppid = getpid();
  while (_serverRun && ppid == getpid())
  {
    if (accept_c(_sock) != -1)
    {
      if ((pid = fork()) == -1)
      {
        perror("fork");
        exit(1);
      }
      else
        handle_new_client(_sock, pid);
    }
    signal(SIGINT, exit_signal);
  }
  return (0);
}

int handle_new_client(my_sock *_sock, pid_t pid)
{
  if (pid == 0)
  {
    _sock->client.ip = inet_ntoa(_sock->s_in.sin_addr);
    printf("ip : %s\n", _sock->client.ip);
    handle_client(_sock);
  } else
  {
    if (close(_sock->client.fd) == -1)
    {
      perror("socket file descriptor");
      exit(1);
    }
  }
  return (0);
}

int handle_client(my_sock *_sock)
{
  char **resp;

  write(_sock->client.fd, "Hello !\n", 8);
  while (read(_sock->client.fd, _sock->client.buffer, 1024))
  {
    if (_sock->client.buffer[0] != '\r')
    {
      resp = my_str_to_wordtab(_sock->client.buffer);
      if (exec_cmd(_sock, resp) == -1)
      {
        printf("return\n");
        break;
      }
      printf("OK(après)\n");
//    printf("msg : %s | len : %ld\n", *resp, strlen(*resp));
//    printf("fd : %d\n", _sock->client.fd);
      memset(_sock->client.buffer, 0, 1024);
      free(resp);
    }
  }
  if (close(_sock->client.fd) == -1)
  {
    perror("socket file descriptor");
    exit(1);
  }
  return (0);
}