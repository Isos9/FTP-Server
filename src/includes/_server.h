#ifndef MY_SERVER_H_
  #define MY_SERVER_H_

#include <signal.h>
#include <sys/wait.h>
#include "_socket.h"

void  exit_signal();
int  init_server(my_sock *_sock);
int  handle_new_client(my_sock *_sock, pid_t pid);
int handle_client(my_sock *_sock);


#endif