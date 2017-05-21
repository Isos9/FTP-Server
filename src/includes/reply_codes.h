/*
** reply_codes.h for ftp in /home/isos/Workspace/Epitech/PSU_2016_myftp/src/includes
** 
** Made by Sébastien Jacobin
** Login   <sebastien.jacobin@epitech.net>
** 
** Started on  Sun May 21 23:18:36 2017 Sébastien Jacobin
** Last update Sun May 21 23:18:40 2017 Sébastien Jacobin
*/

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
