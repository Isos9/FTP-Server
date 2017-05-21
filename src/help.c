/*
** help.c for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 22:26:46 2017 Sébastien Jacobin
** Last update Sun May 21 22:27:24 2017 Sébastien Jacobin
*/

#include "includes/help.h"

int	feat_cmd(my_sock *_sock, char **resp)
{
  if (resp)
    {
      write(_sock->client.fd, "211-TEST\n", 9);
      write(_sock->client.fd, "211 End\n", 8);
    }
  return (0);
}

int	help_cmd(my_sock *_sock, char **resp)
{
  if (resp)
    {
      write(_sock->client.fd, "214-Help\n", 9);
      write(_sock->client.fd, "214 End\n", 8);
    }
  return (0);
}
