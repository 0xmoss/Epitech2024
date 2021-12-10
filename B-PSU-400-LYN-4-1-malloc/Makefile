##
## EPITECH PROJECT, 2020
## B-PSU-400-LYN-4-1-malloc-
## File description:
## Makefile
##

OBJS	=	$(patsubst %.c, %.o, $(wildcard ./src/*.c))

INCLUDE = include

HFILE	=	$(wildcard $(INCLUDE)/*.h)

NAME	=	libmy_malloc.so

INC_FLAG	=	-I $(INCLUDE)

OBJ_FLAG	=	-g3
OBJ_FLAG	+=	-Weverything
OBJ_FLAG	+=	-Wno-gnu
OBJ_FLAG	+=	-march=native
OBJ_FLAG	+=	-fPIC

DEBUG_FLAGS	=	-O0

LDFLAGS	= -shared

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

test: re
	@$(shell export LD_PRELOAD=./libmy_malloc.so)
	@$(shell ./test/test.out)
	@$(shell unset LD_PRELOAD)
	@echo "\e[32m[ DONE ]\033[0m  test"

re:	fclean all

.c.o:	%.c
	@$(CC) -c $< -o $@ $(INC_FLAG) && echo "\e[32m[ DONE ] \033[0m" $< || echo "\e[91;5m[ FAIL ] \e[25m" $< "\033[0m"

.PHONY: all clean fclean re