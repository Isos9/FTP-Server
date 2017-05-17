#include "includes/down_up.h"

void  download_data(my_sock *_sock, int fd)
{
  int fd_d;
  socklen_t size;
  char *line;

  size = sizeof(_sock->s_in_pasv);
  if ((fd_d = accept(_sock->d_fd, (struct sockaddr *)&_sock->s_in_pasv, &size)) == -1)
  {
    perror("accept");
    exit(1);
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

void upload_data(my_sock *_sock, int fd)
{
  int fd_d;
  socklen_t size;
  char *line;

  size = sizeof(_sock->s_in_pasv);
  if ((fd_d = accept(_sock->d_fd, (struct sockaddr *)&_sock->s_in_pasv, &size)) == -1)
  {
    perror("accept");
    exit(1);
  }
  while ((line = get_next_line(fd_d)))
  {
    write(fd, line, strlen(line));
    write(fd, "\n", 1);
  }
  _sock->pasv_mode = 0;
  close(fd_d);
  close(fd);
  printf("upload complete\n");
}