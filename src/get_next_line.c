/*
** get_next_line.c for gnl in /home/isos/Workspace/Epitech/CPE_2016_getnextline
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Mon Nov 28 11:27:05 2016 Sébastien Jacobin
** Last update Sun Dec  4 14:44:51 2016 Sébastien Jacobin
*/

#include "includes/get_next_line.h"

int my_strlen(char *str)
{
  int i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	e;
  char	*res;

  i = 0;
  e = 0;
  res = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
  while (dest && dest[e] != '\0')
    {
      res[i] = dest[e];
      e = e + 1;
      i = i + 1;
    }
  e = 0;
  while (src && src[e] != '\n' && src[e] != '\0')
    {
      res[i] = src[e];
      e = e + 1;
      i = i + 1;
    }
  res[i] = '\0';
  return (res);
}

int	count_line(char *buff)
{
  int	i;
  int	e;

  i = 0;
  e = 0;
  while (buff && buff[i] != '\0')
    {
      if (buff[i] == '\n')
	e = e + 1;
      i = i  + 1;
    }
  return (e);
}

char	*get_line(char	*buff, int  pos)
{
  int	i;
  int   e;
  char	*res;

  i = 0;
  e = 0;
  res = malloc(sizeof(char) * (my_strlen(buff) + 1));
  res[0] = 0;
  while (buff[i] != '\0')
    {
      e = (buff[i] == '\n') ? e + 1: e;
      i = i + 1;
      if (e == pos || e == count_line(buff))
	return (my_strcat(res, &buff[i]));
    }
  res[i] = '\0';
  return (res);
}

char	*get_next_line(int fd)
{
  char	*r;
  ssize_t	size;
  static int	pos = 0;
  static char	buff[READ_SIZE];

  r = NULL;
  while (1)
    {
      if (pos >= count_line(buff))
	{
	  if (pos == count_line(buff) && (my_strlen(buff) != 0))
	    r = get_line(buff, pos);
	  size = read(fd, buff, READ_SIZE - 1);
	  buff[size] = '\0';
	  r = (size > 0) ? my_strcat(r, buff) : my_strlen(r) == 0 ? NULL : r;
	  pos = 0;
	  if (size <= 0)
	    return (r);
	}
      else
	r = get_line(buff, pos);
      if ((pos = pos + 1) <= count_line(buff))
	return (r);
    }
  return (r);
}
