##
## EPITECH PROJECT, 2020
## myftp
## File description:
## Makefile
##

OBJS		=	$(patsubst %.c, %.o, $(shell find src/* -type f -name "*.c"))

INCLUDE 	= 	include

LIB_PATH	= 	lib/

LIBNAME		=	phaseout

LIB 		= 	$(shell find $(LIB_PATH)* -type f -name "*.a"

HFILE		=	$(wildcard $(INCLUDE)/*.h)

NAME		=	myftp

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
	@$(MAKE) -C $(LIB_PATH)$(LIBNAME) --no-print-directory
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(LIB_PATH)$(LIBNAME)/*.a

$(OBJS): $(HFILE)

debug: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(DEBUG_FLAGS)

clean:
	@$(RM) $(OBJS)
	@echo "\e[32m[ DONE ]\033[0m  Cleanned *o"

fclean: clean
	@$(MAKE) fclean -C $(LIB_PATH)$(LIBNAME) --no-print-directory
	@$(RM) $(NAME)
	@echo "\e[32m[ DONE ]\033[0m  Cleanned $(NAME)"

re:	fclean all

.c.o:	%.c
	@$(CC) -c $< -o $@ $(INC_FLAG) $(CFLAG) && echo "\e[32m[ DONE ] \033[0m" $< || echo "\e[91;5m[ FAIL ] \e[25m" $< "\033[0m"

.PHONY: all clean fclean re