#!/usr/bin/env python3

import argparse
import socket

from ai.src.logs import LOGS
from ai.src.core import CORE

class CLIENT:
    class SETTINGS:
        ip = None
        port = None
        map = None

    def __init__(self):
        self.SETTINGS.ip = "127.0.0.1"
        self.SETTINGS.port = 8080
        self.SETTINGS.help = False
        self.logs = LOGS()

        if (self.arguments() == True):
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
            "--ip",
            action = "store",
            help = "the name of the machine",
            required = False
        )
        args = parser.parse_args()
        self.SETTINGS.ip = args.ip
        self.SETTINGS.port = args.port
        self.SETTINGS.help = args.help

        if (self.SETTINGS.help == True or (self.SETTINGS.ip == None or self.SETTINGS.port == None)):
            self.usage()
            return (False)
        return (True)

    def usage(self):
        print("USAGE: ./zappy_ai -p port -n name -h machine")
        print("       port    is the port number")
        print("       machine is the name of the machine; localhost by default")

    def build(self):
        self.logs.load("launching ZAI")
        try:
            self.logs.load("building socket...")
            self.socket = socket.socket()
            self.logs.done("socket built")
        except Exception as e:
            self.logs.fail("build failed:\n\t\tError: {}".format(e))

    def connect(self):
        try:
            self.logs.load("connecting {} to: {}:{}".format(
                self.SETTINGS.ip,
                self.SETTINGS.port
            ))
            self.socket.connect((self.SETTINGS.ip, int(self.SETTINGS.port)))
            self.logs.done("connected")
        except Exception as e:
            self.logs.fail("connection failed:\n\t\tError: {}".format(e))
            exit(0)

    def close(self):
        try:
            self.logs.load("closing socket...")
            self.socket.close()
            self.logs.done("socket closed")
            self.logs.done("ZAI stopped")
        except Exception as e:
            self.logs.fail("closing failed:\n\t\tError: {}".format(e))

    def messages(self):
        message = self.socket.recv(1024).decode()[:-1]
        self.logs.recv(message)