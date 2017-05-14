CC		=	gcc -W -Wall -Werror

SRC		=	src/main.c	\
			src/_socket.c	\
			src/_server.c	\
			src/my_str_to_wordtab.c	\
			src/cmd_client.c	\
			src/login.c	\
			src/reply_codes.c

OBJ		=	$(SRC:.c=.o)

NAME	=	server

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all