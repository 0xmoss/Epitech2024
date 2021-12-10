#!/usr/bin/env python3

import json

class CORE:
    def __init__(self):
        self.settings = None
        self.load()
        self.main()

    def load(self):
        with (open("settings.json", 'r') as f):
            self.settings = json.load(f)
        f.close()

    def get_settings(self, line):
        size = len(line)
        cleanned = line.split(' ')

        if (size >= 3):
            if (cleanned[1] == self.settings["commands"]["arguments"]["names"]["player"]):
                self.settings["settings"]["player_name"] = cleanned[2]
            if (cleanned[1] == self.settings["commands"]["arguments"]["names"]["bot"]):
                self.settings["settings"]["bot_name"] = cleanned[2]
            if (cleanned[1] == self.settings["commands"]["arguments"]["bank"]):
                self.settings["settings"]["bank"] = int(cleanned[2])
            if (cleanned[1] == self.settings["commands"]["arguments"]["time"]):
                self.settings["tpermove"] = int(cleanned[2])
            if (cleanned[1] == self.settings["commands"]["arguments"]["candle"]["interval"]):
                self.settings["cinterval"] = int(cleanned[2])
            if (cleanned[1] == self.settings["commands"]["arguments"]["candle"]["format"]):
                self.settings["cformat"] = cleanned[2]
            if (cleanned[1] == self.settings["commands"]["arguments"]["candle"]["total"]):
                self.settings["ctotal"] = int(cleanned[2])
            if (cleanned[1] == self.settings["commands"]["arguments"]["candle"]["given"]):
                self.settings["cgiven"] = int(cleanned[2])
            if (cleanned[1] == self.settings["commands"]["arguments"]["initial"]):
                self.settings["initstack"] = int(cleanned[2])
            if (cleanned[1] == self.settings["commands"]["arguments"]["percent"]):
                self.settings["fees"] = float(cleanned[2])
        self.settings["initstack"]: self.update_stacks(self.settings["initstack"], 0, 0)

    def update_stacks(self, usdt, eth, btc):
        self.settings["stacks"]["USDT"] = float(usdt)
        self.settings["stacks"]["ETH"] = float(eth)
        self.settings["stacks"]["BTC"] = float(btc)

    def update_candles(self, a, b, c):
        pairs = [
            a.split(','),
            b.split(','),
            c.split(',')
        ]

        for i in list(self.settings["candles"].keys()):
            if (i == 'a' or i == 'b' or i == 'c'):
                self.settings["candles"].pop(i)

        # Example: BTC_ETH,1517421600,1.2346420693958102,1.2346420693958102,1.1997680335849261,1.1957232931950688,74.25349262;USDT_ETH,1517421600,69.25788895899439,65.79499451104466,66.96529982030047,67.19844581169241,149808.13961448;USDT_BTC,1517421600,56.09552005050883,53.29074404798339,54.728737319364534,54.6540374182642,268514.58763209


        for pair in pairs:
            self.settings["candles"][pair[0]] = {
                "date" : int(pair[1]),
                "high" : float(pair[2]),
                "low" : float(pair[3]),
                "open" : float(pair[4]),
                "close" : float(pair[5]),
                "volume" : float(pair[6])
            }

        while len(self.settings["BTC_ETH"]) > 10:
            self.settings["BTC_ETH"].pop()
        while len(self.settings["USDT_ETH"]) > 10:
            self.settings["USDT_ETH"].pop()
        while len(self.settings["USDT_BTC"]) > 10:
            self.settings["USDT_BTC"].pop()

    def buy_or_sell(self, data, num, up):
        for i in range(0, num):
            if ((data[i] != self.settings["status"]["buy"] and up == True) or
                (data[i] != self.settings["status"]["sell"] and up == False)):
                return False
        return True

    def average(self, value, money, fee):
        ressources = 0
        data = 0

        for amount in range(money * 100, 0, -10):
            data = amount / 100
            ressources = (value * data) - (fee / 100)
            if (ressources < money):
                return ([ressources, data])
        return ([0, 0])

    def transactions(self, data):
        size = len(data)
        transaction = []

        if (data != 1):
            for i in range(0, size):
                for word in data[i].split():
                    try:
                        float(word)
                        transaction.append(word)
                    except Exception as e:
                        continue
            return (data[transaction.index(max(transaction))])
        return (data[0])

    def launch(self):
        verification = 3
        result = 0
        buy = []

        for pair in self.settings["candles"].keys():
            if (self.settings["candles"][pair]['open'] < self.settings["candles"][pair]['close']):
                self.settings[pair].insert(0, self.settings["status"]["buy"])
            elif (self.settings["candles"][pair]['open'] > self.settings["candles"][pair]['close']):
                self.settings[pair].insert(0, self.settings["status"]["sell"])
            else:
                self.settings[pair].insert(0, self.settings["status"]["pass"])
            if (pair == "BTC_ETH" and self.buy_or_sell(self.settings[pair], verification, True)):
                result = self.average(
                    self.settings["candles"][pair]["high"],
                    int(self.settings["stacks"]["BTC"] / 2),
                    self.settings["fees"]
                )
                if (result[0] != 0):
                    buy.append("buy {} {}".format(pair, result[1]))
            if pair == "USDT_ETH" and self.buy_or_sell(self.settings[pair], verification, True):
                result = self.average(
                    self.settings["candles"][pair]["high"],
                    int(self.settings["stacks"]["USDT"] / 2),
                    self.settings["fees"]
                )
                if (result[0] != 0):
                    buy.append("buy {} {}".format(pair, result[1]))
            if pair == "USDT_BTC" and self.buy_or_sell(self.settings[pair], verification, True):
                result = self.average(
                    self.settings["candles"][pair]["high"],
                    int(self.settings["stacks"]["USDT"] / 2),
                    self.settings["fees"]
                )
                if (result[0] != 0):
                    buy.append("buy {} {}".format(pair, result[1]))
            if pair == "BTC_ETH" and self.buy_or_sell(self.settings[pair], verification, False):
                result = self.average(
                    self.settings["candles"][pair]["high"],
                    int(self.settings["stacks"]["ETH"] / 2),
                    self.settings["fees"]
                )
                if (result[0] != 0):
                    buy.append("sell {} {}".format(pair, result[1]))
            if pair == "USDT_ETH" and self.buy_or_sell(self.settings[pair], verification, False):
                result = self.average(
                    self.settings["candles"][pair]["high"],
                    int(self.settings["stacks"]["ETH"] / 2),
                    self.settings["fees"]
                )
                if (result[0] != 0):
                    buy.append("sell {} {}".format(pair, result[1]))
            if pair == "USDT_BTC" and self.buy_or_sell(self.settings[pair], verification, False):
                result = self.average(
                    self.settings["candles"][pair]["high"],
                    int(self.settings["stacks"]["BTC"] / 2),
                    self.settings["fees"]
                )
                if (result[0] != 0):
                    buy.append("sell {} {}".format(pair, result[1]))
        if (len(buy) != 0):
            print(self.transactions(buy))
        else:
            print("pass")

    def main(self):
        self.update_stacks(
            self.settings["default"]["stacks"]["USDT"],
            self.settings["default"]["stacks"]["ETH"],
            self.settings["default"]["stacks"]["BTC"]
        )
        self.update_candles(
            self.settings["default"]["candles"]["USDT"],
            self.settings["default"]["candles"]["ETH"],
            self.settings["default"]["candles"]["BTC"]
        )
        launched = True

        while (launched == True):
            self.line = input()
            self.cleanned = self.line.split()
            self.stacks = None

            if (self.line.startswith(self.settings["commands"]["settings"])):
                self.get_settings(self.line)
            elif (self.line.startswith(self.settings["commands"]["stacks"])):
                self.stacks = self.cleanned[3]
                self.update_stacks(
                    self.stacks.split(',')[2].split(':')[1],
                    self.stacks.split(',')[1].split(':')[1],
                    self.stacks.split(',')[0].split(':')[1]
                )
            elif (self.line.startswith(self.settings["commands"]["next_candles"])):
                self.stacks = self.cleanned[3]
                self.update_candles(
                    self.stacks.split(';')[0],
                    self.stacks.split(';')[1],
                    self.stacks.split(';')[2]
                )
            elif (self.line.startswith(self.settings["commands"]["action"])):
                self.launch()
            elif (self.line.startswith(self.settings["commands"]["end"])):
                launched = False

if (__name__ == "__main__"):
    CORE()
