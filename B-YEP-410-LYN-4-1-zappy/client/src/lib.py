##
## EPITECH PROJECT, 2021
## client
## File description:
## window
##

import pygame
pygame.init()
import client.src.spritesheet
import random

ip = ""
port = ""
game_state = 0 # 0=menu, 1=game, 2=settings, 3=ip/host
music_state = 0 # 0=reset, 1=menu, 2=game
mute = False
ip_active = False
port_active = False
timeout = 0

IS_RUNNING = True
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
DARKBLUE = (2, 9, 129)
YELLOW = (255, 255, 0)
GREY = (190, 190, 190)
DARKGREY = (169, 169, 169)

last_update = pygame.time.get_ticks()
animation_cooldown = 100
frame = 0
list_square = []
display = True
item_event = []
inventory_event = {"n": 0, "x": 0, "y": 0, "q0": 0, "q1": 0, "q2": 0, "q3": 0, "q4": 0, "q5": 0, "q6": 0}
list_item = []
SCREEN = pygame.display.set_mode((0, 0), pygame.FULLSCREEN, pygame.RESIZABLE)