SRC	=	pushswap.hs

OBJ	= 	*.hi \
		*.o

NAME	=	pushswap_checker

all:	$(NAME)

$(NAME):
	ghc -o $(NAME) $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re