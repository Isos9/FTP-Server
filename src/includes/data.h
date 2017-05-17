#ifndef DATA_H_
  #define DATA_H_

#include "get_next_line.h"
#include "down_up.h"
#include "pasv.h"
#include "reply_codes.h"
#include "_socket.h"

int pasv_cmd(my_sock *_sock, char **resp);
int retr_cmd(my_sock *_sock, char **resp);


#endif