/*
** _server.c for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 22:13:30 2017 Sébastien Jacobin
** Last update Sun May 21 22:36:53 2017 Sébastien Jacobin
*/

#include "includes/str_to_wordtab.h"
#include "includes/cmd_client.h"
#include "includes/_server.h"

void	get_server_ip(my_sock *_sock)
{
  FILE  *in;
  char buff[512];

  in = popen("ip addr | grep 'state UP' -A2 | tail -n1 "
                     "| awk '{print $2}' | cut -f1  -d'/'", "r");
  fgets(buff, sizeof(buff) - 1, in);
  _sock->serv_ip = strdup(buff);
}

int	init_server(my_sock *_sock)
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

int	handle_new_client(my_sock *_sock, pid_t pid)
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

int	handle_client(my_sock *_sock)
{
  char **resp;

  write_protocole_s(_sock,"220 Hello !\r\n");
  while (read(_sock->client.fd, _sock->client.buffer, 1024))
    {
      if (_sock->client.buffer[0] != '\r')
	{
	  resp = my_str_to_wordtab(_sock->client.buffer);
	  if (exec_cmd(_sock, resp) == -1)
	    break;
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
