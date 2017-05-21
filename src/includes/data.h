#ifndef DATA_H_
  #define DATA_H_

#include "get_next_line.h"
#include "down_up_lst.h"
#include "pasv.h"
#include "reply_codes.h"
#include "_socket.h"
#include "path.h"

int pasv_cmd(my_sock *_sock, char **resp);
int retr_cmd(my_sock *_sock, char **resp);
int stor_cmd(my_sock *_sock, char **resp);
int dele_cmd(my_sock *_sock, char **resp);

#endif