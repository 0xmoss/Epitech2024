##
## EPITECH PROJECT, 2020
## B-OOP-400-LYN-4-1-arcade-
## File description:
## Makefile
##

OBJS	:=	$(patsubst %.cpp, %.o, $(shell find ./src/* -type f -name "*.cpp"))

INCLUDE	=	include

HFILE	=	$(wildcard $(INCLUDE)/*.hpp)

NAME	=	arcade_ncurses.so

INC_FLAG	=	-I $(INCLUDE)

OBJ_FLAG	=	-g3 -std=c++11
OBJ_FLAG	+=	-Weverything
OBJ_FLAG	+=	-Wno-gnu -fPIC
OBJ_FLAG	+=	-march=native

DEBUG_FLAGS	=	-O0

CC	=	@clang++
RM	=	@rm -f

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lncurses -shared -g3 -std=c++11

$(OBJS): $(HFILE)

debug: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(OBJ_FLAG) $(DEBUG_FLAGS)

clean:
	@$(RM) $(OBJS)
	@echo "\e[32m[ DONE ]\033[0m  Cleanned *o"

fclean: clean
	@$(RM) $(NAME)
	@echo "\e[32m[ DONE ]\033[0m  Cleanned $(NAME)"

re:	fclean all

.cpp.o:	%.cpp
	@$(CC) -c $< -o $@ $(INC_FLAG) $(OBJ_FLAG) && echo "\e[32m[ DONE ] \033[0m" $< || echo "\e[91;5m[ FAIL ] \e[25m" $< "\033[0m"

.PHONY: all clean fclean re
