#!/usr/bin/env python

from math import sqrt

def r(inputs, period):
    if (len(inputs) > period):
        if (inputs[-(1 + period)] - 1 > 0):
            return (round((inputs[-1] / inputs[-(1 + period)] - 1) * 100))
    return ("nan")