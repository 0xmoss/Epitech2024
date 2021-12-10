##
## EPITECH PROJECT, 2021
## B-YEP-410-LYN-4-1-zappy-
## File description:
## menu_chat
##

from client.src import lib
import client.src.item as item

def inventory():
    w, h = lib.pygame.display.get_surface().get_size()
    s = display_inventory().split(',')
    font = lib.pygame.font.SysFont('Arial', 40)
    lib.pygame.draw.rect(lib.SCREEN, lib.RED, lib.pygame.Rect(w - 375, (h / 2) + 50, float(s[0]), float(s[1])), 4)
    lib.SCREEN.blit(font.render('Inventory of player ', True, lib.WHITE), (w - 375 + 10, (h / 2) + 60))

    nn = str(lib.inventory_event["n"])
    lib.SCREEN.blit(font.render(nn, True, lib.WHITE), (w - 375 + 300, (h / 2) + 60))

    q0 = str(lib.inventory_event["q0"])
    lib.SCREEN.blit(font.render(q0, True, lib.WHITE), (w - 375 + 100, (h / 2) + 80))
    item.pop_item("food", w - 375 + 10, (h / 2) + 80)

    q1 = str(lib.inventory_event["q1"])
    lib.SCREEN.blit(font.render(q1, True, lib.WHITE), (w - 375 + 100, (h / 2) + 110))
    item.pop_item("linemate", w - 375 + 10, (h / 2) + 110)

    q2 = str(lib.inventory_event["q2"])
    lib.SCREEN.blit(font.render(q2, True, lib.WHITE), (w - 375 + 100, (h / 2) + 140))
    item.pop_item("deraumere", w - 375 + 10, (h / 2) + 140)

    q3 = str(lib.inventory_event["q3"])
    lib.SCREEN.blit(font.render(q3, True, lib.WHITE), (w - 375 + 100, (h / 2) + 170))
    item.pop_item("sibur", w - 375 + 10, (h / 2) + 170)

    q4 = str(lib.inventory_event["q4"])
    lib.SCREEN.blit(font.render(q4, True, lib.WHITE), (w - 375 + 100, (h / 2) + 200))
    item.pop_item("mendiane", w - 375 + 10, (h / 2) + 200)

    q5 = str(lib.inventory_event["q5"])
    lib.SCREEN.blit(font.render(q5, True, lib.WHITE), (w - 375 + 100, (h / 2) + 230))
    item.pop_item("phiras", w - 375 + 10, (h / 2) + 230)

    q6 = str(lib.inventory_event["q6"])
    lib.SCREEN.blit(font.render(q6, True, lib.WHITE), (w - 375 + 100, (h / 2) + 250))
    item.pop_item("thystame", w - 375 + 10, (h / 2) + 250)

def display_inventory():
    w, h = lib.pygame.display.get_surface().get_size()
    w_sq =  w - 10
    h_sq = (h / 2) - 100
    return "{},{}".format(w_sq, h_sq)

def chat():
    w, h = lib.pygame.display.get_surface().get_size()
    s = display_chat().split(',')
    font = lib.pygame.font.SysFont('Arial', 40)
    lib.pygame.draw.rect(lib.SCREEN, lib.RED, lib.pygame.Rect(w - 375, 100, float(s[0]), float(s[1])), 4)
    lib.SCREEN.blit(font.render('Chat', True, lib.WHITE), (w - 375 + 10, 110))

def display_chat():
    w, h = lib.pygame.display.get_surface().get_size()
    w_sq =  w - 10
    h_sq = (h / 2) - 100
    return "{},{}".format(w_sq, h_sq)

def display_menu_chat():
    chat()
    inventory()