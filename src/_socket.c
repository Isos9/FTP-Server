#include "includes/_socket.h"

void  init_sock(my_sock *_sock)
{
  struct protoent   *pe;

  pe = getprotobyname("TCP");
  _sock->s_in.sin_family = AF_INET;
  _sock->s_in.sin_port = htons(_sock->port);
  _sock->s_in.sin_addr.s_addr = INADDR_ANY;
  _sock->fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (_sock->fd == -1)
  {
    perror("socket");
    exit(1);
  }
}

void  bind_sock(my_sock *_sock)
{
  if (bind(_sock->fd, (const struct sockaddr *)&_sock->s_in, sizeof(_sock->s_in)) == -1)
  {
    if (close(_sock->fd) == -1)
      perror("socket file descriptor");
    else
      perror("bind");
    exit(1);
  }
}

void  listen_sock(my_sock *_sock)
{
  if (listen(_sock->fd, _sock->port) == -1)
  {
    if (close(_sock->fd) == -1)
      perror("socket file descriptor");
    else
      perror("listen");
    exit(1);
  }
}

void  accept_c(my_sock *_sock)
{
  unsigned int size;

  size = sizeof(_sock->s_in);
  if ((_sock->client_fd = accept(_sock->fd, (struct sockaddr *)&_sock->s_in, &size)) == -1)
  {
    if (close(_sock->fd) == -1)
      perror("socket file descriptor");
    else
      perror("accept");
    exit(1);
  }
  _sock->client_ip = inet_ntoa(_sock->s_in.sin_addr);
}