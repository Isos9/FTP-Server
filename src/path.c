#include "includes/path.h"

char *gen_real_path(my_sock *_sock, char *path)
{
  char *res;

  res = malloc(sizeof(char) * (strlen(_sock->dir_name) + strlen(path) + 5));
  sprintf(res, "%s%s", _sock->dir_name, path);
  return (res);
}

void  init_path(my_sock *_sock, char *path)
{
  char *root;

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

char  *check_path(my_sock *_sock, char *path)
{
  char *r_path;

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

char **get_curr_list(my_sock *_sock, char **resp)
{
  int i;
  FILE  *in;
  char buff[512];
  char **res;
  char *cmd;

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