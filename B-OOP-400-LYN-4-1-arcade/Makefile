##
## EPITECH PROJECT, 2020
## B-OOP-400-LYN-4-1-arcade-
## File description:
## Makefile
##

OBJS	:=	$(patsubst %.cpp, %.o, $(shell find ./src/* -type f -name "*.cpp"))

INCLUDE	=	include
LIB_PATH=	lib

HFILE	=	$(wildcard $(INCLUDE)/*.hpp)

## GAMES
GAMES_PATH	= $(LIB_PATH)/games

## GRAPHICAL
NCURSES_PATH	= $(LIB_PATH)/graphicals/ncurses

NAME	=	arcade

INC_FLAG	=	-I $(INCLUDE)

OBJ_FLAG	=	-g3 -std=c++11
OBJ_FLAG	+=	-Weverything
OBJ_FLAG	+=	-Wno-gnu
OBJ_FLAG	+=	-march=native

DEBUG_FLAGS	=	-O0

CC	=	@clang++
RM	=	@rm -f

all: graphicals core

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -ldl -g3 -std=c++11

$(OBJS): $(HFILE)

clean:
	@echo "\e[33m[ .... ]\033[0m  Cleanning *o"
	@$(RM) $(OBJS)
	@echo "\e[32m[ DONE ]\033[0m  Cleanned *o"

fclean: clean
	@echo "\e[33m[ .... ]\033[0m  Cleanning $(NAME)"
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(NCURSES_PATH) --no-print-directory
	@echo "\e[32m[ DONE ]\033[0m  Cleanned $(NAME)"

re:	fclean all

core: $(NAME)

games:
	@echo "\e[33m[ .... ]\033[0m  Compiling games"
	@$(MAKE) -C $(GAMES_PATH) --no-print-directory
	@echo "\e[32m[ DONE ]\033[0m  Games compiled"

graphicals:
	@echo "\e[33m[ .... ]\033[0m  Compiling graphicals"
	@$(MAKE) -C $(NCURSES_PATH) --no-print-directory
	@echo "\e[32m[ DONE ]\033[0m  Graphicals compiled"

.cpp.o:	%.cpp
	@$(CC) -c $< -o $@ $(INC_FLAG) $(OBJ_FLAG) && echo "\e[32m[ DONE ] \033[0m" $< || echo "\e[91;5m[ FAIL ] \e[25m" $< "\033[0m"

debug: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(OBJ_FLAG) $(DEBUG_FLAGS)

.PHONY: all clean fclean re
