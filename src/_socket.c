/*
** _socket.c for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 22:14:32 2017 Sébastien Jacobin
** Last update Sun May 21 22:42:45 2017 Sébastien Jacobin
*/

#include "includes/_socket.h"

void	init_sock(my_sock *_sock)
{
  struct protoent   *pe;

  _sock->d_fd = -2;
  _sock->pasv_mode = 0;
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

void	bind_sock(my_sock *_sock)
{
  if (bind(_sock->fd, (const struct sockaddr *)&_sock->s_in,
	   sizeof(_sock->s_in)) == -1)
    {
      if (close(_sock->fd) == -1)
	perror("socket file descriptor");
      else
	perror("bind");
      exit(1);
    }
}

void	listen_sock(my_sock *_sock)
{
  if (listen(_sock->fd, 20) == -1)
    {
      if (close(_sock->fd) == -1)
	perror("socket file descriptor");
      else
	perror("listen");
      exit(1);
    }
}

int	accept_c(my_sock *_sock)
{
  unsigned int size;

  size = sizeof(_sock->s_in);
  _sock->client.fd = accept(_sock->fd, (struct sockaddr *)&_sock->s_in, &size);
  return (_sock->client.fd);
}
