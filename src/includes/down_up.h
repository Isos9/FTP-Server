#ifndef DOWN_H_
  #define DOWN_H_

#include "reply_codes.h"
#include "get_next_line.h"
#include "_socket.h"

void  download_data(my_sock *_sock, int fd);
void upload_data(my_sock *_sock, int fd);

#endif