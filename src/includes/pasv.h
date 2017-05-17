#ifndef PASV_H_
  #define PASV_H_

#include "_socket.h"

char *get_part(my_sock *_sock, int *i);
char **split_ip(my_sock *_sock);
void  init_pasv_sock(my_sock *_sock, int *port);


#endif