/*
** down_up_lst.c for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 22:24:45 2017 Sébastien Jacobin
** Last update Sun May 21 22:45:05 2017 Sébastien Jacobin
*/

#include "includes/down_up_lst.h"

void	download_data(my_sock *_sock, int fd)
{
  int		fd_d;
  socklen_t	size;
  char		*line;

  size = sizeof(_sock->s_in_pasv);
  if ((fd_d = accept(_sock->d_fd,
		     (struct sockaddr *)&_sock->s_in_pasv, &size)) == -1)
    {
      write_protocole_s(_sock, "426 no TCP connection\r\n");
      return;
    }
  write_protocole(_sock, 150);
  while ((line = get_next_line(fd)))
    {
      write(fd_d, line, strlen(line));
      write(fd_d, "\n", 1);
    }
  write_protocole(_sock, 226);
  _sock->pasv_mode = 0;
  close(fd_d);
  close(fd);
}

void	upload_data(my_sock *_sock, int fd)
{
  int		fd_d;
  socklen_t	size;
  char		*line;

  size = sizeof(_sock->s_in_pasv);
  if ((fd_d =
       accept(_sock->d_fd, (struct sockaddr *)&_sock->s_in_pasv, &size)) == -1)
    {
      perror("accept");
      exit(1);
    }
  write_protocole(_sock, 150);
  while ((line = get_next_line(fd_d)))
    {
      write(fd, line, strlen(line));
      write(fd, "\n", 1);
    }
  write_protocole(_sock, 226);
  _sock->pasv_mode = 0;
  close(fd_d);
  close(fd);
}

char	**get_curr_list(my_sock *_sock, char **resp)
{
  int	i;
  FILE	*in;
  char	buff[512];
  char	**res;
  char	*cmd;

  i = 0;
  res = malloc(sizeof(char*) * 64);
  cmd = malloc(sizeof(char) * 128);
  if (resp[1])
    {
      if (resp[1][0] == '/')
	resp[1] = gen_real_path(_sock, resp[1]);
      sprintf(cmd, "/bin/ls -l %s", resp[1]);
    }
  else
    sprintf(cmd, "/bin/ls -l");
  in = popen(cmd, "r");
  fgets(buff, sizeof(buff), in);
  while (fgets(buff, sizeof(buff) - 1, in) != NULL)
    res[i++] = strdup(buff);
  res[i] = NULL;
  pclose(in);
  return (res);
}
