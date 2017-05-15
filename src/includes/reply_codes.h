#ifndef REPLY_CODES_H_
  #define REPLY_CODES_H_

#include "_socket.h"

typedef struct proto_s {
  int nbr;
  char *msg;
} proto_t;

proto_t create_proto(int proto, char *str);
proto_t  *init_replies();
void  write_protocole(my_sock *_sock, int proto);
void  write_protocole_s(my_sock *_sock, char *str);

#endif