#ifndef LOGIN_H_
  #define LOGIN_H_

#include "_socket.h"
#include "reply_codes.h"


int user_cmd(my_sock *_sock, char **resp);
int passwd_cmd(my_sock *_sock, char **resp);
int  quit_cmd(my_sock *_sock, char **resp);

#endif