#!/usr/bin/env python3

import sys
import random

class GDC:
    def __init__(self):
        self.pass_size = 128
        self.data = None

        if (sys.argv[1] == "dump"):
            self.dump()
        else:
            self.revert()

    def password(self):
        all = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
        buffer = ""

        for i in range(0, self.pass_size):
            buffer += all[random.randint(0, len(all) - 1)]

        return (buffer)
    
    def dump(self):
        self.cache = self.password()

        with open("cache", 'w+') as file:
            file.write(self.cache)

        with open("docker-compose.yml", 'r') as file:
            self.data = file.read()

        with open("docker-compose.yml", 'w') as file:
            file.write(self.data.replace("REPLACE_PASSWORD", self.cache))

    def revert(self):
        with open("cache", 'r') as file:
            self.cache = file.read()

        with open("docker-compose.yml", 'r') as file:
            self.data = file.read()

        with open("docker-compose.yml", 'w') as file:
            file.write(self.data.replace(self.cache, "REPLACE_PASSWORD"))

if (__name__ == "__main__"):
    GDC()
