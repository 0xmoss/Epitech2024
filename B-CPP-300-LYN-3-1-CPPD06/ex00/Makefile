##
## EPITECH PROJECT, 2020
## B-CPP-300-LYN-3-1-CPPD06-
## File description:
## Makefile
##

SRC	=	$(wildcard ./*.cpp)

NAME	=	my_cat

RM	=	rm -rf

CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(SRC) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
