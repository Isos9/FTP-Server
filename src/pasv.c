#include "includes/pasv.h"

char *get_part(my_sock *_sock, int *i)
{
  int j;
  char *res;

  j = 0;
  res = malloc(sizeof(char) * 5);
  memset(res, 0, 5);
  while (_sock->serv_ip[*i] && _sock->serv_ip[*i] != '\n' && _sock->serv_ip[*i] != '.')
  {
    res[j++] = _sock->serv_ip[*i];
    *i = *i + 1;
  }
  res[*i] = 0;
  *i = *i + 1;
  return (res);
}

char **split_ip(my_sock *_sock)
{
  int i;
  int j;
  char **res;

  res = malloc(sizeof(char *) * 5);
  i = 0;
  j = 0;
  while (i < 5)
  {
    res[i] = get_part(_sock, &j);
    i++;
  }
  res[i] = NULL;
  return (res);
}

void  init_pasv_sock(my_sock *_sock, int *port)
{
  struct protoent   *pe;
  socklen_t len;


  len = sizeof(_sock->s_in_pasv);
  pe = getprotobyname("TCP");
  _sock->d_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  _sock->s_in_pasv.sin_family = AF_INET;
  _sock->s_in_pasv.sin_port = 0;
  _sock->s_in_pasv.sin_addr.s_addr = INADDR_ANY;
  bind(_sock->d_fd, (const struct sockaddr *)&_sock->s_in_pasv, sizeof(_sock->s_in_pasv));
  listen(_sock->d_fd, 1);
  if (getsockname(_sock->d_fd, (struct sockaddr *)&_sock->s_in_pasv, &len) != -1)
    *port = ntohs(_sock->s_in_pasv.sin_port);
}