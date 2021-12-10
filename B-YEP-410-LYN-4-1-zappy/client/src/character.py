##
## EPITECH PROJECT, 2021
## B-YEP-410-LYN-4-1-zappy-
## File description:
## character
##

from client.src import lib

charac = lib.pygame.image.load("client/sprits/slime.png").convert_alpha()
charac = lib.pygame.transform.scale(charac, (90,90))

def move(x, y):
    charac.set_colorkey(lib.BLACK)
    lib.SCREEN.blit(charac, (x, y))