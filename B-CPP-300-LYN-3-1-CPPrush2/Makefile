##
## EPITECH PROJECT, 2020
## B-CPP-300-LYN-3-1-CPPrush2-
## File description:
## Makefile
##

SRC	=	$(wildcard ./src/*.cpp) $(wildcard ./src/*/*.cpp)

SRC_TOY	=	$(wildcard ./src/TOY_main.cpp)
SRC_TOY	+=	$(wildcard ./src/Toy/Toy.cpp)
SRC_TOY	+=	$(wildcard ./src/Teddy/Teddy.cpp)
SRC_TOY	+=	$(wildcard ./src/LittlePony/LittlePony.cpp)

INC	=	$(wildcard ./src/*.hpp) $(wildcard ./src/*/*.hpp)

NAME	=	santa

RM	=	rm -rf

CFLAGS	=	-Wall -Wextra -O3 -fno-builtin -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(SRC) -o $(NAME) $(CFLAGS) $(INC)

toy:
	g++ $(SRC_TOY) -o santa_toy $(CFLAGS) $(INC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
