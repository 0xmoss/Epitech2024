#!/usr/bin/env python

from math import sqrt

from tools.cumule import cumule

def calcul(average, period, inputs):
    result = []

    for i in inputs[-period:]:
        result.append((i - average) ** 2)
    return (sqrt(cumule(result) / period))

def s(inputs, period):
    if (len(inputs) >= period):
        if (period > 0):
            average = cumule(inputs[-period:])
            return ("%.2f" % calcul(average, period, inputs))
    return ("nan")