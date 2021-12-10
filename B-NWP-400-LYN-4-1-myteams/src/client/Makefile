##
## EPITECH PROJECT, 2021
## Makefile generated with Yumiko
## File description
## Makefile
##

OBJ	=	$(patsubst %.c, %.o, $(shell find src -type f -name "*.c"))

HFILE	=	$(patsubst %.c, %.o, $(shell find include -type f -name "*.h"))

LIB_PATH	= 	lib/

LIBNAME		=	phaseout

LIB 		= 	$(shell find $(LIB_PATH)* -type f -name "*.a"

NAME	=	../../myteams_cli

CFLAGS	=	-I include -I ../include -g3
CFLAGS	+=	-I ../../libs/myteams -O3

LDFLAGS	=	-L ../../libs/myteams/
LDLIBS 	= 	-lmyteams -luuid

CC	=	gcc

RM	=	@rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(MAKE) -C $(LIB_PATH)$(LIBNAME) --no-print-directory
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS) $(LIB_PATH)$(LIBNAME)/*.a

$(OBJ):	$(HFILE)

clean:
	@$(RM) $(OBJ)
	@printf "\e[32m[ DONE ]\033[0m  Cleanned\n"

fclean:
	@$(MAKE) fclean -C $(LIB_PATH)$(LIBNAME) --no-print-directory
	@$(RM) $(OBJ)
	@$(RM) $(NAME)
	@printf "\e[32m[ DONE ]\033[0m  Cleanned\n"

re:	fclean all

.c.o:	%.c
	@$(CC) -c $< -o $@ $(CFLAGS) && echo -e "\e[32m[ DONE ] \033[0m" $< || echo -e "\e[91;5m[ FAIL ] \e[25m" $< "\033[0m\n"

.PHONY: all clean fclean re
