/*
** data.c for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 22:23:47 2017 Sébastien Jacobin
** Last update Sun May 21 22:43:50 2017 Sébastien Jacobin
*/

#include "includes/data.h"

int	pasv_cmd(my_sock *_sock, char **resp)
{
  int	port;
  char	*msg;
  char	**ips;

  if (resp)
    {
      msg = malloc(sizeof(char) * 128);
      init_pasv_sock(_sock, &port);
      printf("port : %d\n", port);
      ips = split_ip(_sock);
      sprintf(msg, "227 Entering Passive Mode (%s,%s,%s,%s,%d,%d).\n",
	      ips[0], ips[1], ips[2], ips[3], port/256, port%256);
      _sock->pasv_mode = 1;
      write_protocole_s(_sock, msg);
    }
  return (0);
}

int	retr_cmd(my_sock *_sock, char **resp)
{
  int	fd;
  char	*path;

  if (resp)
    {
      if (_sock->pasv_mode)
	{
	  if ((path = check_path(_sock, resp[1])))
	    {
	      if ((fd = open(path, O_RDONLY)) != -1)
		download_data(_sock, fd);
	      else
		write_protocole_s(_sock, "550 Failed to open file\n");
	    } else
	    write_protocole_s(_sock, "550 Failed to open file\n");
	}
      else
	write_protocole_s(_sock, "530 Use PORT or PASV mode.\n");
    }
  return (0);
}

int	stor_cmd(my_sock *_sock, char **resp)
{
  int fd;
  char *path;

  if (resp)
  {
    if (_sock->pasv_mode)
    {
      if ((path = check_path_up(_sock, resp[1])))
      {
        if ((fd = open(path, O_CREAT | O_TRUNC | O_RDWR, S_IRWXU)) != -1)
          upload_data(_sock, fd);
        else
          write_protocole_s(_sock, "530 Can't create the file.\n");
      }
      else
        write_protocole_s(_sock, "530 Can't create the file.\n");
    }
    else
      write_protocole_s(_sock, "530 Use PORT or PASV mode.\n");
  }
  return (0);
}

int	dele_cmd(my_sock *_sock, char **resp)
{
  char	*path;
  if (resp)
    {
      if ((path = check_path(_sock, resp[1])))
	{
	  printf("path : %s\n", path);
	  if (remove(path) == -1)
	    {
	      perror("remove");
	      write_protocole_s(_sock, "550 Failed to delete file or directory.\n");
	      return (0);
	    }
	  write_protocole(_sock, 250);
	}
      else
	write_protocole_s(_sock, "550 Failed to delete file or directory.\n");
    }
  return (0);
}
