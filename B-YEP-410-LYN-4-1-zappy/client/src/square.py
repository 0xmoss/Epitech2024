##
## EPITECH PROJECT, 2021
## client
## File description:
## square
##

import client.src.lib as lib

def create_square(x, y, s, i, j):
    square = {"x": x, "y": y, "img": s, "x_serv": i, "y_serv": j}
    lib.list_square.append(square)

def move_square(w):
    key = lib.pygame.key.get_pressed()
    lis =[]
    if key[lib.pygame.K_DOWN]:
        for i in range (len(lib.list_square)):
            lib.list_square[i]["y"] -= 100
        for i in lib.list_item:
            i.y -= 100
    if key[lib.pygame.K_UP]:
        for i in range (len(lib.list_square)):
            lib.list_square[i]["y"] += 100
        for i in lib.list_item:
            i.y += 100
    if key[lib.pygame.K_LEFT]:
        for i in range (len(lib.list_square)):
            lib.list_square[i]["x"] += 100
        for i in lib.list_item:
            i.x += 100
    if key[lib.pygame.K_RIGHT]:
        for i in range (len(lib.list_square)):
            lib.list_square[i]["x"] -= 100
        for i in lib.list_item:
            i.x -= 100
    for i in range (len(lib.list_square)):
        if lib.list_square[i]["x"] >= 100 and lib.list_square[i]["x"] <= w:
            square = lib.SCREEN.blit(lib.list_square[i]["img"], (lib.list_square[i]["x"], lib.list_square[i]["y"]))


def square_size(x_max, y_max):
    imgs = []
    grass = lib.pygame.image.load("client/sprits/grass.png").convert()
    grass = lib.pygame.transform.scale(grass, (100,100))
    dirt = lib.pygame.image.load("client/sprits/dirt.jpg").convert()
    dirt = lib.pygame.transform.scale(dirt, (100,100))
    gravel = lib.pygame.image.load("client/sprits/gravel.jpg").convert()
    gravel = lib.pygame.transform.scale(gravel, (100,100))
    imgs.append(grass)
    imgs.append(dirt)
    imgs.append(gravel)

    w, h = lib.pygame.display.get_surface().get_size()
    nb_square_y = 0
    nb_square_x = 0
    pos_y = 50
    size = 100
    while (nb_square_y < y_max and lib.display == True):
        pos_x = w - 400
        nb_square_x = 0
        while (nb_square_x < x_max):
            create_square(pos_x, pos_y, lib.random.choice(imgs), nb_square_x, nb_square_y)
            pos_x -= size
            nb_square_x += 1
        nb_square_y += 1
        pos_y += size
    lib.display = False
    move_square(w - 500)