#!/usr/bin/env python

from math import sqrt

from src.r import r
from src.g import g
from src.s import s
from src.average import average
from src.weirdest import weirdest
from tools.cumule import cumule

class settings:
    period = 0
    _input_ = "_EMPTY_"
    _inputs_ = []
    filters = []
    average = []
    position = []
    tendency = 0

def _average_():
    if (len(settings._inputs_) >= settings.period):
        if (settings.period > 0):
            return (cumule(settings._inputs_[-settings.period:]) / settings.period)
    return (None)

def switch():
    value = 0
    prevalue = 0
    quotien_1 = 0
    quotien_2 = 0

    if (len(settings._inputs_) > settings.period + 1):
        quotien_1 = settings._inputs_[-(1 + settings.period)]
        quotien_2 = settings._inputs_[-(2 + settings.period)]
        if (quotien_1 > 0 and quotien_2 > 0):
            value = round((settings._inputs_[-1] / quotien_1 - 1) * 100)
            prevalue = round((settings._inputs_[-2] / quotien_2 - 1) * 100)
        if (abs(prevalue + value) != (abs(prevalue) + abs(value))):
            settings.tendency += 1
            return ("\t\ta switch occurs")
    return ("")

def resume():
    temp_average = g(settings._inputs_, settings.period)
    temp_evolution = r(settings._inputs_, settings.period)
    temp_deviation = s(settings._inputs_, settings.period)
    temp_switch = switch()

    if (temp_evolution != "nan"):
        print("g={}\t\tr={}%\t\ts={}{}".format(temp_average, temp_evolution, temp_deviation, temp_switch))
    else:
        print("g={}\t\tr={}\t\ts={}{}".format(temp_average, temp_evolution, temp_deviation, temp_switch))

def check(value):
    try:
        float(settings._input_)
        return (True)
    except ValueError:
        print("Input must be floating")
        return (False)

def groundhog(period):
    settings.period = int(period)

    while (settings._input_ != "STOP"):
        settings._input_ = input()
        if (settings._input_ != "STOP"):
            if (check(settings._input_) == True):
                settings._inputs_.append(float(settings._input_))
                resume()
                settings.filters.append(average(settings.period, settings._inputs_))
                settings.average.append(_average_())
                settings.filters = list(filter(None, settings.filters))
                if (len(settings.average) > 0 and len(settings.filters) > 0):
                    a = settings.average[len(settings.average) - 1] - 2 * float(settings.filters[len(settings.filters) - 1])
                    b = settings.average[len(settings.average) - 1] + 2 * float(settings.filters[len(settings.filters) - 1])
                    if ((b - a) > 0):
                        settings.position.append((settings._inputs_[len(settings._inputs_) - 1] - a) / (b - a))
    return (weirdest(settings.period, settings._inputs_, settings.position, settings.tendency))
