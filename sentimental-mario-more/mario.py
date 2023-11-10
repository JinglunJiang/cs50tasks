# TODO
from cs50 import get_int

while True:
    h = get_int("Height: ")
    if h >= 1 and h <= 8:
        break
s = 7
l = 0

while l < h:

    i = 0
    while i < (h - l - 1):
        print(" ", end="")
        i += 1
    j = 0
    while j < (8 - s):
        print("#", end="")
        j += 1
    print("  ", end="")
    k = 0
    while k < (8 - s):
        print("#", end="")
        k += 1
    print()
    s -= 1
    l += 1