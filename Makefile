NAME	=	sudoku-bi

SRC	=

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -Iincludes/

CFLAGS	=	-W -Wall -Wextra -pedantic -ansi

LIB_DIR	=	my

MK_LIB	=	@(cd $(LIB_DIR) && make)

MK_CLIB	=	@(cd $(LIB_DIR) && make clean)

MK_FLIB	=	@(cd $(LIB_DIR) && make fclean)

LIB	=	-L. -lmy

RM	=	rm -f

all	:	$(NAME)

$(NAME):	$(OBJ)
		$(MK_LIB)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean	:
		$(RM) $(OBJ)
		$(MK_CLIB)

fclean	:	clean
		$(RM) $(NAME)
		$(MK_FLIB)

re	:	fclean all

.PHONY	:	all clean fclean re
