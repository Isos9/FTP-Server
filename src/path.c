#include "includes/path.h"

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

  r_path = realpath(path, NULL);
  if (strlen(r_path) < strlen(_sock->dir_name))
  {
    write_protocole_s(_sock, "530 You can't go this way\n");
    return (NULL);
  }
  return (r_path);
}

char **get_curr_list()
{
  int i;
  FILE  *in;
  char buff[512];
  char **res;

  i = 0;
  res = malloc(sizeof(char*) * 64);
  in = popen("/bin/ls -l", "r");
  fgets(buff, sizeof(buff), in);
  while (fgets(buff, sizeof(buff) - 1, in) != NULL)
    res[i++] = strdup(buff);
  res[i] = NULL;
  pclose(in);
  return (res);
}