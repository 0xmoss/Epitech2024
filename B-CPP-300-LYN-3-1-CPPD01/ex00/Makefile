##
## EPITECH PROJECT, 2020
## B-CPP-300-LYN-3-1-CPPD01-
## File description:
## Makefile
##

SRC	=	z.c

OBJ	=	$(SRC:.c=.o)

NAME	=	z

RM	=	rm -rf

CFLAGS	=	-std=gnu11 -Wall -Wextra -I include

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(OBJ)

re: fclean all
