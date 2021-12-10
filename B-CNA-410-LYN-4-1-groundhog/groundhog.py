#!/usr/bin/env python3

import sys

from src.helpme import helpme
from src.engine import groundhog

if (__name__ == "__main__"):
    if (len(sys.argv) == 2):
        if (sys.argv[1] == "-h" or sys.argv[1] == "--help"):
            helpme()
        elif (sys.argv[1].isnumeric() == True):
            exit(groundhog(sys.argv[1]))
        else:
            exit(84)
    else:
        exit(84)