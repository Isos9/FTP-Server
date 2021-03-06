/*
** get_next_line.h for gnl in /home/isos/Workspace/Epitech/CPE_2016_getnextline
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Mon Nov 28 11:49:04 2016 Sébastien Jacobin
** Last update Sun Dec  4 02:15:40 2016 Sébastien Jacobin
*/

#ifndef READ_SIZE
# define READ_SIZE 64
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char *str);
char	*my_strcat(char *dest, char *src);
int	count_line(char *buff);
char	*get_line(char	*buff, int  pos);
char	*get_next_line(int fd);

#endif /*!READ_SIZE*/