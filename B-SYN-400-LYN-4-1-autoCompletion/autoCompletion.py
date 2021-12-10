#!/usr/bin/env python3

import sys

from src.settings import SETTINGS
from src.tools import TOOLS

class AUTOCOMPLETION:
    def __init__(self):
        self.settings = SETTINGS()
        self.tools = TOOLS(self.settings)
        self.status = self.tools.get_status()
        self.path = self.tools.get_path()
        self.content = None
        self.input = []
        self.found = False
        self.launched = True

        if (self.path != None and self.status == 0):
            self.content = self.tools.get_content()
            self.core()

    def display(self):
        components = self.settings.settings["prediction"]

        for component in components:
            print("{}".format(component))

    def get_input(self):
        while (self.launched == True and self.found == False):
            input_data = input().lower()
            if (input_data != None and input_data != "" and input_data != '\n'):
                if (input_data == "abort"):
                    self.launched = False
                else:
                    if (len(input_data) == 1):
                        self.input.append(input_data)
                        if (self.tools.prediction(self.input) == True):
                            self.found = True
                        if (self.tools.input == ""):
                            self.input = []
            else:
                self.tools.errors.unknown_address()
        exit(0)

    def core(self):
        self.data = []
        splitted = None
        result = None
        input_data = None
        launched = True

        try:
            self.tools.parser(self.content)
            for content in self.content:
                result = self.tools.extractor(content)
            self.tools.dump("city", True)
            self.tools.prediction_display_found()
            self.get_input()
        except Exception as e:
            print("{}".format(e), file = sys.stderr)
            exit(84)

if (__name__ == "__main__"):
    AUTOCOMPLETION()

