#!/usr/bin/env python3

import subprocess

class Manager:
    def __init__(self):
        self.commands = {
            "new page" : "dotnet new page --name Pizza --namespace RazorPagesPizza.Pages --output Pages"
        }