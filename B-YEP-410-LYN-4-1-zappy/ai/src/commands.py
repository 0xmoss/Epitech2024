import socket

from ai.src.logs import LOGS
from ai.src.settings import SETTINGS
from ai.src.tools import TOOLS

class COMMANDS:
    def __init__(self):
        self.logs = LOGS()
        self.settings = SETTINGS()
        self.tools = TOOLS()
        self.direction = 0
        self.number = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

    def send(self, command, socket_client):
        message = None

        try:
            socket_client.send(bytes("{}\n".format(command), 'utf8'))
            if (self.settings.settings["debug"] == True):
                self.logs.send("{}".format(command))
        except Exception as e:
            self.logs.fail("send failed\n\t\tError: {}".format(e))

        try:
            message = self.tools.receive_message(socket_client)
            if (self.settings.settings["debug"] == True):
                self.logs.recv(message)
        except Exception as e:
            self.logs.fail("recv failed\n\t\tError: {}".format(e))

        return (message)

    def path(self, result):
        if (result != None and len(result) > 0):
            if (result[0] == '[' and result[len(result) - 1] == ']'):
                result = self.tools.inventory_cleanner(result)

        return (result)

    def update_inventory(self):
        path = self.settings.settings["Inventory"]
        ressources = self.settings.settings["status"]["ressources"]
        size = len(path)
        count = len(ressources)
        index = 0

        for i in range(0, size - 1):
            for index in range(0, count):
                if (path[i] != "player"):
                    if (ressources[index]["name"] == path[i] and path[i + 1] in self.number):
                        ressources[index]["quantity"] = int(path[i + 1])
        if (self.settings.settings["debug"] == True):
            self.logs.done("Inventory updated: {}".format(ressources))

    def get(self, path, name):
        for i in range(0, len(path)):
            if (path[i]["name"] == name):
                return (path[i]["command"])

        return (None)

    def player(self, command, socket):
        data = self.get(self.settings.settings["commands"], "{}".format(command))
        result = None
        direction = self.settings.settings["map"]["direction"]

        if (data != None):
            for i in range(0, len(data)):
                result = self.send(data[i], socket)
                self.settings.settings[data[i]] = self.path(result)
                if (data[i] == "Right" or data[i] == "Left"):
                    if (data[i] == "Right"):
                        if (self.direction == len(direction) - 1):
                            self.direction = 0
                        else:
                            self.direction += 1
                    else:
                        if (self.direction == 0):
                            self.direction = len(direction) - 1
                        else:
                            self.direction -= 1
                elif (data[i] == "Look"):
                    self.settings.settings["map"][self.settings.settings["map"]["direction"][self.direction]] = self.tools.array_cleanner(result)
                for numbers in self.number:
                    if (numbers in self.settings.settings[data[i]]):
                        self.update_inventory()
                        return (0)
            return (result)
        else:
            self.logs.fail("command not found\n\t\tcommand: {}".format(command))

