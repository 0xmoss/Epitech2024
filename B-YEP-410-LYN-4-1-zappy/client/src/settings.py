##
## EPITECH PROJECT, 2021
## client
## File description:
## settings
##

from client.src import lib

b_x = 0
b_y = 0
s_x = 0
s_y = 0

def background():
    return(lib.pygame.image.load("client/sprits/backgroudsettings.jpg").convert())

def ipport_button_click():
    global b_x
    global b_y
    global s_x
    global s_y
    mouse = lib.pygame.mouse.get_pos()
    if lib.pygame.mouse.get_pressed()[0]:
        if (b_x <= mouse[0] and mouse[0] <= b_x + s_x
        and b_y <= mouse[1] and mouse[1] <= b_y + s_y):
            lib.timeout = 1
            lib.game_state = 3

def sound_button_click():
    global b_x
    global b_y
    global s_x
    global s_y
    mouse = lib.pygame.mouse.get_pos()
    if lib.pygame.mouse.get_pressed()[0]:
        if (b_x <= mouse[0] and mouse[0] <= b_x + s_x
        and b_y <= mouse[1] and mouse[1] <= b_y + s_y):
            lib.timeout = 1
            if lib.mute: lib.mute = False
            elif not lib.mute: lib.mute = True

def back_button_click():
    global b_x
    global b_y
    global s_x
    global s_y
    mouse = lib.pygame.mouse.get_pos()
    if lib.pygame.mouse.get_pressed()[0]:
        if (b_x <= mouse[0] and mouse[0] <= b_x + s_x
        and b_y <= mouse[1] and mouse[1] <= b_y + s_y):
            lib.timeout = 1
            if lib.game_state == 2: lib.game_state = 0
            if lib.game_state == 3: lib.game_state = 2

def buttons(w, h):
    global b_x
    global b_y
    global s_x
    global s_y
    buttons_list = {
        'IP/PORT': {'x': 200, 'y': 75},
        'SOUND': {'x': 200, 'y': 75},
        'BACK': {'x': 300, 'y': 75},
    }
    font = lib.pygame.font.SysFont('Arial', 30)
    i = 0
    for text in buttons_list:
        x = buttons_list[text]['x']
        y = buttons_list[text]['y']
        z = len(buttons_list)
        if z == 0:
            z = 1
        if text == 'SOUND' and lib.mute: rect = lib.pygame.draw.rect(lib.SCREEN, lib.RED, ((w/2) - (x/2), ((h/z) - (y/2)) + i, x, y), 10)
        else: rect = lib.pygame.draw.rect(lib.SCREEN, lib.GREY, ((w/2) - (x/2), ((h/z) - (y/2)) + i, x, y), 10)
        lib.SCREEN.blit(font.render(text, True, lib.WHITE), ((w/2) - (x/2) + 10, ((h/z) - (y/2/2)) + i))
        b_x = rect.x
        b_y = rect.y
        s_x = x
        s_y = y
        if lib.timeout == 0:
            try: eval(text.lower().replace('/', '') + "_button_click" + "()")
            except: i = i
        i+=y + 25

def ip_button_click():
    global b_x
    global b_y
    global s_x
    global s_y
    mouse = lib.pygame.mouse.get_pos()
    if lib.pygame.mouse.get_pressed()[0]:
        if (b_x <= mouse[0] and mouse[0] <= b_x + s_x
        and b_y <= mouse[1] and mouse[1] <= b_y + s_y):
            lib.timeout = 1
            lib.ip_active   = True
            lib.port_active = False
        else: lib.ip_active = False

def port_button_click():
    global b_x
    global b_y
    global s_x
    global s_y
    mouse = lib.pygame.mouse.get_pos()
    if lib.pygame.mouse.get_pressed()[0]:
        if (b_x <= mouse[0] and mouse[0] <= b_x + s_x
        and b_y <= mouse[1] and mouse[1] <= b_y + s_y):
            lib.timeout = 1
            lib.port_active   = True
            lib.ip_active     = False
        else: lib.port_active = False

