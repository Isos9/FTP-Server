#include "includes/str_to_wordtab.h"
#include "includes/cmd_client.h"
#include "includes/_server.h"

int init_server(my_sock *_sock)
{
  pid_t   ppid;
  pid_t   pid;

  pid = -2;
  ppid = getpid();
  while (ppid == getpid())
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

  write_protocole_s(_sock,"220 Hello !\r\n");
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