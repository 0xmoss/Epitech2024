#!/usr/bin/env python

from math import sqrt

def calcul_position(position):
    result = []

    for i in range(0, len(position)):
        result.append(abs(position[i] - .5))
    return (result)

def calcul_sorted(period, inputs, position):
    data = []
    values = sorted(position)[-5:]

    for i in range(0, len(values)):
        data.append(inputs[position.index(values[i]) + period - 1])
    return (data)

def reverse_list(data):
    result = []
    i = len(data) - 1

    while (i > 0):
        result.append(data[i])
        i -= 1
    return (result)

def weirdest(period, inputs, position, tendency):
    if (len(inputs) >= period):
        print("Global tendency switched %d times" % (tendency))
        if (tendency >= 5):
            data_position = calcul_position(position)
            print("5 weirdest values are {}".format(reverse_list(calcul_sorted(period, inputs, data_position))))
        return (0)
    return (84)