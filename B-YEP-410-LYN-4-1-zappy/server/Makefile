##
## EPITECH PROJECT, 2021
## Makefile generated with Yumiko
## File description
## Makefile
##

SRC	=	$(shell find src -type f -name "*.c")

OBJ	=	$(patsubst %.c, %.o, $(SRC))

HFILE	=	$(shell find include -type f -name "*.h")

NAME	=	zappy_server

CFLAGS	=	-I include -g3 -Wall -Werror -Wextra -O3
LDFLAGS	=	-lm

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	cp $(NAME) ../$(NAME)

$(OBJ):	$(HFILE)

clean:
	@printf "\033[32m[ DONE ]\033[0m\tStart cleaning...\n"
	@rm -f $(OBJ)
	@printf "\033[32m[ DONE ]\033[0m\tFinished cleaning!\n"

fclean:
	@printf "\033[32m[ DONE ]\033[0m\tStart cleaning...\n"
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@rm -f ../$(NAME)
	@printf "\033[32m[ DONE ]\033[0m\tFinished cleaning!\n"

re:	fclean all

%.o:	%.c
	@$(CC) -c $< -o $@ $(CFLAGS) && printf "\033[32m[ DONE ]\t\033[0m%s\n" $< || printf "\033[91;5m[ FAIL ]\t\033[25m%s\033[0m\n" $<

.PHONY: all clean fclean re
