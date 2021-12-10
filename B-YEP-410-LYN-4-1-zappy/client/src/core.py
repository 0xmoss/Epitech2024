#!/usr/bin/env python3

import os
import time
from math import sqrt
import socket
import subprocess
from threading import Thread, Lock
from client.src.square import square_size
from client.src.menu_chat import display_menu_chat
from client.src.menu import menu
from client.src.settings import settings
import client.src.lib as lib
from client.src.character import move
from client.src.sound import sound_change
import client.src.window as window
import client.src.spritesheet
import client.src.item as item
from client.src.logs import LOGS
from client.src.tools import TOOLS

message_queue = list()
mutex = Lock()

def message_thread(tools, server_socket):
    global message_queue
    global mutex
    while True:
        message = tools.receive_message(server_socket)
        if message != "":
            mutex.acquire()
            message_queue.append(message)
            mutex.release()

class CORE:
    def __init__(self):
        self.logs = LOGS()
        self.tools = TOOLS()

    def launch(self, socket_client, map, sgt):
        global message_queue
        global mutex
        print("launch")
        self.socket = socket_client
        self.logs.load("launching ZGUI")
        map = map.split()
        stg = sgt.split()
        thread = Thread(target=message_thread, args=(self.tools, self.socket,))
        thread.start()
        while lib.IS_RUNNING:
            lib.SCREEN.fill((0,0,0))
            mutex.acquire()
            while len(message_queue) > 0:
                message = message_queue.pop(0)
                print(message)
                message = message.split()
                if (message[0] == "bct"):
                    lib.item_event.append({"x": int(message[1]), "y": int(message[2]), "q0": int(message[3]), "q1": int(message[4]), "q2": int(message[5]), "q3": int(message[6]), "q4": int(message[7]), "q5": int(message[8]), "q6": int(message[9])})
                if (message[0] == "pin"):
                    lib.inventory_event = {"n": int(message[1]), "x": int(message[2]), "y": int(message[3]), "q0": int(message[4]), "q1": int(message[5]), "q2": int(message[6]), "q3": int(message[7]), "q4": int(message[8]), "q5": int(message[9]), "q6": int(message[10])}
            mutex.release()
            for event in lib.pygame.event.get():
                lib.IS_RUNNING = window.close(event, lib.IS_RUNNING)
            if lib.game_state == 0:
                sound_change(1)
                menu()
            if lib.game_state == 1:
                sound_change(2)
                square_size(int(map[1]), int(map[2]))
                # item.pop("food", 400, 300, 85, 1)
                # item.pop_item("linemate", 400, 300)
                item.parser_dic()
                move(3 * 90, 5 *90)
                display_menu_chat()
            if lib.game_state == 2 or lib.game_state == 3:
                sound_change(1)
                settings()
            lib.pygame.display.update()
            if lib.timeout != 0: lib.timeout += 1
            if lib.timeout > 10: lib.timeout = 0
        self.logs.load("stopping ZGUI")
