#ifndef DIR_H_
  #define DIR_H_

#include "reply_codes.h"
#include "_socket.h"
int pwd_cmd(my_sock *_sock, char **resp);
int type_cmd(my_sock *_sock, char **resp);

#endif