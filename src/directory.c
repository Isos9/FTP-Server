#include "includes/directory.h"

int pwd_cmd(my_sock *_sock, char **resp)
{
  size_t len_dir_name;
  char *msg;
  char *curr_dir;

  if (resp)
  {
    len_dir_name = strlen(_sock->dir_name);
    if (strlen(getcwd(NULL, 0)) <= len_dir_name)
      write_protocole_s(_sock, "257 \"/\"\n");
    else
    {
      curr_dir = getcwd(NULL, 0);
      msg = malloc(sizeof(char) * (strlen(&curr_dir[len_dir_name]) + 1));
      memset(msg, 0, strlen(&curr_dir[len_dir_name]) + 1);
      sprintf(msg, "257 \"%s\"\n", &curr_dir[len_dir_name]);
      write_protocole_s(_sock, msg);
    }
  }
  return (0);
}

int type_cmd(my_sock *_sock, char **resp)
{
  if (resp)
    write(_sock->client.fd, "200 Switching to Binary mode.\n", 30);
  return (0);
}

int  list_cmd(my_sock *_sock, char **resp)
{
  int i;
  socklen_t size;
  int fd_d;
  char **list;

  if (resp)
  {
    if (_sock->pasv_mode)
    {
      write_protocole(_sock, 150);
      i = -1;
      size = sizeof(_sock->s_in_pasv);
      fd_d = accept(_sock->d_fd, (struct sockaddr *)&_sock->s_in_pasv, &size);
      list = get_curr_list(_sock, resp);
      while (list && list[++i])
        write(fd_d, list[i], strlen(list[i]));
      close(fd_d);
      _sock->pasv_mode = 0;
      write_protocole(_sock, 226);
    }
    else
      write_protocole_s(_sock, "425 Use PORT or PASV mode.\n");
  }
  return (0);
}

int cwd_cmd(my_sock *_sock, char **resp)
{
  char  *path;

  if (resp)
  {
    if ((path = check_path(_sock, resp[1])))
    {
      if (chdir(path) == -1)
      {
        write_protocole_s(_sock, "550 Failed to change directory.\n");
        return (0);
      }
      write_protocole(_sock, 250);
    }
    else
      write_protocole_s(_sock, "550 Failed to change directory.\n");
  }
  return (0);
}

int cdup_cmd(my_sock *_sock, char **resp)
{
  resp[1] = strdup("..");
  cwd_cmd(_sock, resp);
  return (0);
}