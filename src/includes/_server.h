#ifndef MY_SERVER_H_
  #define MY_SERVER_H_

#include <signal.h>
#include <sys/wait.h>
#include "_socket.h"

int  init_server(my_sock *_sock);
int  handle_new_client(my_sock *_sock, pid_t pid);
int handle_client(my_sock *_sock);
void get_server_ip(my_sock *_sock);


#endif