##
## EPITECH PROJECT, 2020
## B-YEP-410-LYN-4-1-zappy-
## File description:
## Makefile
##

NAME = zappy_client

all:
	@chmod +x $(NAME)
	@printf "\033[32m[ DONE ]\033[0m\tAdded rights\n"
	@cp $(NAME) ../$(NAME)
	@printf "\033[32m[ DONE ]\033[0m\tCopied\n"

clean:
	@rm ../$(NAME)
	@printf "\033[32m[ DONE ]\033[0m  Cleanned $(NAME)\n"

fclean:	clean

re:	fclean all

.PHONY: all clean fclean re