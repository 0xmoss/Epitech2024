##
## EPITECH PROJECT, 2021
## src
## File description:
## item
##

import client.src.lib as lib

q0 = lib.pygame.image.load("client/assets/resources/q0.png").convert_alpha()
q1 = lib.pygame.image.load("client/assets/resources/q1.png").convert_alpha()
q2 = lib.pygame.image.load("client/assets/resources/q2.png").convert_alpha()
q3 = lib.pygame.image.load("client/assets/resources/q3.png").convert_alpha()
q4 = lib.pygame.image.load("client/assets/resources/q4.png").convert_alpha()
q5 = lib.pygame.image.load("client/assets/resources/q5.png").convert_alpha()
q6 = lib.pygame.image.load("client/assets/resources/q6.png").convert_alpha()

list_item = [
    {
        "item" : "food",
        "type" : q0,
    },
    {
        "item" : "linemate",
        "type" : q1,
    },
    {
        "item" : "deraumere",
        "type" : q2,
    },
    {
        "item" : "sibur",
        "type" : q3,
    },
    {
        "item" : "mendiane",
        "type" : q4,
    },
    {
        "item" : "phiras",
        "type" : q5,
    },
    {
        "item" : "thystame",
        "type" : q6,
    }
]

# def draw_rec(image, width, height, scale, square, steps_nbr):
#     current_time = lib.pygame.time.get_ticks()
#     if current_time - lib.last_update >= lib.animation_cooldown:
#         lib.frame += 1
#         lib.last_update = current_time
#         if lib.frame >= 7:
#             lib.frame = 0
#     animation_list = []
#     animation_steps = steps_nbr
#     for x in range(animation_steps):
#         animation_list.append(image.get_image(x, scale, scale, square, lib.BLACK))
#     i = lib.SCREEN.blit(animation_list[lib.frame], (width, height))
#     print (i)


def get_pos(k):
    for i in (lib.list_square):
        if i["x_serv"] == k["x"] and i["y_serv"] == k["y"]:
            return (i["x"], i["y"])

def parser_dic():
    for k in lib.item_event:
        if k["q0"] == 1:
            x, y = get_pos(k)
            pop_item("food", x, y)
        if k["q1"] == 1:
            x, y = get_pos(k)
            pop_item("linemate", x + 30, y)
        if k["q2"] == 1:
            x, y = get_pos(k)
            pop_item("deraumere", x + 60, y)
        if k["q3"] == 1:
            x, y = get_pos(k)
            pop_item("sibur", x, y + 30)
        if k["q4"] == 1:
            x, y = get_pos(k)
            pop_item("mendiane", x, y + 60)
        if k["q5"] == 1:
            x, y = get_pos(k)
            pop_item("phiras", x + 90, y)
        if k["q6"] == 1:
            x, y = get_pos(k)
            pop_item("thystame", x, y + 90)

def draw_item(x, y, item):
    item.set_colorkey(lib.BLACK)
    lib.list_item.append(lib.SCREEN.blit(item, (x, y)))

def pop_item(item, x, y):
    for iteme in list_item:
        if iteme["item"] == item:
            draw_item(x, y, iteme["type"])
    # for i in lib.list_item:
    #     print(i.x, i.y)
