##
## EPITECH PROJECT, 2020
## B-CPP-300-LYN-3-1-CPPD03-
## File description:
## Makefile
##

OBJS	=		 $(patsubst %.c, %.o, $(wildcard ./*.c))

HFILE	=		 string.h

NAME	=		 libstring.a

CFLAGS  =		-g3
CFLAGS  +=		-Wall -Wextra -O3 -fno-builtin
CFLAGS	+=		-std=gnu11 -L. -lstring


CC		=		 @gcc
AR		=		 @ar rc
RM		=		 @rm -f

all:	 $(NAME)

$(NAME):	$(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(OBJS): $(HFILE)

clean:
	@$(RM) $(OBJS)
	@echo "\e[32m[ DONE ]\033[0m Cleanned"

fclean:
	@$(RM) $(OBJS)
	@rm -f $(NAME)
	@echo "\e[32m[ DONE ] \033[0m Cleanned"

re:	fclean all

.c.o:	%.c
	@$(CC) -c $< -o $@ $(CFLAGS) && echo "\e[32m[ DONE ] \033[0m" $< || echo "\e[91;5m[ FAIL ] \e[25m" $< "\033[0m"

.PHONY: all clean fclean re
