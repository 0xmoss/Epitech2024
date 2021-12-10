##
## EPITECH PROJECT, 2020
## B-PSU-402-LYN-4-1-strace-
## File description:
## Makefile
##

OBJS		=	$(patsubst %.c, %.o, $(shell find src/* -type f -name "*.c"))

INCLUDE 	= 	include

HFILE		=	$(wildcard $(INCLUDE)/*.h)

NAME		=	strace

INC_FLAG	=	-I $(INCLUDE)

CFLAG	=	-g3
CFLAG	+=	-Weverything
CFLAG	+=	-Wno-gnu
CFLAG	+=	-march=native

DEBUG_FLAGS	=	-O0

INC_FLAG	=	-I $(INCLUDE)

CC	=	@clang
RM	=	@rm -f

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(OBJS): $(HFILE)

debug: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(DEBUG_FLAGS)

clean:
	@$(RM) $(OBJS)
	@echo "\e[32m[ DONE ]\033[0m  Cleanned *o"

fclean: clean
	@$(RM) $(NAME)
	@echo "\e[32m[ DONE ]\033[0m  Cleanned $(NAME)"

re:	fclean all

.c.o:	%.c
	@$(CC) -c $< -o $@ $(INC_FLAG) $(CFLAG) && echo "\e[32m[ DONE ] \033[0m" $< || echo "\e[91;5m[ FAIL ] \e[25m" $< "\033[0m"

.PHONY: all clean fclean re