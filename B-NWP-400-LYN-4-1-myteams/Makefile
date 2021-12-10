##
## EPITECH PROJECT, 2020
## B-NWP-400-LYN-4-1-myteams-
## File description:
## Makefile
##

SERVER	=	src/server
CLIENT	=	src/client

all:	exportall	server	client

exportall:
	@export LD_LIBRARY_PATH=./libs/myteams

server:
	@make -C $(SERVER) --no-print-directory

client:
	@make -C $(CLIENT) --no-print-directory

clean:
	@make clean -C $(SERVER) --no-print-directory
	@make clean -C $(CLIENT) --no-print-directory

fclean:
	@make fclean -C $(SERVER) --no-print-directory
	@make fclean -C $(CLIENT) --no-print-directory

re:
	@make re -C $(SERVER) --no-print-directory
	@make re -C $(CLIENT) --no-print-directory

.PHONY:	all	exportall	server	client	clean	fclean	re
