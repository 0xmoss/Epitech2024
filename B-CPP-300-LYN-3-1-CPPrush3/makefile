##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## to make project
##

CC	=	g++
ECHO	=	echo -e

COLOR	=   31
LIGHT   =   \e[1;0m
BOLD    =   \e[1;1m
GREEN   =   \e[1;32m
WHITE   =   \e[1;37m
DEFAULT =   \e[1;37m

INFO    =   $(BOLD)$(GREEN)[INFO]\t$(WHITE)
WARNING =   $(BOLD)$(YELLOW)[WARNING]\t$(WHITE)
ERROR   =   $(BOLD)$(RED)[ERROR]\t$(WHITE)

SRC	=	$(wildcard src/*.cpp)

TEST	=	$(wildcard test/*.cpp)

OBJ	=	$(patsubst %.cpp, %.o, $(SRC))

TOBJ	=	$(patsubst %.cpp, %.o, $(TEST))

CFLAGS  =       -I ./include
CFLAGS  +=      -g3
CFLAGS  +=      -Wall -Wextra -O3 -fno-builtin
CFLAGS  +=      -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS  +=      -lncurses

NAME	=	MyGKrellm

$(NAME):	$(OBJ)
	@echo -en "\e[1m\e[38;2"
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@$(ECHO) "$(INFO)Compilation terminée !$(DEFAULT)"

test:	$(TOBJ)
	@echo -en "\e[1m\e[38;2"
	$(CC) $(TOBJ) $(CFLAGS) -o test.out
	@$(ECHO) "$(INFO)Compilation terminée !$(DEFAULT)"

$(OBJ): %.o : %.cpp
	@echo -en "\e[1m\e[38;2"
	$(CC) $(CFLAGS) -g -c $< -o $@

$(TOBJ): %.o : %.cpp
	@echo -en "\e[1m\e[38;2"
	$(CC) $(CFLAGS) -g -c $< -o $@

all:	$(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@$(ECHO) "$(INFO)Fichiers supprimés !$(DEFAULT)"
	@echo -e "\033[00m"

fclean:	clean
	@rm -f $(NAME)

tclean:
	@rm -f $(TOBJ)
	@rm -f test.out
	@$(ECHO) "$(INFO)Fichiers supprimés !$(DEFAULT)"
	@echo -e "\033[00m"

tfclean:	tclean
	@rm -f $(NAME)

re:	fclean all
