import os
import json

class SETTINGS:
    def __init__(self):
        self.path = "resources/settings.json"

        self.load()

    def load(self):
        if (os.path.isfile(self.path) == True):
            with open(self.path, 'r') as f:
                self.settings = json.load(f)
            f.close()
        else:
            self.settings = None
