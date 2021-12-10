import os
import json

from ai.src.logs import LOGS

class SETTINGS:
    def __init__(self):
        self.path = "ai/ressources/settings.json"
        self.logs = LOGS()
        self.load()

    def load(self):
        if (self.check() == True):
            self.logs.load("loading settings")
            try:
                with open(self.path, 'r') as f:
                    self.settings = json.load(f)
                f.close()
                self.logs.done("settings loaded")
            except Exception as e:
                self.logs.fail("settings load failed\n\t\tError: {}".format(e))

    def check(self):
        self.logs.load("checking settings path")
        if (os.path.isfile(self.path) == True):
            self.logs.ok("settings ressources found")
            return (True)
        self.logs.ko("settings ressources not found")
        return (False)
