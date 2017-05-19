#ifndef DIR_H_
  #define DIR_H_

#include <dirent.h>
#include "reply_codes.h"
#include "path.h"

int pwd_cmd(my_sock *_sock, char **resp);
int type_cmd(my_sock *_sock, char **resp);
int  list_cmd(my_sock *_sock, char **resp);
int cwd_cmd(my_sock *_sock, char **resp);
int cdup_cmd(my_sock *_sock, char **resp);

#endif