##
## EPITECH PROJECT, 2020
## B-PSU-400-LYN-4-1-malloc-
## File description:
## Makefile
##

OBJS_NM	=	$(patsubst %.c, %.o, $(shell find src/nm -type f -name "*.c"))
OBJS_OBJ	=	$(patsubst %.c, %.o, $(shell find src/objdump -type f -name "*.c"))

INCLUDE = include

HFILE	=	$(wildcard $(INCLUDE)/*.h)

LIBPATH	=	lib/*/

NAME_NM	=	my_nm
NAME_OBJ	=	my_objdump

INC_FLAG	=	-I $(INCLUDE)

OBJ_FLAG	=	-g3
OBJ_FLAG	+=	-Wall -Wextra
OBJ_FLAG	+=	-Wno-gnu
OBJ_FLAG	+=	-march=native

DEBUG_FLAGS	=	-O0

CC	=	@clang
RM	=	@rm -f

$(OBJS): $(HFILE)

all: $(NAME_NM) $(NAME_OBJ)

$(NAME_NM): $(OBJS_NM)
	@$(MAKE) -C $(LIBPATH) --no-print-directory
	$(CC) -o $(NAME_NM) $(OBJS_NM) $(OBJ_FLAG) $(LIBPATH)*.a

$(NAME_OBJ): $(OBJS_OBJ)
	@$(MAKE) -C $(LIBPATH) --no-print-directory
	$(CC) -o $(NAME_OBJ) $(OBJS_OBJ) $(OBJ_FLAG) $(LIBPATH)*.a

nm: $(NAME_NM)

objdump: $(NAME_OBJ)

debug: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(DEBUG_FLAGS)

clean:
	@$(MAKE) clean -C $(LIBPATH) --no-print-directory
	@$(RM) $(OBJS_NM)
	@$(RM) $(OBJS_OBJ)
	@echo "\e[32m[ DONE ]\033[0m  Cleanned *o"

fclean: clean
	@$(MAKE) fclean -C $(LIBPATH) --no-print-directory
	@$(RM) $(NAME_NM) $(NAME_OBJ)
	@echo "\e[32m[ DONE ]\033[0m  Cleanned $(NAME_NM) $(NAME_OBJ)"

re:	fclean all

.c.o:	%.c
	@$(CC) -c $< -o $@ $(INC_FLAG) $(OBJ_FLAG) && echo "\e[32m[ DONE ] \033[0m" $< || echo "\e[91;5m[ FAIL ] \e[25m" $< "\033[0m"

.PHONY: all clean fclean re
