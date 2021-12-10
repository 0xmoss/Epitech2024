##
## EPITECH PROJECT, 2020
## auto completion
## File description:
## Makefile
##

NAME = autoCompletion

all:
	@cp $(NAME).py $(NAME)
	@chmod +x $(NAME)
	@printf "$(NAME) ready\n"

clean:
	@rm -rf ./src/__pycache__
	@rm -f $(NAME)
	@printf "$(NAME) cleanned\n"

fclean: clean

re: fclean all
