import argparse
import socket

from client.src.logs import LOGS
from client.src.core import CORE
from client.src.tools import TOOLS

class CLIENT:
    class SETTINGS:
        host = None
        port = None
        map = None

    def __init__(self):
        self.SETTINGS.host = "127.0.0.1"
        self.SETTINGS.port = 8080
        self.SETTINGS.name = "_EMPTY_"
        self.SETTINGS.help = False
        self.logs = LOGS()
        self.tools = TOOLS()

        if (self.arguments() == True):
            self.core = CORE()
            self.build()
            self.connect()
            self.messages()
            self.close()

    def arguments(self):
        parser = argparse.ArgumentParser(add_help = False)
        settings = parser.add_argument(
            "-help",
            "--help",
            action = "store_true",
            help = "display all arguments",
            default = False,
            required = False
        )
        settings = parser.add_argument(
            "-p",
            "--port",
            action = "store",
            help = "the port number",
            required = False
        )
        settings = parser.add_argument(
            "-h",
            "--host",
            action = "store",
            help = "the name of the machine",
            required = False
        )
        args = parser.parse_args()
        self.SETTINGS.host = args.host
        self.SETTINGS.port = args.port
        self.SETTINGS.help = args.help

        if (self.SETTINGS.help == True or (self.SETTINGS.host == None or self.SETTINGS.port == None)):
            self.usage()
            return (False)
        return (True)

    def usage(self):
        print("USAGE: ./zappy_client -p port -h machine")
        print("       port    is the port number")
        print("       machine is the name of the machine; localhost by default")

    def build(self):
        self.logs.load("launching ZGUI")
        try:
            self.logs.load("building socket...")
            self.socket = socket.socket()
            self.logs.done("socket built")
        except Exception as e:
            self.logs.fail("build failed:\n\t\tError: {}".format(e))

    def connect(self):
        try:
            self.logs.load("connecting GRAPHIC to: {}:{}".format(
                self.SETTINGS.host,
                self.SETTINGS.port
            ))
            self.socket.connect((self.SETTINGS.host, int(self.SETTINGS.port)))
            self.logs.done("connected")
        except Exception as e:
            self.logs.fail("connection failed:\n\t\tError: {}".format(e))
            exit(0)

    def close(self):
        try:
            self.logs.load("closing socket...")
            self.socket.close()
            self.logs.done("socket closed")
            self.logs.done("ZGUI stopped")
        except Exception as e:
            self.logs.fail("closing failed:\n\t\tError: {}".format(e))

    def logger(self):
        try:
            self.logs.load("logging ".format("GRAPHIC"))
            message = "GRAPHIC"
            self.logs.send(message)
            self.socket.send(bytes("{}\n".format(message), 'utf8'))
            print("before")
            self.SETTINGS.map = self.tools.receive_message(self.socket)
            self.SETTINGS.sgt = self.tools.receive_message(self.socket)
            print("after")
            print(self.SETTINGS.map)
            print(self.SETTINGS.sgt)
            if (message != "ko"):
                message = message.split('\n')
                self.logs.done("logged")
            else:
                self.logs.ko("team name not allowed to connect")
        except Exception as e:
            self.logs.fail("logging failed\n\t\tError: {}".format(e))

    def messages(self):
        message = self.socket.recv(1024).decode()[:-1]
        self.logs.recv(message)
        self.logger()
        self.core.launch(self.socket, self.SETTINGS.map, self.SETTINGS.sgt)