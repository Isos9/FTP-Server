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

  res = malloc(sizeof(proto_t) * 15);
  res[0] = create_proto(120, "Service ready in nnn minutes.");
  res[1] = create_proto(125, "Data connection already open; transfer starting.");
  res[2] = create_proto(150, "File status okay; about to open data connection.");
  res[3] = create_proto(200, "Command okay.");
  res[4] = create_proto(214, "Help message.");
  res[5] = create_proto(220, "Service ready for new user.");
  res[6] = create_proto(221, "Service closing control connection.");
  res[7] = create_proto(226, "Closing data connection.");
  res[8] = create_proto(227, "Entering Passive Mode (h1,h2,h3,h4,p1,p2).");
  res[9] = create_proto(230, "User logged in, proceed.");
  res[10] = create_proto(250, "Requested file action okay, completed.");
  res[11] = create_proto(257, "\"PATHNAME\" created.");
  res[12] = create_proto(331, "User name okay, need password.");
  res[13] = create_proto(332, "Need account for login.");
  res[14] = create_proto(0, "");
  printf("INIT_REPLIES\n");

  return (res);
}

void  write_protocole(my_sock *_sock, int proto_num)
{
  int i;
  proto_t *proto;
  char *msg;

  i = 0;
  proto = init_replies();
  msg = malloc(sizeof(char) * 128);
  memset(msg, 0, 128);
  while (proto[i].nbr)
  {
    if (proto_num == proto[i].nbr)
    {
      sprintf(msg, "%d %s\n", proto[i].nbr, proto[i].msg);
      write(_sock->client.fd, msg, strlen(msg));
      break;
    }
    i++;
  }
}