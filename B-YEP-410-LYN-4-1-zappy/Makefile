##
## EPITECH PROJECT, 2020
## B-YEP-410-LYN-4-1-zappy-
## File description:
## Makefile
##

SERVER	=	server
CLIENT	=	client
AI		=	ai

all:	server	client	ai

server:
	@make -C $(SERVER) --no-print-directory

client:
	@make -C $(CLIENT) --no-print-directory

ai:
	@make -C $(AI) --no-print-directory

clean:
	@make clean -C $(SERVER) --no-print-directory
	@make clean -C $(CLIENT) --no-print-directory
	@make clean -C $(AI) --no-print-directory

fclean:
	@make fclean -C $(SERVER) --no-print-directory
	@make fclean -C $(CLIENT) --no-print-directory
	@make fclean -C $(AI) --no-print-directory

re:
	@make re -C $(SERVER) --no-print-directory
	@make re -C $(CLIENT) --no-print-directory
	@make re -C $(AI) --no-print-directory

.PHONY:	all	server	client	ai	clean	fclean	re