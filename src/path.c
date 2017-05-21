/*
** path.c for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 22:21:10 2017 Sébastien Jacobin
** Last update Sun May 21 22:27:52 2017 Sébastien Jacobin
*/

#include "includes/path.h"

char	*gen_real_path(my_sock *_sock, char *path)
{
  char	*res;

  res = malloc(sizeof(char) * (strlen(_sock->dir_name) + strlen(path) + 5));
  sprintf(res, "%s%s", _sock->dir_name, path);
  return (res);
}

void	init_path(my_sock *_sock, char *path)
{
  char	*root;

  root = getcwd(NULL, 0);
  _sock->dir_name = malloc(sizeof(char) * (strlen(path) + strlen(root) + 64));
  memset(_sock->dir_name, 0, strlen(path) + 1);
  sprintf(_sock->dir_name, "%s/%s", root, path);
  if (chdir(_sock->dir_name) == -1)
    {
      perror("chdir");
      exit(1);
    }
}

char	*check_path(my_sock *_sock, char *path)
{
  char	*r_path;

  if (!path)
    return (NULL);
  if (path[0] == '/')
    r_path = realpath(gen_real_path(_sock, path), NULL);
  else
    r_path = realpath(path, NULL);
  printf("r_path : %s\n", r_path);
  if (!r_path || (strlen(r_path) < strlen(_sock->dir_name)))
    return (NULL);
  return (r_path);
}

char	*check_path_up(my_sock *_sock, char *path)
{
  char	*r_path;
  char	*tmp_path;
  char	*ptr;

  tmp_path = malloc(sizeof(char) * (strlen(path) + 1024));
  if ((ptr = rindex(path, '/')))
    {
      if (path[0] == '/')
	sprintf(tmp_path, "%s%s", _sock->dir_name, cut_path(path, ptr - path));
      else
	sprintf(tmp_path, "%s/%s", _sock->dir_name, cut_path(path, ptr - path));
      if ((r_path = realpath(tmp_path, NULL)))
	{
	  if (strlen(r_path) >= strlen(_sock->dir_name))
	    return (path);
	  else
	    return (NULL);
	}
      else
	return (NULL);
    }
  return (path);
}

char	*cut_path(char *path, int len)
{
  int	i;
  char	*res;

  i = 0;
  res = malloc(sizeof(char) * (len + 1));
  while (i < len)
    {
      res[i] = path[i];
      i++;
    }
  res[i] = 0;
  return (res);
}
