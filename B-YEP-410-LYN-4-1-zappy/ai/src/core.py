#!/usr/bin/env python3

import os
import time
from math import sqrt
import socket
import subprocess
import threading

from ai.src.logs import LOGS
from ai.src.commands import COMMANDS

class CORE:
    def __init__(self):
        self.logs = LOGS()
        self.commands = COMMANDS()
        self.search_elevation = False
        self.socket = None

    def handler(self):
        self.elevation = False
        message = None
        finished = False
        count_elevation = 0

        self.logs.load("starting handler")
        while (self.done == False):
            message = self.socket.recv(1024).decode()[:-1]
            if (self.commands.settings.settings["elevation"] in message):
                self.logs.ok("elevation message received: {}".format(message))
                self.search_elevation = True
                count_elevation += 1
        self.logs.done("handler closed")

    def elevate(self, required):
        tmp = "{}".format(required)
        try:
            self.socket.sendall(tmp.encode())
            self.logs.done("elevation sent to all: {}".format(required))
        except Exception as e:
            self.logs.fail("sendall failed\n\t\tError: {}".format(e))

    def move(self, path, item):
        size = len(self.commands.settings.settings["map"][path["direction"]][path["y"]])
        x = 0
        y = 0
        where = 0
        if (size % 2 == 1):
            x = (size - 1) / 2
        else:
            x = (size) / 2

        if (self.commands.settings.settings["debug"] == True):
            self.logs.display("\n\nCURRENT: {} / REQUIRED: {} / MAP: {}\n\n".format(
                self.commands.settings.settings["looking"],
                path["direction"],
                self.commands.settings.settings["map"][path["direction"]]
            ))

        self.logs.load("moving ZAI from: (x:{}, y:{}) to {}".format(x, y, path))
        self.commands.player(path["direction"], self.socket)

        while (y < path["y"]):
            self.commands.player("forward", self.socket)
            y += 1

        if (x != path["x"]):
            if (x < path["x"]):
                self.commands.player("right", self.socket)
                where = 1
            if (x > path["x"]):
                self.commands.player("left", self.socket)
                where = -1
            while (x != path["x"]):
                self.commands.player("forward", self.socket)
                x += where

        self.logs.done("moved ZAI: {}:{} {}".format(x, y, path))
        if (item != "player"):
            if (self.commands.player("take {}".format(item), self.socket) == self.commands.settings.settings["server"]["status"]["ok"]):
                self.logs.ok("took {}".format(item))
            else:
                self.logs.ko("take {} failed".format(item))
        else:
            if (self.commands.player("incantation", self.socket) == self.commands.settings.settings["server"]["status"]["ok"]):
                self.search_elevation = False
                self.commands.settings.settings["status"]["level"] += 1

    def get_players(self, square):
        count = -1

        for floor in square:
            for i in floor:
                if (i == "player"):
                    count += 1

        return (count)

    def get_pow(self):
        data = []

        for i in range(1, 20):
            data.append(pow(i, 2))

        return (data)

    def check_food(self):
        self.commands.player("inventory", self.socket)
        food = self.commands.tools.get_inventory(self.commands.settings.settings["status"]["ressources"], "food")
        limit = self.commands.settings.settings["food_limit"]

        if (food < limit):
            return (False)
        return (True)

    def parse(self):
        floor = 0
        found = False
        self.path = {
            "direction" : "forward",
            "x" : 0,
            "y" : 0
        }

        for direction in self.commands.settings.settings["map"]["direction"]:
            self.path["direction"] = direction
            for square in range(0, len(self.commands.settings.settings["map"][direction])):
                for element in range(0, len(self.to_search)):
                    if (found == False):
                        for i in range(0, len(self.commands.settings.settings["map"][direction][square])):
                            time.sleep(5)
                            search = self.to_search[element]
                            if (self.check_food() == False):
                                search = "food"
                                element = 0
                            elif (self.search_elevation == True):
                                search = "player"
                                element = 0
                            if (self.commands.settings.settings["map"][direction][square][i] == search):
                                self.path["y"] = floor
                                self.path["x"] = i
                                self.move(self.path, search)
                                self.move({"direction" : "backward", "x": 0, "y" : 0}, search)
                                found = True
                        self.path["x"] = 0
                        self.path["y"] = 0
                    found = False
                floor += 1
            floor = 0

    def core(self):
        players = 0
        self.to_search = []
        self.path = {
            "direction" : "forward",
            "x" : 0,
            "y" : 0
        }
        default = [
            [ "forward" ],
            [ "right", "forward" ]
        ]
        status = 0
        pow_value = self.get_pow()
        self.done = False
        floor = 0
        required = 0
        search = None
        ressources = self.commands.settings.settings["status"]["ressources"]
        count_ressources = len(ressources)
        level = self.commands.settings.settings["status"]["level"]

        self.logs.load("launching ai")

        # Searching materials
        while (self.done == False):
            self.commands.player("look around", self.socket)
            self.commands.player("inventory", self.socket)
            if (self.commands.settings.settings["passive"] == False):
                self.parse()
                for i in range(0, count_ressources):
                    if (ressources[i]):
                        if (ressources[i]["quantity"] >= ressources[i]["elevation"][level]):
                            required += 1
                            if (ressources[i]["name"] in self.to_search):
                                self.to_search.remove(ressources[i]["name"])
                        elif (ressources[i]["name"] not in self.to_search):
                            self.to_search.append(ressources[i]["name"])
                if (required == count_ressources):
                    self.logs.ok("required: {} / {}".format(required, count_ressources))
                    self.elevate("{}|{}".format(
                        self.commands.settings.settings["elevation"],
                        self.commands.settings.settings["status"]["players"][self.commands.settings.settings["status"]["level"]]
                    ))
                    self.logs.display("searching people to elevate")
                    self.search_elevation = True
                    self.logs.load("waiting for players")
                    while (players < self.commands.settings.settings["status"]["players"][self.commands.settings.settings["status"]["level"]]):
                        self.commands.player("look around", self.socket)
                        self.commands.player("inventory", self.socket)
                        self.to_search.append("player")
                        self.parse()
                        for direction in self.commands.settings.settings["map"]["direction"]:
                            players = self.get_players(self.commands.settings.settings["map"][direction])
                        self.logs.done("players: {} / {}".format(players, self.commands.settings.settings["status"]["players"][self.commands.settings.settings["status"]["level"]]))
                    if (self.commands.player("incantation", self.socket) == self.commands.settings.settings["server"]["status"]["ok"]):
                        self.logs.ok("incantation succeeded")
                        self.search_elevation = False
                        level += 1
                        self.logs.done("ZAI level updated: {}".format(level))
                        self.commands.player("inventory", self.socket)
                    else:
                        self.logs.ko("incantation failed")
                else:
                    self.logs.ko("required: {} / {}".format(required, count_ressources))
                required = 0
                if (level == len(ressources[0]["elevation"]) - 1):
                    self.done = True
                if (self.path["x"] == 0 and self.path["y"] == 0):
                    self.logs.load("no path found, moving")
                    status = 0
                    for i in range(0, len(default) - 1):
                        for command in default[i]:
                            if (status == 0):
                                if (self.commands.player(command, self.socket) == self.commands.settings.settings["server"]["status"]["ok"]):
                                    self.logs.ok("moved: {}".format(command))
                                    status += 1
                                else:
                                    self.logs.ko("move failed: {}".format(command))
                    status = 0
            else:
                self.logs.load("moving")
                for i in range(0, len(default) - 1):
                    for command in default[i]:
                        if (status == 0):
                            if (self.commands.player(command, self.socket) == self.commands.settings.settings["server"]["status"]["ok"]):
                                self.logs.ok("moved: {}".format(command))
                                status += 1
                            else:
                                self.logs.ko("move failed: {}".format(command))
                status = 0
                result = self.commands.tools.array_cleanner(self.commands.player("look", self.socket))
                players = self.get_players(result[0])
                if (players == 1):
                    self.logs.ok("no player found")
                    players = 1
                else:
                    while (players > 1):
                        self.logs.load("waiting for elevation: {} players".format(players))
                        result = self.commands.tools.array_cleanner(self.commands.player("look", self.socket))
                        players = self.get_players(result[0])
                        time.sleep(self.commands.settings.settings["refresh"])

    def launch(self, socket_client):
        self.socket = socket_client
        self.core()

