#!/usr/bin/env python

def cumule(array):
    result = 0

    for i in range(0, len(array)):
        result += array[i]
    return (result)