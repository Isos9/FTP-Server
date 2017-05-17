#ifndef PATH_H_
 #define PATH_H_

#include <limits.h>
#include "reply_codes.h"
#include "_socket.h"

void  init_path(my_sock *_sock, char *path);
char  *check_path(my_sock *_sock, char *path);
char **get_curr_list();

#endif