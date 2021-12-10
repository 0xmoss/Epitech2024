##
## EPITECH PROJECT, 2021
## Makefile generated with Yumiko
## File description
## Makefile
##

OBJ	=	$(patsubst %.c, %.o, $(shell find src -type f -name "*.c"))

HFILE	=	$(patsubst %.c, %.o, $(shell find include -type f -name "*.h"))

NAME	=	../../myteams_server

CFLAGS	=	-I include -I ../include -g3 -Wall -Werror -Wextra
CFLAGS	+=	-I ../../libs/myteams -O3

LDFLAGS	=	-L ../../libs/myteams/
LDLIBS 	= 	-lmyteams -luuid

CC	=	gcc

RM	=	@rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS) $(LIBPATH) $(LIBNAME)

$(OBJ):	$(HFILE)

clean:
	@$(RM) $(OBJ)
	@echo -e "\e[32m[ DONE ]\033[0m  Cleanned"

fclean:
	@$(RM) $(OBJ)
	@$(RM) $(NAME)
	@echo -e "\e[32m[ DONE ]\033[0m  Cleanned"

re:	fclean all

.c.o:	%.c
	@$(CC) -c $< -o $@ $(CFLAGS) && echo -e "\e[32m[ DONE ] \033[0m" $< || echo -e "\e[91;5m[ FAIL ] \e[25m" $< "\033[0m"

.PHONY: all clean fclean re
