##
## EPITECH PROJECT, 2022
## Anthony Becarne
## File description:
## Makefile
##

CFLAGS_CS	 	+=	-Iinclude/ -Ilibs/myteams

EFLAGS_CS		+=	-Wall -Wextra -Werror -g

LDFLAGS_CS	 	+=	-Llibs/myteams/ -lmyteams -Llibs/my/ -lmy -luuid

# Main Server files
SRC_S		=	server/src/main.c 									\
				server/src/init.c									\
				server/src/error.c									\
				server/src/teams/find.c								\
				server/src/teams/getter.c							\
				server/src/client/client.c							\
				server/src/server/server.c							\
				server/src/teams/add_users.c						\
				server/src/free_ressources.c						\
				server/src/client/commands.c						\
				server/src/client/commands2.c						\
				server/src/server/show_func.c						\
				server/src/client/commands3.c						\
				server/src/errors/infos_cmd.c						\
				server/src/errors/create_cmd.c						\
				server/src/errors/all_use_cmd.c						\
				server/src/client/linked_list.c						\
				server/src/errors/all_log_cmd.c						\
				server/src/errors/all_sub_cmd.c						\
				server/src/server/main_server.c						\
				server/src/errors/all_msg_cmd.c						\
				server/src/server/create_func.c						\
				server/src/send_datas/dispatch.c					\
				server/src/client/linked_list2.c					\
				server/src/send_datas/send_datas.c					\
				server/src/client/uuid_manipulation.c 				\
				server/src/client/all_cases_in_switch.c				\
				server/src/client/all_cases_in_switch2.c				\

# Main Client files
SRC_C		=	client/src/main.c 									\
				client/src/init.c									\
				client/src/error.c									\
				client/src/update.c									\
				client/src/main_client.c							\
				client/src/replies/help.c							\
				client/src/free_ressources.c						\
				client/src/replies/replies1.c						\
				client/src/replies/replies2.c						\
				client/src/replies/replies3.c						\
				client/src/replies/replies4.c						\
				client/src/replies/replies5.c						\
				client/src/replies/replies6.c						\
				client/src/replies/replies7.c						\
				client/src/replies/replies8.c						\
				client/src/replies/replies9.c						\
				client/src/replies/replies10.c						\
				client/src/store_datas/store1.c						\
				client/src/store_datas/store2.c						\
				client/src/store_datas/store3.c						\
				client/src/ask_datas/ask_to_serv.c					\
				client/src/store_datas/store_datas.c				\
				client/src/replies/check_response_from_server.c		\

OBJ_C		=	$(SRC_C:.c=.o)
OBJ_S		=	$(SRC_S:.c=.o)

NAME_C	=	myteams_cli
NAME_S	=	myteams_server

all:		$(NAME_C)	$(NAME_S)

$(NAME_C):	$(OBJ_C)
			gcc $(OBJ_C) -o $(NAME_C) $(EFLAGS_CS) $(CFLAGS_CS) $(LDFLAGS_CS)

$(NAME_S):	$(OBJ_S)
			gcc $(OBJ_S) -o $(NAME_S) $(EFLAGS_CS) $(CFLAGS_CS) $(LDFLAGS_CS)

clean:
			rm -f $(OBJ_C)
			rm -f $(OBJ_S)

fclean: 	clean
			rm -rf $(NAME_C)
			rm -rf $(NAME_S)

re:			fclean all

.PHONY:		all clean fclean re