def ip_buttons(w, h):
    global b_x
    global b_y
    global s_x
    global s_y
    buttons_list = {
        'IP:': {'x': 450, 'y': 75},
        'PORT:': {'x': 450, 'y': 75},
        'BACK': {'x': 200, 'y': 75},
    }
    font = lib.pygame.font.SysFont('Arial', 30)
    i = 0
    for text in buttons_list:
        x = buttons_list[text]['x']
        y = buttons_list[text]['y']
        z = len(buttons_list)
        if z == 0:
            z = 1
        if text == 'BACK':
            rect = lib.pygame.draw.rect(lib.SCREEN, lib.GREY, ((w/2) - (x/2), ((h/z) - (y/2)) + i, x, y), 10)
            lib.SCREEN.blit(font.render(text, True, lib.WHITE), ((w/2) - (x/2) + 10, ((h/z) - (y/2/2)) + i))
        elif text == 'IP:':
            if lib.ip_active:
                rect = lib.pygame.draw.rect(lib.SCREEN, lib.WHITE, ((w/2) - (x/2), ((h/z) - (y/2)) + i, x, y), 10)
                lib.SCREEN.blit(font.render(text, True, lib.WHITE), ((w/2) - (x/2) + 10, ((h/z) - (y/2/2)) + i))
                lib.SCREEN.blit(font.render(lib.ip, True, lib.WHITE), ((w/2) - (x/2) + 100, ((h/z) - (y/2/2)) + i))
            else:
                rect = lib.pygame.draw.rect(lib.SCREEN, lib.GREY, ((w/2) - (x/2), ((h/z) - (y/2)) + i, x, y), 10)
                lib.SCREEN.blit(font.render(text, True, lib.GREY), ((w/2) - (x/2) + 10, ((h/z) - (y/2/2)) + i))
                lib.SCREEN.blit(font.render(lib.ip, True, lib.GREY), ((w/2) - (x/2) + 100, ((h/z) - (y/2/2)) + i))
        elif text == 'PORT:':
            if lib.port_active:
                rect = lib.pygame.draw.rect(lib.SCREEN, lib.WHITE, ((w/2) - (x/2), ((h/z) - (y/2)) + i, x, y), 10)
                lib.SCREEN.blit(font.render(text, True, lib.WHITE), ((w/2) - (x/2) + 10, ((h/z) - (y/2/2)) + i))
                lib.SCREEN.blit(font.render(lib.port, True, lib.WHITE), ((w/2) - (x/2) + 100, ((h/z) - (y/2/2)) + i))
            else:
                rect = lib.pygame.draw.rect(lib.SCREEN, lib.GREY, ((w/2) - (x/2), ((h/z) - (y/2)) + i, x, y), 10)
                lib.SCREEN.blit(font.render(text, True, lib.GREY), ((w/2) - (x/2) + 10, ((h/z) - (y/2/2)) + i))
                lib.SCREEN.blit(font.render(lib.port, True, lib.GREY), ((w/2) - (x/2) + 100, ((h/z) - (y/2/2)) + i))
        else:
            rect = lib.pygame.draw.rect(lib.SCREEN, lib.GREY, ((w/2) - (x/2), ((h/z) - (y/2)) + i, x, y), 10)
            lib.SCREEN.blit(font.render(text, True, lib.GREY), ((w/2) - (x/2) + 10, ((h/z) - (y/2/2)) + i))
        b_x = rect.x
        b_y = rect.y
        s_x = x
        s_y = y
        if lib.timeout == 0:
            try: eval(text.lower().replace(':', '') + "_button_click" + "()")
            except: i = i
        i+=y + 25

def write_in():
    if lib.ip_active == True:
        for event in lib.pygame.event.get():
            if event.type == lib.pygame.KEYDOWN:
                if event.key == lib.pygame.K_BACKSPACE: lib.ip = lib.ip[:-1]
                elif event.key == lib.pygame.K_TAB:
                    lib.ip_active = False
                    lib.port_active = True
                elif event.key == lib.pygame.K_RETURN:
                    lib.ip_active = False
                else: lib.ip += event.unicode
    if lib.port_active == True:
        for event in lib.pygame.event.get():
            if event.type == lib.pygame.KEYDOWN:
                if event.key == lib.pygame.K_BACKSPACE: lib.port = lib.port[:-1]
                elif event.key == lib.pygame.K_TAB:
                    lib.ip_active = True
                    lib.port_active = False
                elif event.key == lib.pygame.K_RETURN:
                    lib.port_active = False
                else: lib.port += event.unicode

def settings():
    w, h = lib.pygame.display.get_surface().get_size()
    bg_img = background()
    bg_img = lib.pygame.transform.scale(bg_img, (w, h))
    lib.SCREEN.blit(bg_img, [0, 0])
    if lib.game_state == 2: buttons(w, h)
    elif lib.game_state == 3: ip_buttons(w, h)
    write_in()