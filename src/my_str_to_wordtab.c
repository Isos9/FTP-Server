/*
** my_str_to_wordtab.c for Day08 in /home/jacobin_s/CPool_Day08/task04
** 
** Made by Sébastien Jacobin
** Login   <jacobin_s@epitech.net>
** 
** Started on  Thu Oct 13 09:30:59 2016 Sébastien Jacobin
** Last update Sun Dec  4 23:43:02 2016 Sébastien Jacobin
*/

#include "includes/str_to_wordtab.h"

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	e;
  int	o;
  char	**res;

  i = 0;
  e = 0;
  o = 0;
  res = malloc(sizeof(char *) * (nb_words(str) + 1));
  while (str[e] != '\0')
    {
      if (check(str, e) == 1)
	{
	  res[i] = malloc(sizeof(char) * (strlen(str) + 1));
          memset(res[i], 0, strlen(str) + 1);
	  while (check(str, e) == 1)
	    res[i][o++] = str[e++];
	  i = i + 1;
	}
      o = 0;
      if (str[e] != '\0')
	e = e + 1;
    }
  res[nb_words(str)] = '\0';
  return (res);
}

int	nb_words(char *str)
{
  int	e;
  int	nb;

  e = 0;
  nb = 0;
  while (str && str[e] != '\0')
    {
      while (check(str, e) == 1)
	{
	  if (check(str, e + 1) != 1)
	    {
	      nb = nb + 1;
	    }
	  e = e + 1;
	}
      if (str[e] != '\0')
	{
	  e = e + 1;
	}
    }
  return (nb);
}

int	check(char *str, int e)
{
  if (str[e] > 32 && str[e] < 127)
      return (1);
  return (0);
}
