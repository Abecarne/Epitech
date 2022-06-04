##
## EPITECH PROJECT, 2020
## Anthony Becarne
## File description:
## Makefile
##

CFLAGS	= -W -Wall -Wextra -I./include/ -Llib/my -lmy -g

SRC		=	env.c			\
			main.c 			\
			path.c 			\
			exit.c			\
			pipe.c			\
			exec.c 			\
			clean.c			\
			parse.c			\
			error.c			\
			setenv.c		\
			get_cmd.c		\
			init_var.c		\
			builtins.c		\
			built_cd.c		\
			unsetenv.c		\
			pipe_exec.c		\
			pipe_exec2.c	\
			check_pipe.c	\
			redir_left.c	\
			valid_pipe.c	\
			valid_redir.c	\
			redir_right.c

OBJ		=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			make -C lib/my clean
			gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
			rm -f $(OBJ)

fclean: clean
			rm -rf $(NAME)
			make -C lib/my fclean

re:		fclean all