/*
** str_to_wordtab.h for ftp  in /home/isos/Workspace/Epitech/PSU_2016_myftp/src/includes
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 23:19:21 2017 Sébastien Jacobin
** Last update Sun May 21 23:19:30 2017 Sébastien Jacobin
*/

#ifndef STR_TO_WORDTAB_H_
  #define STR_TO_WORDTAB_H_

#include <string.h>
#include <stdlib.h>

char	**my_str_to_wordtab(char *str);
int	nb_words(char *str);
int	check(char *str, int e);


#endif
