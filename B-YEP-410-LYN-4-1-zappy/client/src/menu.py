##
## EPITECH PROJECT, 2021
## client
## File description:
## menu
##

from client.src import lib

b_x = 0
b_y = 0
s_x = 0
s_y = 0

def background():
    return(lib.pygame.image.load("client/sprits/backgroudmenu.jpg").convert())

def start_button_click():
    global b_x
    global b_y
    global s_x
    global s_y
    mouse = lib.pygame.mouse.get_pos()
    if lib.pygame.mouse.get_pressed()[0]:
        if (b_x <= mouse[0] and mouse[0] <= b_x + s_x
        and b_y <= mouse[1] and mouse[1] <= b_y + s_y):
            if len(lib.ip) == 0 or len(lib.port) == 0:
                lib.timeout = 1
                lib.game_state = 3
                return
            lib.timeout = 1
            lib.game_state = 1

def settings_button_click():
    global b_x
    global b_y
    global s_x
    global s_y
    mouse = lib.pygame.mouse.get_pos()
    if lib.pygame.mouse.get_pressed()[0]:
        if (b_x <= mouse[0] and mouse[0] <= b_x + s_x
        and b_y <= mouse[1] and mouse[1] <= b_y + s_y):
            lib.timeout = 1
            lib.game_state = 2

def quit_button_click():
    global b_x
    global b_y
    global s_x
    global s_y
    mouse = lib.pygame.mouse.get_pos()
    if lib.pygame.mouse.get_pressed()[0]:
        if (b_x <= mouse[0] and mouse[0] <= b_x + s_x
        and b_y <= mouse[1] and mouse[1] <= b_y + s_y):
            lib.IS_RUNNING = False

def buttons(w, h):
    global b_x
    global b_y
    global s_x
    global s_y
    buttons_list = {
        'START': {'x': 300, 'y': 75},
        'SETTINGS': {'x': 200, 'y': 75},
        'QUIT': {'x': 200, 'y': 75},
    }
    font = lib.pygame.font.SysFont('Arial', 30)
    i = 0
    for text in buttons_list:
        x = buttons_list[text]['x']
        y = buttons_list[text]['y']
        z = len(buttons_list)
        if z == 0:
            z = 1
        rect = lib.pygame.draw.rect(lib.SCREEN, lib.GREY, ((w/2) - (x/2), ((h/z) - (y/2)) + i, x, y), 10)
        lib.SCREEN.blit(font.render(text, True, lib.WHITE), ((w/2) - (x/2) + 10, ((h/z) - (y/2/2)) + i))
        b_x = rect.x
        b_y = rect.y
        s_x = x
        s_y = y
        if lib.timeout == 0:
            try: eval(text.lower() + "_button_click" + "()")
            except: i = i
        i+=y + 25

def menu():
    w, h = lib.pygame.display.get_surface().get_size()
    bg_img = background()
    bg_img = lib.pygame.transform.scale(bg_img, (w, h))
    lib.SCREEN.blit(bg_img, [0, 0])
    buttons(w, h)