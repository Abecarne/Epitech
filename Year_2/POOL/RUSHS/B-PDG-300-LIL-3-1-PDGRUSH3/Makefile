CFLAGS		=	-std=c++20 -Wall -Wextra -Werror

CFLAGS		=	-I./include/

VFLAGS		=	-s --log-file=valgrind_out.txt

LIB_SFML	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

LIB_NCURSES	=	-lncurses

CC			=	g++

SRC			=	src/main.cpp			\
				src/CpuG.cpp			\
				src/Cpu.cpp				\
				src/Ram.cpp				\
				src/Info.cpp			\
				src/Infos.cpp			\
				src/Module.cpp			\
				src/Display.cpp			\
				src/Network.cpp			\
				src/RamCore.cpp			\
				src/AllInfo.cpp			\
				src/NetworkG.cpp		\
				src/terminal.cpp

OBJ			=	$(SRC:.cpp=.o)

NAME		=	MyGKrellm

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIB_SFML) $(LIB_NCURSES)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -rf $(NAME)

debug:			$(OBJ)
				$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIB_SFML) -g
				valgrind $(VFLAGS) ./$(NAME)

run: 			all
				@./$(NAME)

re:				fclean all

.PHONY: 		all clean fclean test debug run re
