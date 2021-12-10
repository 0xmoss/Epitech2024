#!/usr/bin/env python

from math import sqrt

from tools.cumule import cumule

def calcul(period, inputs, result):
    data = []
    a = inputs[-period:]

    for i in range(0, len(a)):
        data.append((a[i] - result) ** 2)
    return (sqrt(cumule(data) / period))

def average(period, inputs):
    size = len(inputs)

    if (size >= period):
        if (period > 0):
            result = cumule(inputs[-period:]) / period
            if (result > 0):
                return ("%.2f" % (calcul(period, inputs, result)))
    return (None)
