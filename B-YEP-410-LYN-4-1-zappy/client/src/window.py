##
## EPITECH PROJECT, 2021
## client
## File description:
## window
##

from client.src import lib

def screen():
    lib.pygame.display.set_caption('Zappy')
    lib.SCREEN.fill(lib.WHITE)

def close(event, is_running):
    if event.type == lib.pygame.QUIT:
        is_running = False
    elif event.type == lib.pygame.KEYDOWN:
        if event.key == lib.pygame.K_ESCAPE:
            is_running = False
    return is_running