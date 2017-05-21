/*
** main.c for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 22:13:05 2017 Sébastien Jacobin
** Last update Sun May 21 22:13:12 2017 Sébastien Jacobin
*/

#include "includes/path.h"
#include "includes/_server.h"

int	main(int ac, char **av)
{
  if (ac != 3)
    return (0);
  my_sock mySock;

  mySock.port = atoi(av[1]);
  init_path(&mySock, av[2]);
  get_server_ip(&mySock);
  printf("serv_ip : %s", mySock.serv_ip);
  printf("path : %s\n", mySock.dir_name);
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
