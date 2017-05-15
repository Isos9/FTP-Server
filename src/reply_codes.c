#include "includes/reply_codes.h"

proto_t create_proto(int proto, char *str)
{
  int i;
  proto_t res;

  i = 0;
  res.nbr = proto;
  res.msg = malloc(sizeof(char) * (strlen(str) + 1));
  while (str && str[i])
  {
    res.msg[i] = str[i];
    i++;
  }
  res.msg[i] = 0;
  return (res);
}

proto_t  *init_replies()
{
  proto_t *res;

  res = malloc(sizeof(proto_t) * 12);
  res[0] = create_proto(125, "Data connection already open; transfer starting.");
  res[1] = create_proto(150, "File status okay; about to open data connection.");
  res[2] = create_proto(200, "Command okay.");
  res[3] = create_proto(220, "Service ready for new user.");
  res[4] = create_proto(221, "Service closing control connection.");
  res[5] = create_proto(226, "Closing data connection.");
  res[6] = create_proto(230, "User logged in, proceed.");
  res[7] = create_proto(250, "Requested file action okay, completed.");
  res[8] = create_proto(257, "\"PATHNAME\" created.");
  res[9] = create_proto(331, "User name okay, need password.");
  res[10] = create_proto(332, "Need account for login.");
  res[11] = create_proto(0, "");

  return (res);
}

void  write_protocole(my_sock *_sock, int proto_num)
{
  int i;
  proto_t *proto;
  char *msg;

  i = 0;
  proto = init_replies();
  while (proto[i].nbr)
  {
    if (proto_num == proto[i].nbr)
    {
      msg = malloc(sizeof(char) * (strlen(proto[i].msg) + 1));
      memset(msg, 0, strlen(proto[i].msg));
      sprintf(msg, "%d %s\r\n", proto[i].nbr, proto[i].msg);
      write(_sock->client.fd, msg, strlen(msg));
      break;
    }
    i++;
  }
}


void  write_protocole_s(my_sock *_sock, char *str)
{
  write(_sock->client.fd, str, strlen(str));
}