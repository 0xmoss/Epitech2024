#!/usr/bin/env python

from math import sqrt

from tools.cumule import cumule

def calcul(period, inputs):
    result = []
    size = len(inputs[-period:])
    a = inputs[-period:]
    b = inputs[-(period + 1):-1]

    for i in range(0, size):
        if ((a[i] - b[i]) < 0):
            result.append(0)
        else:
            result.append(a[i] - b[i])
    return (cumule(result) / period)

def g(inputs, period):
    if (len(inputs) > period):
        if (period > 0):
            return ("%.2f" % calcul(period, inputs))
    return ("nan")