CC		=	gcc -W -Wall -Werror

SRC		=	src/main.c	\
			src/_socket.c	\
			src/_server.c

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